/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeltour <mdeltour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 18:34:39 by mdeltour          #+#    #+#             */
/*   Updated: 2019/05/18 19:26:11 by mdeltour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft.h"
# include <sys/types.h>
# include <sys/uio.h>
# include <fcntl.h>

typedef struct		s_flist
{
	size_t			tetri;
	struct s_tetris	*first;
	struct s_tetris	*last;
}					t_flist;

typedef struct		s_tetris
{
	char			lines[4][4];
	struct s_tetris	*prev;
	struct s_tetris	*next;
}					t_tetris;

int					ft_fillit(int fd);
t_flist				*ft_newlist(void);
int					is_valid_str(char *str);

#endif
