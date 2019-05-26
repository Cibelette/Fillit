/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeltour <mdeltour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/26 15:47:54 by mdeltour          #+#    #+#             */
/*   Updated: 2019/05/26 15:53:18 by mdeltour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	free_board(char **board, int board_size)
{
	int		i;

	i = 0;
	while (i < board_size + 4)
	{
		free(board[i]);
		board[i] = NULL;
		i++;
	}
	free(board[i]);
	board[i] = NULL;
	free(board);
	board = NULL;
}

void	print_board(char **board, int board_size)
{
	int i;
	int j;

	i = 0;
	while (i < board_size)
	{
		j = 0;
		while (j < board_size)
		{
			ft_putchar(board[i][j]);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}

int		size_of_board(int nb_piece)
{
	int	result;

	result  = 2;
	while (result * result < nb_piece * 4)
		result++;
	return (result);
}

char	**extend_tab(char **tab, size_t new_size)
{
	char	**newtab;
	size_t		i;

	if (tab)
		free_board(tab, new_size - 1);
	if (!(newtab = (char **)malloc(sizeof(char *) * (new_size + 5))))
		return (NULL);
	i = 0;
	while (i < new_size + 4)
	{
		newtab[i] = ft_strnew_with_dot(new_size);
		i++;
	}
	newtab[i] = 0;
	return (newtab);
}


t_board	*init_board(t_flist *list, t_board *board)
{
	if (!(board = (t_board *)malloc(sizeof(t_board))))
		return (NULL);
	board->size = size_of_board(list->tetri);
	printf("%zu\n%zu\n", list->tetri, board->size);
	board->tab = extend_tab(NULL, board->size);
	return (board);
}
