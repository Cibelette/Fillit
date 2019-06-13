/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   Bloc[1]: cibyl <cibyl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 15:46:12 by mdeltour          #+#    #+#             */
/*   Updated: 2019/06/13 14:56:33 by cibyl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	can_place(t_tetris *curr, t_map *map, int loc[2])
{

	int		loc2[2];
	int		count;

	count = 0;
	loc2[1] = 0;
	while (loc2[1] < map->size && loc2[1] < loc[1] + 4)
	{
		loc2[0] = 0;
		while (loc2[0] < map->size && loc2[0] < loc[0] + 4 && (loc[1] + loc2[1]) < map->size
			&& (loc[0] + loc2[0]) < map->size)
		{
			if (map->tab[loc[1] + loc2[1]][loc[0] + loc2[0]] >= 'A' && map->tab[loc[1] + loc2[1]][loc[0] + loc2[0]] <= 'Z'
					&& curr->line[loc2[1]][loc2[0]] >= 'A' && curr->line[loc2[1]][loc2[0]] <= 'Z')
				return (ERROR);
			if (map->tab[loc[1] + loc2[1]][loc[0] + loc2[0]] == '.' && curr->line[loc2[1]][loc2[0]] >= 'A'
					&& curr->line[loc2[1]][loc2[0]] <= 'Z')
				count++;
			loc2[0]++;
		}
		loc2[1]++;
	}
	return (count != 4 ? ERROR : OK);
}

static int	place_tetri(t_tetris *curr, t_map *map, int loc[2])
{
	int		loc2[2];
	int		count;

	count = 0;
	loc2[1] = 0;
	while (loc2[1] < map->size && loc2[1] < loc[1] + 4)
	{
		loc2[0] = 0;
		while (loc2[0] < map->size && loc2[0] < loc[0] + 4 && (loc[1] + loc2[1]) < map->size
			&& (loc[0] + loc2[0]) < map->size)
		{
			if (map->tab[loc[1] + loc2[1]][loc[0] + loc2[0]] >= 'A' && map->tab[loc[1] + loc2[1]][loc[0] + loc2[0]] <= 'Z'
					&& curr->line[loc2[1]][loc2[0]] >= 'A' && curr->line[loc2[1]][loc2[0]] <= 'Z')
				return (ERROR);
			if (map->tab[loc[1] + loc2[1]][loc[0] + loc2[0]] == '.' && curr->line[loc2[1]][loc2[0]] >= 'A'
					&& curr->line[loc2[1]][loc2[0]] <= 'Z')
			{
				map->tab[loc[1] + loc2[1]][loc[0] + loc2[0]] = curr->line[loc2[1]][loc2[0]];
				count++;
				if (count == 4)
					return (OK);
			}
			loc2[0]++;
		}
		loc2[1]++;
	}
	return (count != 4 ? ERROR : OK);
}

static int	try_place_block(t_tetris *curr, t_map *map, int loc[2])
{
	if (loc[0] > map->size || loc[1] > map->size)
		return (ERROR);
	if (can_place(curr, map, loc) == ERROR)
		return (ERROR);
	if (place_tetri(curr, map, loc) == ERROR)
		return (ERROR);
	return (OK);
}

int			ft_solve(t_tetris *curr, t_map *map)
{
	int		loc[2];
	char	**tmp;

	if (!(tmp = (char **)malloc(sizeof(char *) * (map->size + 1))))
		return (ERROR);
	tmp[map->size] = NULL;
	loc[1] = 0;
	while (loc[1] < map->size)
	{
		loc[0] = 0;
		while (loc[0] < map->size)
		{
			if (save_map(tmp, map->tab, map->size) == ERROR)
				free(tmp);
			if (try_place_block(curr, map, loc) == OK && loc[0] < map->size)
			{
				if (curr->next == NULL || ft_solve(curr->next, map) == OK)
				{
					free(tmp);
					return (OK);
				}
				if (save_map(map->tab, tmp, map->size) == ERROR)
					return (ERROR);
			}
			loc[0]++;
		}
		loc[1]++;
	}
	free(tmp);
	return (ERROR);
}
