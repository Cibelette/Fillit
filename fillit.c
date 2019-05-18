/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clagier <clagier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/05 18:32:06 by mdeltour          #+#    #+#             */
/*   Updated: 2019/05/18 16:08:44 by clagier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_flist			*newlist(void)
{
    t_flist *list;
	
    if (!(list = malloc(sizeof(t_flist))))
        return (list);
    list->tetris = 0;
    list->first = NULL;
    list->last = NULL;
    return (list);
}

t_flist			*newtetris(t_flist *list, char lines[4][5])
{
    int j;

    j = 0;
    if (list != NULL)
    {
        t_tetris *newtetris;
        if (!(newtetris = malloc(sizeof *newtetris)))
            return (list);
        while (j < 4)
        {
            ft_strcpy(newtetris->lines[j], lines[j]);
            j++;
        }
        newtetris->next = NULL;
        if (list->last == NULL)
        {
            newtetris->prev = NULL;
            list->first = newtetris;
            list->last = newtetris;
        }
        else
        {
            list->last->next = newtetris;
            newtetris->prev = list->last;
            list->last = newtetris;
        }
        list->tetris++;
    }
    return (list);
}

int			is_file_ok(int fd)
{
    t_flist  *list;   
    char *line;
    char tetris[4][5];
    int     i;
    int        j = 0;
    int ret;
    ret = 1;

    list = newlist();
    while (ret == 1)
    {
        while (j < 4 && ret > 0)
        {
            i = 0;
            ret = get_next_line(fd, &line);
            while (line[i] == '.' || line[i] == '#')
                i++;
            if (line[i] != '\0' || i != 4)
            {
                return (1);
            }
            ft_strcpy(tetris[j], line);
            j++;
        }
		list = newtetris(list, tetris);
        ret = get_next_line(fd, &line);
        if (ret == 0)
            return (0);
        if (line[0] != '\0')
            return (1);
        j = 0;
    }
    return (0);
}
int			ft_fillit(int fd)
{
	int ok;
	if (fd < 0)
		return (1);
	ok = is_file_ok(fd);
	return (ok);
}
