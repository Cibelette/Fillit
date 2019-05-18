/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeltour <mdeltour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/18 18:46:14 by mdeltour          #+#    #+#             */
/*   Updated: 2019/05/18 19:25:11 by mdeltour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tetris		*create_tetris(char lines[4][5])
{
	t_tetris	*newtetris;
	int			j;

	j = 0;
	if (!(newtetris = (t_tetris *)malloc(sizeof(t_tetris))))
		return (NULL);
	while (j < 4)
	{
		ft_strcpy(newtetris->lines[j], lines[j]);
		j++;
	}
	newtetris->next = NULL;
	return (newtetris);
}

t_flist			*newtetris(t_flist *list, char lines[4][5])
{
	t_tetris	*newtetris;

	if (list != NULL)
	{
		if (!(newtetris = create_tetris(lines)))
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

int				is_file_ok(int fd)
{
	t_flist		*list;
	char		*line;
	char		tetris[4][5];
	int			j;
	int			ret;

	j = 0;
	ret = 2;
	list = ft_newlist();
	while (ret > 0)
	{
		while (j < 4 && ret > 0)
		{
			ret = get_next_line(fd, &line);
			if (is_valid_str(line) != 4 || line[4] != '\0')
				return (ft_free_error());
			ft_strcpy(tetris[j], line);
			j++;
		}
		list = newtetris(list, tetris);
		ret = get_next_line(fd, &line);
		if (ret == 0)
			return (0);
		if (line[0] != '\0')
			return (ft_free_error());
		j = 0;
	}
	return (0);
}

int				ft_fillit(int fd)
{
	if (fd < 0)
		return (1);
	if (is_file_ok(fd) != 0)
		return (1);
	return (0);
}
