/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeltour <mdeltour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 18:32:17 by mdeltour          #+#    #+#             */
/*   Updated: 2019/05/17 21:06:37 by mdeltour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	main(int argc, char **argv)
{
	int	fd;

	if (argc != 2)
	{
		ft_putstr_fd("usage: ./fillit source_file\n", 2);
		return (1);
	}
	fd = open(argv[1], O_RDONLY);
	if (ft_fillit(fd) == 1)
	{
		close(fd);
		ft_putstr_fd("error\n", 2);
		return (1);
	}
	/*if (ft_fillit_clara(fd) == 1)
	{
		close(fd);
		ft_putstr_fd("error\n", 2);
		return (1);
	}
	*/
	close(fd);
	return (0);
}