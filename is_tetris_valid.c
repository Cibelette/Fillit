/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_tetris_valid.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clagier <clagier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 11:51:57 by clagier           #+#    #+#             */
/*   Updated: 2019/05/20 13:20:18 by clagier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int check_connexion(char lines[4][5], int i, int j)
{
	int connexions;

	connexions = 0;
	if (lines[i][j-1] == '#')
		connexions++;
	if (lines[i][j+1] == '#')
		connexions++;
	if (lines[i-1][j] == '#')
		connexions++;
	if (lines[i+1][j] == '#')
		connexions++;
	return(connexions);
}

int	is_tetris_ok(t_flist list)
{
	t_tetris	*current;
	int			i;
	int			j;
	int			connexion;

	current = list.first;
	while (&current != NULL)
	{
		i = 0;
		while (i < 4)
		{
			j = 0;
			while(current->lines[i][j])
			{
				if (current->lines[i][j] == '#')
				{
					connexion = connexion + check_connexion(current->lines,i ,j);
				}
				j++;
			}
			i++;
		}
		printf("connexion = %d\n", connexion)
		if (!(connexion == 6 || connexion == 8))
			return (1);
		current = current->next;
	}
	return(0);
}