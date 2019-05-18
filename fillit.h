/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clagier <clagier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 18:34:39 by mdeltour          #+#    #+#             */
/*   Updated: 2019/05/18 15:48:14 by clagier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft.h"
# include <sys/types.h>
# include <sys/uio.h>
# include <fcntl.h>

typedef struct		flist
{
	size_t			tetris;
	struct tetris	*first;
	struct tetris	*last;
}					t_flist;

typedef struct		tetris
{
	char			lines[4][4];
	struct tetris	*prev;
	struct tetris	*next;
}					t_tetris;

int		ft_fillit(int fd);
int     ft_fillit_c(int fd);

#endif