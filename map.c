/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeltour <mdeltour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/26 15:47:54 by mdeltour          #+#    #+#             */
/*   Updated: 2019/06/14 14:08:55 by mdeltour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_map	*restaure_map(t_map *map, int size, t_tetris *curr)
{
	int		y;
	int		x;
	char	letter;

	letter = find_letter(curr);
	y = 0;
	while (y < size)
	{
		x = 0;
		while (x < size)
		{
			if (map->tab[y][x] == letter)
				map->tab[y][x] = '.';
			x++;
		}
		y++;
	}
	return (map);
}

void	print_map(t_map *map, int map_size)
{
	int i;
	int j;

	i = 0;
	while (i < map_size)
	{
		j = 0;
		while (j < map_size)
		{
			ft_putchar(map->tab[i][j]);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}

t_map	*extend_tab(t_map *map, int new_size)
{
	int	i;

	if (!(map->tab = (char **)malloc(sizeof(char *) * (new_size + 1))))
		return (NULL);
	i = 0;
	while (i < new_size)
	{
		if ((map->tab[i] = ft_strnew_with_dot(new_size)) == NULL)
			free_map(map);
		i++;
	}
	map->tab[i] = NULL;
	return (map);
}

t_map	*init_map(t_map *map, t_flist *list)
{
	int		size;
	int		nb;

	nb = list->tetri;
	size = 2;
	while ((size = ft_sqrt(nb * 4)) == 0)
		nb++;
	if (map)
	{
		size = map->size;
		free_map(map);
	}
	if (!(map = (t_map *)malloc(sizeof(t_map))))
		return (NULL);
	map->size = size;
	map = extend_tab(map, map->size);
	return (map);
}

int		place2(int l[2], int l2[2], t_tetris *curr, t_map *map)
{
	if (is_upper_case(map->tab[l[1] + l2[1]][l[0] + l2[0]]) == OK
		&& is_upper_case(curr->line[l2[1]][l2[0]]) == OK)
		return (ERROR);
	if (map->tab[l[1] + l2[1]][l[0] + l2[0]] == '.'
		&& is_upper_case(curr->line[l2[1]][l2[0]]) == OK)
	{
		map->tab[l[1] + l2[1]][l[0] + l2[0]] = curr->line[l2[1]][l2[0]];
		return (OK);
	}
	return (END);
}
