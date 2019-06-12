/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeltour <mdeltour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/26 15:47:54 by mdeltour          #+#    #+#             */
/*   Updated: 2019/06/11 19:26:33 by mdeltour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		save_map(char **dest, char **srcs, int size)
{
	int	y;

	y = 0;
	/*if (dest != NULL)
	{
		free(dest);
		dest = NULL;
		if (!(dest = (char **)malloc(sizeof(char *) * (size + 1))))
			return (ERROR);
	}
	*/
	while (y < size)
	{
		if (!(dest[y] = ft_strncpy_without(srcs[y], size)))
			return (ERROR);
		y++;
	}
	return (OK);
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
	map->x = 0;
	map->y = 0;
	map->size = size;
	map = extend_tab(map, map->size);
	return (map);
}
