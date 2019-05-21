/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeltour <mdeltour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 18:34:39 by mdeltour          #+#    #+#             */
/*   Updated: 2019/05/21 12:58:39 by mdeltour         ###   ########.fr       */
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
	char			lines[4][5];
	struct s_tetris	*prev;
	struct s_tetris	*next;
}					t_tetris;

int					ft_fillit(int fd);
t_flist				*ft_newlist(void);
int					is_valid_str(char *str);
t_tetris			*create_tetris(char lines[4][5]);
t_flist				*newtetris(t_flist *list, char lines[4][5]);
int					ft_free_error(void);
int					is_file_ok(int fd);
int					is_tetris_ok(t_flist list);
int					check_connexion(char lines[4][5], int i, int j);
int					count_connexion(t_tetris *current);

#endif
