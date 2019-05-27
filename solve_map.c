/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeltour <mdeltour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 15:46:12 by mdeltour          #+#    #+#             */
/*   Updated: 2019/05/27 17:32:01 by mdeltour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int place_next_block(t_tetris *current, int i, int j, t_map *map, char letter)
{
	int block;
	int inext;
	int jnext;
	char **tmp;

	tmp = map->tab;
	block = 0;
	while (block < 3)
	{
		inext = find_block_lat(current, i, j);
		jnext = find_block_long(current, i, j);
		map->x += (inext - i);
		map->y += (jnext - j);
		if (map->x < 0 || map->y < 0 || tmp[map->x][map->y] != '.')
			return (-1);
		tmp[map->x][map->y] = letter;
		i = inext;
		j = jnext;
		block++;
	}
	map->tab = tmp;
	free(tmp);
	map->x = 0;
	map->y = 0;
}

int		place_block(t_tetris *current, t_map *map, char letter, int x, int y)
{
	int i;
	int j;
	int ok;
	
	ft_putstr("blop\n");
	i = find_block_lat(current, 0, 0);
	ft_putstr("blop1\n");
	j = find_block_long(current, 0, 0);
	ft_putstr("blop2\n");

	while (map->tab[x])
	{
		ft_putstr("blop3\n");
		while (map->tab[x][y])
		{
			ft_putstr("blop4\n");
			while (map->tab[x][y] != '.')
			{
				ft_putstr("blop5\n");
				map->y++;
			}
			if (map->tab[x][y] == '.')
			{
				ft_putstr("blop6\n");
				map->x = x;
				map->y = y;
				ok = place_next_block(current, i, j, map, letter);
				if ( ok == 0)
				{
					ft_putstr("blop7\n");
					map->tab[x][y] = letter;
					if ((current = current->next) == NULL)
						ft_putstr("blop8\n");
						return (0);
					ft_putstr("blop9\n");
					return(1);
				}
				else if (ok == -1)
				{
					ft_putstr("blop7bis\n");
					place_block(current, map, letter, x, y + 1);
				}
			}
			ft_putstr("blopen\n");
		}
		ft_putstr("blopennn\n");
		y = 0;
		x++;
	}
	ft_putstr("blopend\n");
	return (-1);
}

int find_block_long(t_tetris *current, int i, int j)
{
	while (current->lines[i])
	{
		while (current->lines[i][j])
		{
			while (current->lines[i][j] == '.')
				j++;
			if (current->lines[i][j] > 'A' && current->lines[i][j] < 'Z')
				return (j);
			j++;
		}
		j = 0;
		i++;
	}
	return (-1);
}

int find_block_lat(t_tetris *current, int i, int j)
{
	ft_putstr("deja\n");
	while (current->lines[i])
	{
		while (current->lines[i][j])
		{
			while (current->lines[i][j] == '.')
			j++;
			if (current->lines[i][j] > 'A' && current->lines[i][j] < 'Z')
				return (i);
			j++;
		}
		j = 0;
		i++;
	}
	ft_putstr("deja5\n");
	return (-1);
}

int		ft_solve(t_flist *list, t_map *map)
{
	t_tetris	*current;
	char		letter;
	int 		i;

	current = list->first;
	letter = 'A';
	i = 1;
	while (i == 1)
	{
		ft_putstr("blob\n");
		i = place_block(current, map, letter, 0, 0);
		ft_putstr("blob1\n");
		current = current->next;
		ft_putstr("blobbb\n");
		letter++;
	}
	if (i == -1)
	{
		ft_putstr("blob2\n");
		init_map(list, map);
		ft_solve(list, map);
	}
}