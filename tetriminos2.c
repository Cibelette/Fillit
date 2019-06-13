/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetriminos2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magnon <magnon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 17:05:56 by mdeltour          #+#    #+#             */
/*   Updated: 2019/06/13 15:44:08 by magnon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		is_tetris_ok(t_flist list)
{
	t_tetris	*curr;
	int			connexion;
	char		letter;

	letter = 'A';
	curr = list.first;
	while (curr != NULL)
	{
		connexion = count_connexion(curr, letter);
		if (!(connexion == 6 || connexion == 8))
			return (1);
		curr = curr->next;
		letter++;
	}
	return (0);
}
