/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeltour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 18:21:18 by mdeltour          #+#    #+#             */
/*   Updated: 2019/04/12 14:48:25 by mdeltour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*str;
	size_t	count;

	str = (char *)s;
	count = 0;
	while (count < n)
	{
		if ((char)c == str[0])
			return ((void *)str);
		str++;
		count++;
	}
	return (NULL);
}
