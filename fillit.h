/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magnon <magnon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 18:34:39 by mdeltour          #+#    #+#             */
/*   Updated: 2019/06/14 21:13:22 by magnon           ###   ########.fr       */
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
	char			line[5][5];
	struct s_tetris	*prev;
	struct s_tetris	*next;
}					t_tetris;

typedef struct		s_map
{
	char			**tab;
	int				size;
}					t_map;

/*
** main.c
*/

int					ft_fillit(int fd);

/*
** tetriminos.c
*/

t_flist				*newtetris(t_flist *list, char line[5][5], char letter);
t_tetris			*create_tetris(char line[5][5], char letter);
void				move_tetri(t_tetris	*newtetris, char arg);
int					is_tetris_ok(t_flist list);
void				assign_letter(char letter, t_tetris *newtetris);

/*
** tetriminos2.c
*/

int					is_tetris_ok(t_flist list);

/*
** valid_file.c
*/

int					is_file_ok(int fd, t_flist *list, int j, char letter);
int					valid_str(char *str);
int					check_connexion(char line[5][5], int i, int j, char letter);
int					count_connexion(t_tetris *curr, char letter);

/*
** map.c
*/

t_map				*init_map(t_map *map, t_flist *list);
t_map				*extend_tab(t_map *map, int new_size);
void				print_map(t_map *map, int map_size);
t_map				*restaure_map(t_map *map, int size, t_tetris *curr);

/*
** solve_map.c
*/

int					ft_solve(t_tetris *curr, t_map *map);

/*
** tool.c
*/

char				find_letter(t_tetris *curr);
t_flist				*ft_newlist(void);
char				*ft_strnew_with_dot(int size);
int					is_upper_case(char c);
void				cpy_del(char tetris[5][5], char *line, int j);

/*
** free.c
*/

void				free_all(t_flist *list, t_map *map);
void				free_map(t_map *map);
void				free_tetri_list(t_flist *list);
t_tetris			*free_tetri(t_tetris *tetri);

/*
** free_error.c
*/

int					free_error_all(t_flist *list, t_map *map);
int					free_error_list(t_flist *list);
int					error_list_ret(t_flist *list);
int					free_ret(char *line, int ret);
int					free_ret2(char *line, int j);

#endif
