/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeltour <mdeltour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 15:46:12 by mdeltour          #+#    #+#             */
/*   Updated: 2019/06/04 16:36:26 by mdeltour         ###   ########.fr       */
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
	ft_putstr("rentre dans place next block\n");
	while (block < 3)
	{
		inext = find_block_lat(current, i, j);
		ft_putstr("\ninext = ");
		ft_putnbr(inext);
		jnext = find_block_long(current, i, j);
		ft_putstr("\njnext = ");
		ft_putnbr(jnext);
		map->x += (inext - i);
		map->y += (jnext - j);
		if (map->x < 0 || map->y < 0 || tmp[map->x][map->y] != '.')
		{
			ft_putstr("attention error place next block\n");
			return (ERROR);
		}
		tmp[map->x][map->y] = letter;
		i = inext;
		j = jnext;
		block++;
	}
	map->tab = tmp;
	free(tmp);
	map->x = 0;
	map->y = 0;
	return (OK);
}

int		place_block(t_tetris *current, t_map *map, char letter, int x, int y)
{
	int i;
	int j;
	int status;
	
	if ((i = find_block_lat(current, 0, 0)) == ERROR)
		return (ERROR);
	ft_putstr("i = ");
	ft_putnbr(i);
	j = find_block_long(current, i, 0);
	ft_putstr("j = ");
	ft_putnbr(j);
/*	while (x < 4 && map->tab[x][y] == '.')
	{
		while (y < 4 && map->tab[x][y] == '.')
			y++;
		if (map->tab[x][y] > 'A' && map->tab[x][y] < 'Z')
			break;
		x++;
		y = 0;
	}
	if (map->tab[x][y] > 'A' && map->tab[x][y] < 'Z')
	{
		map->x = x + i;
		map->y = y + i;
		current->lines = tab[x][y];
	}

*/

	while (map->tab[x] && map->tab[x][y] != '.')
	{
		printf("boucle1 x = %d y = %d str = %s\n", x, y, map->tab[0]);
		print_map(map, map->size);
		while (map->tab[x][y] && map->tab[x][y] != '.')
		{
			printf("boucle2\n");
			y++;
		}
		y = 0;
		x++;
	}
	
	if (map->tab[x][y] == '.')
	{
		ft_putstr("maptabde.\n");
		map->x = x;
		map->y = y;
		ft_putstr("avant placenextblock\n");
		print_map(map, map->size);
		status = place_next_block(current, i, j, map, letter);
		ft_putstr("apresplacenextblock\n");
		print_map(map, map->size);
		if ( status == OK)
		{
			map->tab[x][y] = letter;
			if ((current = current->next) == NULL)
				return (END);
			return(OK);
		}
		else if (status == ERROR)
		{
			ft_putstr("error dans place block on essaye de replacer avec tab x+1 \n");
			if (map->tab[x + 1] != NULL)
				place_block(current, map, letter, x, y + 1);
			//printf ("x = %d et y = %d\n", x, y);
			ft_putstr("map trop petite\n");
			return (ERROR);
		}
	}
	return (ERROR);
}

int find_block_long(t_tetris *current, int i, int j)
{
	while (current->lines[i])
	{
		while (i < 4 && current->lines[i][j] == '.')
		{
			while (j < 4 && current->lines[i][j] == '.')
				j++;
			if (current->lines[i][j] >= 'A' && current->lines[i][j] <= 'Z')
				return (j);
			i++;
			j = 0;
		}
		if (current->lines[i][j] >= 'A' && current->lines[i][j] <= 'Z')
			return (j);
	}
	return (ERROR);
}


int find_block_lat(t_tetris *current, int i, int j)
{
	while (current->lines[i])
	{
		while (i < 4 && current->lines[i][j] == '.')
		{
			while (j < 4 && current->lines[i][j] == '.')
				j++;
			if (current->lines[i][j] >= 'A' && current->lines[i][j] <= 'Z')
				return (i);
			i++;
			j = 0;
		}
		if (current->lines[i][j] >= 'A' && current->lines[i][j] <= 'Z')
			return (i);
	}
	return (ERROR);
}

int		ft_solve(t_flist *list, t_map *map)
{
	t_tetris	*current;
	char		letter;
	int 		status;

	current = list->first;
	letter = 'A';
	status = OK;
	while (status == OK)
	{
		ft_putstr("statu OK ft_solve placons !\n");
		status = place_block(current, map, letter, 0, 0);
		current = current->next;
		letter++;
	}
	if (status == ERROR)
	{
		ft_putstr("status error ft_solve on reviens dans principale \n");
		print_map(map, map->size);
		return (ERROR);
	}
	return (END);
}