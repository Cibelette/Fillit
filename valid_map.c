/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeltour <mdeltour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 12:33:03 by mdeltour          #+#    #+#             */
/*   Updated: 2019/05/21 12:56:22 by mdeltour         ###   ########.fr       */
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

int				check_connexion(char lines[4][5], int i, int j)
{
	int connexions;

	connexions = 0;
	if (lines[i][j - 1] == '#')
		connexions++;
	if (lines[i][j + 1] == '#')
		connexions++;
	if (lines[i - 1][j] == '#')
		connexions++;
	if (lines[i + 1][j] == '#')
		connexions++;
	return (connexions);
}

int				count_connexion(t_tetris *current)
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
			if (current->lines[i][j] == '#')
			{
				diese++;
				connexion += check_connexion(current->lines, i, j);
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

	current = list.first;
	while (current != NULL)
	{
		connexion = count_connexion(current);
		printf("connexion = %d\n", connexion);
		if (!(connexion == 6 || connexion == 8 || connexion == 0))
			return (ft_free_error());
		current = current->next;
	}
	return (0);
}
