/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cibyl <cibyl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 12:33:03 by mdeltour          #+#    #+#             */
/*   Updated: 2019/05/22 16:18:39 by cibyl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdio.h"
#include "fillit.h"

int				is_valid_str(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if ((str[i] != '#') && (str[i] != '.'))
			return (-1);
		i++;
	}
	return (i);
}

int				check_connexion(char lines[4][5], int i, int j, char letter)
{
	int connexions;

	connexions = 0;
	if (lines[i][j - 1] == letter)
		connexions++;
	if (lines[i][j + 1] == letter)
		connexions++;
	if (lines[i - 1][j] == letter)
		connexions++;
	if (lines[i + 1][j] == letter)
		connexions++;
	return (connexions);
}

int				count_connexion(t_tetris *current, char letter)
{
	int			i;
	int			j;
	int			connexion;
	int			diese;

	diese = 0;
	connexion = 0;
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (current->lines[i][j])
		{
			if (current->lines[i][j] == letter)
			{
				diese++;
				connexion += check_connexion(current->lines, i, j, letter);
			}
			j++;
		}
		i++;
	}
	if (connexion == 0 && diese != 0)
		return (-1);
	return (connexion);
}

int				is_tetris_ok(t_flist list)
{
	t_tetris	*current;
	int			connexion;
	char	letter;

	letter = 'A';
	current = list.first;
	while (current != NULL)
	{
		connexion = count_connexion(current, letter);
		printf("connexion = %d\n", connexion);
		if (!(connexion == 6 || connexion == 8 || connexion == 0))
			return (ft_free_error());
		current = current->next;
		letter++;
	}
	return (0);
}
