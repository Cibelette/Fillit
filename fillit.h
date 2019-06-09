/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeltour <mdeltour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 18:34:39 by mdeltour          #+#    #+#             */
/*   Updated: 2019/06/09 16:54:14 by mdeltour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft.h"
# include <sys/types.h>
# include <sys/uio.h>
# include <fcntl.h>
# define END 0
# define OK 1
# define ERROR -1

typedef struct		s_flist
{
	int				tetri;
	struct s_tetris	*first;
	struct s_tetris	*last;
}					t_flist;

typedef struct		s_tetris
{
	char			line[4][4];
	struct s_tetris	*prev;
	struct s_tetris	*next;
}					t_tetris;

typedef struct		s_map
{
	char			**tab;
	int				size;
	int				x;
	int				y;
}					t_map;

/*
** main.c
*/

int					ft_fillit(int fd);

/*
** tetriminos.c
*/

t_flist				*newtetris(t_flist *list, char line[4][4], char letter);
t_tetris			*create_tetris(char line[4][4], char letter);
void				move_tetri(t_tetris	*newtetris, char arg);
int					is_tetris_ok(t_flist list);
void				assign_letter(char letter, t_tetris *newtetris);

/*
** valid_file.c
*/

int					is_file_ok(int fd, t_flist *list);
int					is_valid_str(char *str);
t_flist				*ft_newlist(void);
int					check_connexion(char line[4][4], int i, int j, char letter);
int					count_connexion(t_tetris *curr, char letter);

/*
** map.c
*/

t_map				*init_map(t_map *map);
t_map				*extend_tab(t_map *map, int new_size);
void				print_map(t_map *map, int map_size);
int					save_map(char **dest, char **srcs, int size);

/*
** solve_map.c
*/

int					ft_solve(t_tetris *curr, t_map *map);

/*
** tool.c
*/

t_flist				*ft_newlist(void);
char				*ft_strnew_with_dot(int size);
char				*ft_strncpy_without(const char *src, int len);
int					ft_free_error(void);

#endif
