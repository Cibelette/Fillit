/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeltour <mdeltour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/18 18:30:18 by mdeltour          #+#    #+#             */
/*   Updated: 2019/06/11 15:31:11 by mdeltour         ###   ########.fr       */
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

int			ft_free_error(void)
{
	return (1);
}

char		*ft_strncpy_without(const char *src, int len)
{
	char	*dst;
	int		i;

	i = 0;
	dst = (char *)malloc(sizeof(char) * len);
	while (i < len)
	{
		dst[i] = src[i];
		i++;
	}
	return (dst);
}

void			print_tetris(t_tetris *map)
{
	int 	y2;

	y2 = 0;
	while (y2 < 4)
	{
		ft_putstr(map->line[y2]);
		ft_putchar('\n');
		y2++;
	}
	ft_putchar('\n');
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
