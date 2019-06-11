/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeltour <mdeltour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 15:46:12 by mdeltour          #+#    #+#             */
/*   Updated: 2019/06/11 15:39:20 by mdeltour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

static int	can_place(t_tetris *curr, t_map *map, int x, int y)
{
	int		i;
	int		j;
	int		count;

	count = 0;
	j = 0;
	while (j < map->size && j < y + 4)
	{
		i = 0;
		while (i < map->size && i < x + 4 && (y + j) < map->size
			&& (x + i) < map->size)
		{
			if (map->tab[y + j][x + i] >= 'A' && map->tab[y + j][x + i] <= 'Z'
					&& curr->line[j][i] >= 'A' && curr->line[j][i] <= 'Z')
				return (ERROR);
			if (map->tab[y + j][x + i] == '.' && curr->line[j][i] >= 'A'
					&& curr->line[j][i] <= 'Z')
				count++;
			i++;
		}
		j++;
	}
	return (count != 4 ? ERROR : OK);
}

static int	place_tetri(t_tetris *curr, t_map *map, int x, int y)
{
	int		i;
	int		j;
	int		count;

	count = 0;
	j = 0;
	while (j < map->size && j < y + 4)
	{
		i = 0;
		while (i < map->size && i < x + 4 && (y + j) < map->size
			&& (x + i) < map->size)
		{
			if (map->tab[y + j][x + i] >= 'A' && map->tab[y + j][x + i] <= 'Z'
					&& curr->line[j][i] >= 'A' && curr->line[j][i] <= 'Z')
				return (ERROR);
			if (map->tab[y + j][x + i] == '.' && curr->line[j][i] >= 'A'
					&& curr->line[j][i] <= 'Z')
			{
				map->tab[y + j][x + i] = curr->line[j][i];
				count++;
				if (count == 4)
					return (OK);
			}
			i++;
		}
		j++;
	}
	return (count != 4 ? ERROR : OK);
}

static int	try_place_block(t_tetris *curr, t_map *map, int x, int y)
{
	if (x > map->size || y > map->size)
		return (ERROR);
	if (can_place(curr, map, x, y) == ERROR)
		return (ERROR);
	if (place_tetri(curr, map, x, y) == ERROR)
		return (ERROR);
	return (OK);
}

int			ft_solve(t_tetris *curr, t_map *map)
{
	int		x;
	int		y;
	char	**tmp;

	tmp = (char **)malloc(sizeof(char *) * (map->size + 1));
	tmp[map->size] = NULL;
	y = 0;
	while (y < map->size)
	{
		x = 0;
		while (x < map->size)
		{
			save_map(tmp, map->tab, map->size);
			if (try_place_block(curr, map, x, y) == OK && x < map->size)
			{
				if (curr->next == NULL || ft_solve(curr->next, map) == OK)
					return (OK);
				save_map(map->tab, tmp, map->size);
			}
			x++;
		}
		y++;
	}
	return (ERROR);
}
