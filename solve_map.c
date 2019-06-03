/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeltour <mdeltour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 15:46:12 by mdeltour          #+#    #+#             */
/*   Updated: 2019/06/03 20:17:29 by mdeltour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*ft_strnew_with_dot(size_t size)
{
	size_t		i;
	char	*new_line;

	i = 0;
	if (!(new_line = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	while (i < size)
	{
		new_line[i] = '.';
		i++;
	}
	new_line[i] = '\0';
	return (new_line);
}

int place_next_block(t_tetris *current, int i, int j, t_map *map, char letter)
{
	int block;
	int inext;
	int jnext;
	char **tmp;

	tmp = map->tab;
	block = 0;
	ft_putstr("oookk1\n");
	while (block < 3)
	{
		inext = find_block_lat(current, i, j);
		ft_putstr("oookkboucl1\n");
		jnext = find_block_long(current, i, j);
		ft_putstr("oookkboucl2\n");
		map->x += (inext - i);
		map->y += (jnext - j);
		if (map->x < 0 || map->y < 0 || tmp[map->x][map->y] != '.')
		{
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
	
	i = find_block_lat(current, 0, 0);
	ft_putstr("ok1\n");
	j = find_block_long(current, 0, 0);
	ft_putstr("ok2\n");
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
			if (map->tab[x+1] != NULL)
				place_block(current, map, letter, x, y + 1);
			//printf ("x = %d et y = %d\n", x, y);
			//printf("map trop petite");
			return (ERROR);
		}
	}
	return (ERROR);
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
	// rajouter le cas dun tetris vide.
	return (ERROR);
}

int find_block_lat(t_tetris *current, int i, int j)
{
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
		status = place_block(current, map, letter, 0, 0);
		current = current->next;
		letter++;
	}
	if (status == ERROR)
	{
		init_map(map);
		print_map(map, map->size);
		ft_solve(list, map);
		return (ERROR);
	}
	return (END);
}