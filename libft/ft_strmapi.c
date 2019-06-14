/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeltour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 15:06:01 by mdeltour          #+#    #+#             */
/*   Updated: 2019/04/15 14:24:12 by mdeltour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
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
			strnew[i] = f(i, str[i]);
			i++;
		}
		strnew[i] = '\0';
		return (strnew);
	}
	return (NULL);
}
