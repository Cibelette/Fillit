/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeltour <mdeltour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/26 15:47:54 by mdeltour          #+#    #+#             */
/*   Updated: 2019/05/27 15:32:04 by mdeltour         ###   ########.fr       */
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

void	print_map(char **map, int map_size)
{
	int i;
	int j;

	i = 0;
	while (i < map_size)
	{
		j = 0;
		while (j < map_size)
		{
			ft_putchar(map[i][j]);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}

int		size_of_map(int nb_piece)
{
	int	result;

	result  = 2;
	while (result * result < nb_piece * 4)
		result++;
	return (result);
}

char	**extend_tab(char **tab, size_t new_size)
{
	char	**newtab;
	size_t		i;

	if (tab)
		free_map(tab, new_size - 1);
	if (!(newtab = (char **)malloc(sizeof(char *) * (new_size + 5))))
		return (NULL);
	i = 0;
	while (i < new_size + 4)
	{
		newtab[i] = ft_strnew_with_dot(new_size);
		i++;
	}
	newtab[i] = 0;
	return (newtab);
}


t_map	*init_map(t_flist *list, t_map *map)
{
	if (!(map = (t_map *)malloc(sizeof(t_map))))
		return (NULL);
	map->size = size_of_map(list->tetri);
	printf("%zu\n%zu\n", list->tetri, map->size);
	map->tab = extend_tab(NULL, map->size);
	return (map);
}
