/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeltour <mdeltour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/05 18:32:06 by mdeltour          #+#    #+#             */
/*   Updated: 2019/05/17 21:06:01 by mdeltour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		is_valid_str(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((str[i] != '#') && (str[i] != '.'))
			return (-1);
		i++;
	}
	return (i);
}

int		pre_check(int fd)
{
	char	*line;
	int		ret;
	int		j;
	int		end;

	line = NULL;
	j = 0;
	ret = 2;
	end = 0;
	
	while (ret > 0)
	{
		while (j < 4 && ret > 0)
		{
			ret = get_next_line(fd, &line);
			end++;
			if (is_valid_str(line) != 4)
				return (1);
			j++;
		}
		if (ret > 0)
		{
			j = 0;
			ret = get_next_line(fd, &line);
			end++;
			if (ret == 0)
            	return (0);
			if (line[0] != '\0')
				return (1);
		}
	}
	if ((end % 5) != 0)
		return (1);
	return (0);
}

/*int    is_file_ok(int fd)
{
    char *line;
    int     i;
    int        j = 0;
    int ret;

    ret = 1;
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
            ft_putstr(line);
            ft_putchar('\n');
            j++;
        }
        ret = get_next_line(fd, &line);
        if (ret == 0)
            return (0);
        printf("cc\n");
        ft_putchar(line[0]);
        printf("cc\n");
        if (line[0] != '\0')
            return (1);
        j = 0;
    }
    return (0);
}

int        ft_fillit_clara(int fd)
{
    int ok;

    if (fd < 0)
        return (1);

    ok = is_file_ok(fd);

   printf ("%d", ok);
    return (ok);
}
*/

int		ft_fillit(int fd)
{
	if (fd < 0)
		return (1);
	if (pre_check(fd) != 0)
		return (1);
	return (0);
}
