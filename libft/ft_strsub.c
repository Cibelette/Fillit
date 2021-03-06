/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeltour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 15:19:03 by mdeltour          #+#    #+#             */
/*   Updated: 2019/04/13 15:24:11 by mdeltour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*str;
	char			*strnew;
	unsigned int	i;

	if (!(strnew = ft_strnew(len)) || !s)
		return (NULL);
	str = (char *)s;
	i = 0;
	while (i < len)
	{
		strnew[i] = str[start];
		start++;
		i++;
	}
	return (strnew);
}
