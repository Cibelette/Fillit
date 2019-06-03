/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cibyl <cibyl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/18 18:30:18 by mdeltour          #+#    #+#             */
/*   Updated: 2019/06/01 12:28:31 by cibyl            ###   ########.fr       */
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


