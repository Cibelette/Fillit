/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeltour <mdeltour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/18 18:30:18 by mdeltour          #+#    #+#             */
/*   Updated: 2019/06/08 12:23:41 by mdeltour         ###   ########.fr       */
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

int				ft_free_error(void)
{
	return (1);
}

int				print_tetris(t_tetris *map)
{
	int x2;
	int y2;

	y2 = 0;
	while (y2 < 4)
	{
		x2 = 0;
		while (x2 < 4)
		{
			ft_putchar(map->lines[y2][x2]);
			x2++;
		}
		ft_putchar('\n');
		y2++;
	}
	ft_putchar('\n');
	return (OK);
}

void		print_double_char(char **tab, int size)
{
	int		y;

	y = 0;
	while (y < size)
	{
		ft_putstr(tab[y]);
		ft_putchar('\n');
		y++;
	}
}