/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magnon <magnon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 15:20:01 by magnon            #+#    #+#             */
/*   Updated: 2019/06/15 12:03:26 by mdeltour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	place2(int l[2], int l2[2], t_tetris *curr, t_map *map)
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

static int	can_place(t_tetris *curr, t_map *map, int l[2], int sz)
{
	int		l2[2];
	int		count;

	count = 0;
	l2[1] = 0;
	while (l2[1] < sz && l2[1] < l[1] + 4)
	{
		l2[0] = 0;
		while (l2[0] < sz && l2[0] < l[0] + 4 && (l[1] + l2[1]) < sz
			&& (l[0] + l2[0]) < sz)
		{
			if (is_upper_case(map->tab[l[1] + l2[1]][l[0] + l2[0]]) == OK
				&& is_upper_case(curr->line[l2[1]][l2[0]]) == OK)
				return (ERROR);
			if (map->tab[l[1] + l2[1]][l[0] + l2[0]] == '.'
				&& is_upper_case(curr->line[l2[1]][l2[0]]) == OK)
				count++;
			l2[0]++;
		}
		l2[1]++;
	}
	return (count != 4 ? ERROR : OK);
}

static int	place_tetri(t_tetris *curr, t_map *map, int l[2], int status)
{
	int		l2[2];
	int		count;

	count = 0;
	l2[1] = 0;
	while (l2[1] < map->size && l2[1] < l[1] + 4)
	{
		l2[0] = 0;
		while (l2[0] < map->size && l2[0] < l[0] + 4
			&& (l[1] + l2[1]) < map->size && (l[0] + l2[0]) < map->size)
		{
			if ((status = place2(l, l2, curr, map)) == ERROR)
				return (ERROR);
			if (status == OK)
			{
				count++;
				if (count == 4)
					return (OK);
			}
			l2[0]++;
		}
		l2[1]++;
	}
	return (count != 4 ? ERROR : OK);
}

static int	try_place_block(t_tetris *curr, t_map *map, int l[2])
{
	if (l[0] > map->size || l[1] > map->size)
		return (ERROR);
	if (can_place(curr, map, l, map->size) == ERROR)
		return (ERROR);
	if (place_tetri(curr, map, l, 2) == ERROR)
		return (ERROR);
	return (OK);
}

int			ft_solve(t_tetris *curr, t_map *map)
{
	int		l[2];

	l[1] = 0;
	while (l[1] < map->size)
	{
		l[0] = 0;
		while (l[0] < map->size)
		{
			if (try_place_block(curr, map, l) == OK && l[0] < map->size)
			{
				if (curr->next == NULL || ft_solve(curr->next, map) == OK)
				{
					return (OK);
				}
				map = restaure_map(map, map->size, curr);
			}
			l[0]++;
		}
		l[1]++;
	}
	return (ERROR);
}
