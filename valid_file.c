/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magnon <magnon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 12:33:03 by mdeltour          #+#    #+#             */
/*   Updated: 2019/06/13 19:37:44 by magnon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int				check_connexion(char line[5][5], int i, int j, char letter)
{
	int connexions;

	connexions = 0;
	if (j > 0 && line[i][j - 1] == letter)
		connexions++;
	if (j < 3 && line[i][j + 1] == letter)
		connexions++;
	if (i > 0 && line[i - 1][j] == letter)
		connexions++;
	if (i < 3 && line[i + 1][j] == letter)
		connexions++;
	return (connexions);
}

int				count_connexion(t_tetris *curr, char letter)
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
		while (j < 4)
		{
			if (curr->line[i][j] == letter)
			{
				diese++;
				connexion += check_connexion(curr->line, i, j, letter);
			}
			j++;
		}
		i++;
	}
	if (connexion == 0 || diese != 4)
		return (-1);
	return (connexion);
}

int				check_after_ret(int ret, t_flist *list, char *line)
{
	if (ret == 0)
	{
		if (is_tetris_ok(*list) != 0)
			return (1);
		return (0);
	}
	if (line[0] != '\0' || ret == -1)
		return (1);
	return (3);
}

int				is_file_ok(int fd, t_flist *list)
{
	char		*line;
	char		tetris[5][5];
	int			j;
	int			ret;
	char		letter;

	letter = 'A';
	j = 0;
	ret = 2;
	while (ret > 0)
	{
		while (j < 4 && ret > 0)
		{
			ret = get_next_line(fd, &line);
			if (ret == 0 || is_valid_str(line) != 4)
				return (1);
			ft_strcpy(tetris[j], line);
			ft_memdel((void **)&line);
			j++;
		}
		if (j != 4 || (list = newtetris(list, tetris, letter)) == NULL)
			return (1);
		letter++;
		ret = get_next_line(fd, &line);
		if ((j = check_after_ret(ret, list, line)) != 3)
			return (j);
		ft_memdel((void **)&line);
		j = 0;
	}
	return (0);
}
