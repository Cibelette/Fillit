/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeltour <mdeltour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/18 18:30:18 by mdeltour          #+#    #+#             */
/*   Updated: 2019/06/04 10:36:56 by mdeltour         ###   ########.fr       */
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
