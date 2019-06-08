/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeltour <mdeltour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/18 18:46:14 by mdeltour          #+#    #+#             */
/*   Updated: 2019/06/06 12:18:29 by mdeltour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		move_tetri(t_tetris	*newtetris, char letter, char arg)
{
	int		x;
	int		y;

	y = 0;
	while (y < 4)
	{
		x = 0;
		while (x < 4)
		{
			if (newtetris->lines[y][x] == '#' && arg == 'x')
			{
				newtetris->lines[y][x] = '.';
				newtetris->lines[y][x - 1] = '#';
			}
			else if (newtetris->lines[y][x] == '#' && arg == 'y')
			{
				newtetris->lines[y][x] = '.';
				newtetris->lines[y - 1][x] = '#';
			}
			x++;
		}
		y++;
	}
}

t_tetris		*create_tetris(char lines[4][4], char letter)
{
	t_tetris	*newtetris;
	int			x;
	int			y;

	if (!(newtetris = (t_tetris *)malloc(sizeof(t_tetris))))
		return (NULL);
	y = 0;
	while (y < 4)
	{
		ft_strcpy(newtetris->lines[y], lines[y]);
		y++;
	}
	while (newtetris->lines[0][0] != '#' && newtetris->lines[1][0] != '#'
		&& newtetris->lines[2][0] != '#' && newtetris->lines[3][0] != '#')
		move_tetri(newtetris, letter, 'x');
	while (newtetris->lines[0][0] != '#' && newtetris->lines[0][1] != '#'
		&& newtetris->lines[0][2] != '#' && newtetris->lines[0][3] != '#')
		move_tetri(newtetris, letter, 'y');
	y = 0;
	while (y < 4)
	{
		x = 0;
		while (x < 4)
		{
			if (newtetris->lines[y][x] == '#')
				newtetris->lines[y][x] = letter;
			x++;
		}
		y++;
	}
	newtetris->next = NULL;
	return (newtetris);
}

t_flist			*newtetris(t_flist *list, char lines[4][4], char letter)
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

int				is_file_ok(int fd, t_flist *list)
{
	char		*line;
	char		tetris[4][4];
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
			if (ret == 0 || is_valid_str(line) != 4)
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
	t_map		*map;
	int			status;

	if (fd < 0)
		return (ERROR);
	if (!(list = ft_newlist()))
		return (ERROR);
	if (is_file_ok(fd, list) != 0)
		return (ERROR);
	map = NULL;
	if (!(map = init_map(map)))
		return (ERROR);
	ft_putstr("la map apres first init\n");
	print_map(map, map->size);
	status = 2;
	while ((status = ft_solve(list, map)) == ERROR )
	{
		ft_putstr("aggrandis la map\n");
		map->size += 1;
		if (!(map = init_map(map)))
			return (ERROR);
		ft_putstr("reinitialise apres aggrandissement\n");
		print_map(map, map->size);
	}
	ft_putstr("finis\n");
	print_map(map, map->size);
	return (END);
}
