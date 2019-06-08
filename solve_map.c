/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeltour <mdeltour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 15:46:12 by mdeltour          #+#    #+#             */
/*   Updated: 2019/06/08 17:20:43 by mdeltour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	can_place(t_tetris *current, t_map *map)
{
	int x2;
	int y2;
	int	x;
	int	y;

	x = map->x;
	y = map->y;
	ft_putstr("verif\n");
	y2 = 0;
	if (x > map->size || y > map->size)
		return (ERROR);
	while (y2 < map->size && y2 < y + 4)
	{
		x2 = 0;
		while (x2 < map->size && x2 < x + 4)
		{
			if ((y + y2) < map->size && (x + x2) < map->size)
			{
				if (current->lines[y2][x2] >= 'A' && current->lines[y2][x2] <= 'Z' 
					&& map->tab[y + y2][x + y2] >= 'A' && map->tab[y + y2][x + y2] <= 'Z')
					return (ERROR);
			}
			x2++;
		}
		y2++;
	}
	ft_putstr("verif ok\n");
	return (OK);
}

static int	place_tetri(t_tetris *current, t_map *map)
{
	int x2;
	int y2;
	int	x;
	int	y;
	int	count;

	count = 0;
	x = map->x;
	y = map->y;
	ft_putstr("place\n");
	y2 = 0;
	if (x > map->size || y > map->size)
		return (ERROR);
	while (y2 < map->size && y2 < y + 4)
	{
		x2 = 0;
		while (x2 < map->size && x2 < x + 4)
		{
			if ((y + y2) < map->size && (x + x2) < map->size)
			{
				if (current->lines[y2][x2] >= 'A' && current->lines[y2][x2] <= 'Z' 
					&& map->tab[y + y2][x + x2] >= 'A' && map->tab[y + y2][x + x2] <= 'Z')
					return (ERROR);
				if (map->tab[y + y2][x + x2] == '.' && current->lines[y2][x2] >= 'A' && current->lines[y2][x2] <= 'Z')
				{
					map->tab[y + y2][x + x2] = current->lines[y2][x2];
					count++;
					if (count == 4)
						return (OK);
				}
			}
			x2++;
		}
		y2++;
	}
	if (count != 4)
	{
		ft_putstr("pas finis de le placer\n");
		return (ERROR);
	}
	ft_putstr("place ok\n");
	return (OK);
}

static int	try_place_block(t_tetris *current, t_map *map)
{
	int x2;
	int y2;
	int	x;
	int	y;

	x = map->x;
	y = map->y;
	if (can_place(current, map) == ERROR)
	{
		ft_putstr("verifKOO\n");
		return (ERROR);
	}
	if (place_tetri(current, map) == ERROR)
	{
		ft_putstr("placeKOO\n");
		return (ERROR);
	}
	print_map(map, map->size);
	return (OK);
}

int		ft_solve(t_flist *list, t_map *map)
{
	t_tetris *current;
	int	status;

	status = 2;
	current = list->first;
	map->y = 0;
	while (map->y < map->size)
	{
		map->x = 0;
		while (map->x < map->size)
		{
			if (try_place_block(current, map) == OK && map->x < map->size)
			{
				if (current->next == NULL)
					return (END);
				if (current->next != NULL)
				{
					map->x = 0;
					map->y = 0;
					current = current->next;
				}
			}
			map->x++;
		}
		map->y++;
	}
	ft_putstr("on doit aggrandir\n");
	return (ERROR);
}
