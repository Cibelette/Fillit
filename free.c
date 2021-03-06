/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeltour <mdeltour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/15 13:20:38 by mdeltour          #+#    #+#             */
/*   Updated: 2019/06/16 15:15:51 by mdeltour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		free_tetri_list(t_flist *list)
{
	t_tetris *tetri;

	if (list)
	{
		if (list->last)
		{
			tetri = list->last;
			while (tetri->prev != NULL)
			{
				if (tetri->next != NULL)
					free(tetri->next);
				tetri = tetri->prev;
			}
			free(tetri->next);
			free(tetri);
		}
		free(list);
	}
}

void		free_all(t_flist *list, t_map *map)
{
	free_tetri_list(list);
	free_map(map);
}

void		free_map(t_map *map)
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

t_tetris	*free_tetri(t_tetris *tetri)
{
	free(tetri);
	return (NULL);
}
