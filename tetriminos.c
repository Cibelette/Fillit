/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetriminos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magnon <magnon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/18 18:46:14 by mdeltour          #+#    #+#             */
/*   Updated: 2019/06/13 19:39:30 by magnon           ###   ########.fr       */
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

static int	ft_count_diese(t_tetris *newtetris)
{
	int		diese;
	int		x;
	int		y;

	diese = 0;
	y = 0;
	while (y < 4)
	{
		x = 0;
		while (x < 4)
		{
			if (newtetris->line[y][x] == '#')
				diese++;
			x++;
		}
		y++;
	}
	return (diese);
}

t_tetris	*create_tetris(char line[5][5], char letter)
{
	t_tetris	*newtetris;
	int			y;
	int			diese;

	if (!(newtetris = (t_tetris *)malloc(sizeof(t_tetris))))
		return (NULL);
	y = 0;
	diese = 0;
	while (y < 4)
	{
		ft_strcpy(newtetris->line[y], line[y]);
		newtetris->line[y][4] = '\0';
		y++;
	}
	if ((diese = ft_count_diese(newtetris)) != 4)
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

t_flist		*newtetris(t_flist *list, char line[5][5], char letter)
{
	t_tetris	*newtetris;

	if (list != NULL)
	{
		if ((newtetris = create_tetris(line, letter)) == NULL)
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
