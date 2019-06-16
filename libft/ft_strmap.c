/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeltour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 13:41:28 by mdeltour          #+#    #+#             */
/*   Updated: 2019/04/15 14:23:24 by mdeltour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char			*str;
	char			*strnew;
	unsigned int	i;

	i = 0;
	str = (char *)s;
	if (str && f)
	{
		if (!(strnew = ft_memalloc(ft_strlen(str) + 1)))
			return (NULL);
		while (str[i])
		{
			strnew[i] = f(str[i]);
			i++;
		}
		strnew[i] = '\0';
		return (strnew);
	}
	return (NULL);
}
