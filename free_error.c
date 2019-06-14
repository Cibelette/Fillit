/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magnon <magnon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 21:02:06 by magnon            #+#    #+#             */
/*   Updated: 2019/06/14 21:04:37 by magnon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		free_error_all(t_flist *list, t_map *map)
{
	free_tetri_list(list);
	free_map(map);
	return (ERROR);
}

int		free_error_list(t_flist *list)
{
	free_tetri_list(list);
	return (ERROR);
}

int		error_list_ret(t_flist *list)
{
	free(list);
	return (ERROR);
}

int		free_ret(char *line, int ret)
{
	if (ret != 0)
	{
		if ((line && line[0] != '\0') || (line && line[0] == '\000'))
			free(line);
	}
	return (1);
}

int		free_ret2(char *line, int j)
{
	if (line && line[0])
		free(line);
	return (j);
}
