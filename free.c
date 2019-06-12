/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeltour <mdeltour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 19:21:03 by mdeltour          #+#    #+#             */
/*   Updated: 2019/06/11 19:27:34 by mdeltour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_free_all(t_flist *list, t_map *map)
{
	free_map(map);
	free(list);
}

void    free_map(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->size)
	{
		free(map->tab[i]);
		i++;
	}
	free(map->tab);
	map->tab = NULL;
	free(map);
	map = NULL;
}
