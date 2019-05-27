/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeltour <mdeltour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 18:34:39 by mdeltour          #+#    #+#             */
/*   Updated: 2019/05/27 15:31:33 by mdeltour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft.h"
# include <sys/types.h>
# include <sys/uio.h>
# include <fcntl.h>

# include <stdio.h>

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

typedef struct		s_map
{
	char			**tab;
	size_t			size;
	int				x;
	int				y;
}					t_map;

int					ft_fillit(int fd);
t_flist				*ft_newlist(void);
int					is_valid_str(char *str);
t_tetris			*create_tetris(char lines[4][5], char letter);
t_flist				*newtetris(t_flist *list, char lines[4][5], char letter);
int					ft_free_error(void);
int					is_file_ok(int fd, t_flist *list);
int					is_tetris_ok(t_flist list);
int					check_connexion(char lines[4][5], int i, int j, char letter);
int					count_connexion(t_tetris *current, char letter);

t_map	*init_map(t_flist *list, t_map *map);
char	**extend_tab(char **tab, size_t new_size);
char	*ft_strnew_with_dot(size_t size);
void	free_map(char **map, int map_size);
void	print_map(char **map, int map_size);
int		size_of_map(int nb_piece);
int		ft_solve(t_flist *list, t_map *map);
char	**put_tetris(char **map, char	line[4][5], int i, int j);

#endif
