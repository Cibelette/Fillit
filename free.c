/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magnon <magnon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 19:21:03 by mdeltour          #+#    #+#             */
/*   Updated: 2019/06/13 19:47:41 by magnon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		free_error_all(t_flist *list, t_map *map)
{
	free_tetri(list);
	free_map(map);
	return (ERROR);
}


int		free_error_list(t_flist *list)
{
	free_tetri(list);
	return (ERROR);
}

void	free_tetri(t_flist *list)
{
	t_tetris *tetri;

	tetri = list->last;
	while(tetri->prev != NULL)
	{
		if(tetri->next != NULL)
			free(tetri->next);
		tetri = tetri->prev;
	}
	free(tetri->next);
	free(tetri);
	free(list);

}

void	free_all(t_flist *list, t_map *map)
{
	free_tetri(list);
	free_map(map);
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
