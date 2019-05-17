/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeltour <mdeltour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 15:52:50 by mdeltour          #+#    #+#             */
/*   Updated: 2019/05/17 14:42:40 by mdeltour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		add_last(t_gnl **lst, t_gnl *elem)
{
	t_gnl *list;

	list = *lst;
	while (list->next != NULL)
		list = list->next;
	list->next = elem;
	elem->next = NULL;
}

static t_gnl	*new_list(int fd)
{
	t_gnl *list;

	if (!(list = (t_gnl*)malloc(sizeof(*list))))
		return (NULL);
	list->fd = fd;
	list->temp = ft_strnew(0);
	list->line = NULL;
	list->next = NULL;
	return (list);
}

static t_gnl	*check_fd(t_gnl *lst, int fd)
{
	t_gnl *tmp;
	t_gnl *d_list;

	tmp = NULL;
	d_list = lst;
	while (d_list)
	{
		if (d_list->fd == fd)
			return (d_list);
		if (!(d_list->next))
		{
			tmp = new_list(fd);
			add_last(&d_list, tmp);
			return (tmp);
		}
		d_list = d_list->next;
	}
	return (NULL);
}

static int		check(char *str, char **line)
{
	char	*fin;

	if (!str)
		return (0);
	fin = ft_strchr(str, '\n');
	if (fin != NULL)
	{
		*fin = '\0';
		*line = ft_strdup(str);
		ft_strncpy(str, &fin[1], ft_strlen(&fin[1]) + 1);
		return (1);
	}
	else if (ft_strlen(str) > 0)
	{
		*line = ft_strdup(str);
		*str = '\0';
		return (1);
	}
	return (0);
}

int				get_next_line(const int fd, char **line)
{
	char			buf[BUFF_SIZE + 1];
	static t_gnl	*lst;
	t_gnl			*tmp;
	int				ret;

	if (fd == -1 || line == NULL || BUFF_SIZE <= 0)
		return (-1);
	if (!(lst))
		lst = new_list(fd);
	tmp = check_fd(lst, fd);
	while (!(ft_strchr(tmp->temp, '\n')))
	{
		ret = read(fd, buf, BUFF_SIZE);
		if (ret == -1)
			return (-1);
		if (ret == 0)
			return (check(tmp->line, line));
		buf[ret] = '\0';
		tmp->line = ft_strjoin(tmp->temp, buf);
		free(tmp->temp);
		tmp->temp = tmp->line;
	}
	return (check(tmp->line, line));
}
