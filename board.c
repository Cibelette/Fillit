/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeltour <mdeltour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/26 15:47:54 by mdeltour          #+#    #+#             */
/*   Updated: 2019/06/03 19:53:13 by mdeltour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	free_map(char **map, int map_size)
{
	int		i;

	i = 0;
	while (i < map_size + 4)
	{
		free(map[i]);
		map[i] = NULL;
		i++;
	}
	free(map[i]);
	map[i] = NULL;
	free(map);
	map = NULL;
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

t_map	*extend_tab(t_map *map, size_t new_size)
{
	size_t		i;

	if (!(map->tab = (char **)malloc(sizeof(char *) * new_size)))
		return (NULL);
	i = 0;
	while (i < new_size)
	{
		map->tab[i] = ft_strnew_with_dot(new_size);
		i++;
	}
	ft_putstr("i = \n");
	ft_putnbr(i);
	ft_putchar('\n');
	ft_putstr("la map dans extend 1\n");
	print_map(map, map->size);
	//map->tab[i] = 0;
	ft_putstr("la map dans extend 2\n");
	print_map(map, map->size);
	return (map);
}

t_map	*init_map(t_map *map)
{
	int		x;
	int		y;
    size_t  size;

    size = 2;
    if (map)
    {
        size = map->size + 1;
        free(map);
    }
	if (!(map = (t_map *)malloc(sizeof(t_map))))
		return (NULL);
	map->x = 0;
	map->y = 0;	
	map->size = size;
	map = extend_tab(map, map->size);
	ft_putstr("la map dans init apres extend\n");
	print_map(map, map->size);
	return (map);
}
