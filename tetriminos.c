/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetriminos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeltour <mdeltour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/18 18:46:14 by mdeltour          #+#    #+#             */
/*   Updated: 2019/06/09 18:13:58 by mdeltour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		assign_letter(char letter, t_tetris *newtetris)
{
	int y;
	int x;

	y = 0;
	while (y < 4)
	{
		x = 0;
		while (x < 4)
		{
			if (newtetris->line[y][x] == '#')
				newtetris->line[y][x] = letter;
			x++;
		}
		y++;
	}
}

void		move_tetri(t_tetris *newtetris, char arg)
{
	int		x;
	int		y;

	y = 0;
	while (y < 4)
	{
		x = 0;
		while (x < 4)
		{
			if (newtetris->line[y][x] == '#' && arg == 'x')
			{
				newtetris->line[y][x] = '.';
				newtetris->line[y][x - 1] = '#';
			}
			else if (newtetris->line[y][x] == '#' && arg == 'y')
			{
				newtetris->line[y][x] = '.';
				newtetris->line[y - 1][x] = '#';
			}
			x++;
		}
		y++;
	}
}

t_tetris	*create_tetris(char line[4][4], char letter)
{
	t_tetris	*newtetris;
	int			y;
	int			diese;
	int			i;
	
	if (!(newtetris = (t_tetris *)malloc(sizeof(t_tetris))))
		return (NULL);
	y = 0;
	diese = 0;
	while (y < 4)
	{
		ft_strcpy(newtetris->line[y], line[y]);
		y++;
	}
	y = 0;
	while (y < 4)
	{
		i = 0;
		while (i < 4)
		{
			if (newtetris->line[y][i] == '#')
				diese++;
			i++;
		}
		y++;
	}
	if (diese != 4)
		return (NULL);
	while (newtetris->line[0][0] != '#' && newtetris->line[1][0] != '#'
		&& newtetris->line[2][0] != '#' && newtetris->line[3][0] != '#')
		move_tetri(newtetris, 'x');
	while (newtetris->line[0][0] != '#' && newtetris->line[0][1] != '#'
		&& newtetris->line[0][2] != '#' && newtetris->line[0][3] != '#')
		move_tetri(newtetris, 'y');
	assign_letter(letter, newtetris);
	newtetris->next = NULL;
	return (newtetris);
}

t_flist		*newtetris(t_flist *list, char line[4][4], char letter)
{
	t_tetris	*newtetris;

	if (list != NULL)
	{
		if (!(newtetris = create_tetris(line, letter)))
			return (NULL);
		if (list->last == NULL)
		{
			newtetris->prev = NULL;
			list->first = newtetris;
			list->last = newtetris;
		}
		else
		{
			list->last->next = newtetris;
			newtetris->prev = list->last;
			list->last = newtetris;
		}
		list->tetri++;
	}
	return (list);
}

int			is_tetris_ok(t_flist list)
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
			return (ft_free_error());
		curr = curr->next;
		letter++;
	}
	return (0);
}
