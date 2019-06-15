/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magnon <magnon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/18 18:30:18 by mdeltour          #+#    #+#             */
/*   Updated: 2019/06/14 20:48:41 by magnon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_flist		*ft_newlist(void)
{
	t_flist *list;

	if (!(list = (t_flist *)malloc(sizeof(t_flist))))
		return (NULL);
	list->tetri = 0;
	list->first = NULL;
	list->last = NULL;
	return (list);
}

char		find_letter(t_tetris *curr)
{
	int	x;
	int	y;

	y = 0;
	while (y < 4)
	{
		x = 0;
		while (x < 4)
		{
			if (curr->line[y][x] >= 'A' && curr->line[y][x] <= 'Z')
				return (curr->line[y][x]);
			x++;
		}
		y++;
	}
	return (0);
}

char		*ft_strnew_with_dot(int size)
{
	int		i;
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

int			is_upper_case(char c)
{
	if (c >= 'A' && c <= 'Z')
		return (OK);
	return (ERROR);
}

void		cpy_del(char tetris[5][5], char *line, int j)
{
	ft_strcpy(tetris[j], line);
	ft_memdel((void **)&line);
}
