/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magnon <magnon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 18:32:17 by mdeltour          #+#    #+#             */
/*   Updated: 2019/06/14 21:03:35 by magnon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_fillit(int fd)
{
	t_flist		*list;
	t_map		*map;
	int			status;

	if (fd < 0)
		return (ERROR);
	if ((list = ft_newlist()) == NULL)
		return (error_list_ret(list));
	if (is_file_ok(fd, list, 0, 'A') != 0)
		return (free_error_list(list));
	map = NULL;
	if (!(map = init_map(map, list)))
		return (free_error_all(list, map));
	status = 2;
	while ((status = ft_solve(list->first, map)) == ERROR)
	{
		map->size += 1;
		if (!(map = init_map(map, list)))
			return (free_error_all(list, map));
	}
	print_map(map, map->size);
	free_all(list, map);
	return (END);
}

int		main(int argc, char **argv)
{
	int	fd;

	if (argc != 2)
	{
		ft_putstr_fd("usage: ./fillit source_file\n", 2);
		return (ERROR);
	}
	fd = open(argv[1], O_RDONLY);
	if (ft_fillit(fd) == ERROR)
	{
		close(fd);
		ft_putstr_fd("error\n", 1);
		return (ERROR);
	}
	close(fd);
	return (END);
}
