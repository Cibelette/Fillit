/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_tetris_valid.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cibyl <cibyl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 11:51:57 by clagier           #+#    #+#             */
/*   Updated: 2019/05/22 15:59:47 by cibyl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int check_connexion(char lines[4][5], int i, int j, char letter)
{
	int connexions;

	connexions = 0;
	if (lines[i][j-1] == letter)
		connexions++;
	if (lines[i][j+1] == letter)
		connexions++;
	if (lines[i-1][j] == letter)
		connexions++;
	if (lines[i+1][j] == letter)
		connexions++;
	return(connexions);
}

int	is_tetris_ok(t_flist list)
{
	t_tetris	*current;
	int			i;
	int			j;
	int			connexion;
	char		letter;
	int			diese;

	letter = 'A';
	int diese;
	current = list.first;
	while (&current != NULL)
	{
		diese = 0;
		i = 0;
		while (i < 4)
		{
			j = 0;
			while(current->lines[i][j])
			{
				if (current->lines[i][j] == letter)
				{
					connexion = connexion + check_connexion(current->lines,i ,j, letter);
					diese++;
				}
				j++;
			}
			i++;
		}
		printf("connexion = %d, dieses = %d\n", connexion, diese);
		if (!(connexion == 6 || connexion == 8 ||connexion == 0))
			return (1);
		if (connexion == 0 && diese != 0)
			return (1);
		current = current->next;
		letter++;
	}
	return(0);
}