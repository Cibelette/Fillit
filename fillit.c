/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeltour <mdeltour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/18 18:46:14 by mdeltour          #+#    #+#             */
/*   Updated: 2019/05/27 15:19:02 by mdeltour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tetris		*create_tetris(char lines[4][5], char letter)
{
	t_tetris	*newtetris;
	int			j;
	int			i;

	j = 0;
	if (!(newtetris = (t_tetris *)malloc(sizeof(t_tetris))))
		return (NULL);
	while (j < 4)
	{
		i = 0;
		ft_strcpy(newtetris->lines[j], lines[j]);
		while (newtetris->lines[j][i])
		{
			if (newtetris->lines[j][i] == '#')
				newtetris->lines[j][i] = letter;
			i++;
		}
		ft_putstr(newtetris->lines[j]);
		ft_putchar('\n');
		j++;
	}
	newtetris->next = NULL;
	return (newtetris);
}

t_flist			*newtetris(t_flist *list, char lines[4][5], char letter)
{
	t_tetris	*newtetris;

	if (list != NULL)
	{
		if (!(newtetris = create_tetris(lines, letter)))
			return (NULL);
		if (list->last == NULL)
		{
			newtetris->prev = NULL;
			list->first = newtetris;
			list->last = newtetris;
		}
		else
		{
			list->last->next = newtetris;
			newtetris->prev = list->last;
			list->last = newtetris;
		}
		list->tetri++;
	}
	return (list);
}

int				ft_free_error(void)
{
	return (1);
}

int				is_file_ok(int fd, t_flist *list)
{
	char		*line;
	char		tetris[4][5];
	int			j;
	int			ret;
	char		letter;

	letter = 'A';
	j = 0;
	ret = 2;
	while (ret > 0)
	{
		while (j < 4 && ret > 0)
		{
			ret = get_next_line(fd, &line);
			if (ret == 0 || is_valid_str(line) != 4 || line[4] != '\0')
				return (ft_free_error());
			ft_strcpy(tetris[j], line);
			j++;
		}
		if (j != 4)
			return (1);
		list = newtetris(list, tetris, letter);
		letter++;
		ret = get_next_line(fd, &line);
		if (ret == 0)
		{
			if (is_tetris_ok(*list) != 0)
				return (ft_free_error());
			return (0);
		}
		if (line[0] != '\0' || ret == -1)
			return (ft_free_error());
		j = 0;
	}
	return (0);
}

int				ft_fillit(int fd)
{
	t_flist		*list;
	t_board		*board;

	if (fd < 0)
		return (1);
	if (!(list = ft_newlist()))
		return (1);
	if (is_file_ok(fd, list) != 0)
		return (1);
	board = NULL;
	if (!(board = init_board(list, board)))
		return (1);
	while (ft_solve(list, board) == 1)
		{
			board->size += 1;
			board->tab = extend_tab(board->tab, board->size);
		}
	print_board(board->tab, board->size);
	return (0);
}
