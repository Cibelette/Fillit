/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeltour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 17:52:14 by mdeltour          #+#    #+#             */
/*   Updated: 2019/04/15 11:50:09 by mdeltour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t	count;
	char	*s_src;
	char	*d_dst;

	if (!dst && !src)
		return (NULL);
	count = 0;
	s_src = (char *)src;
	d_dst = (char *)dst;
	while (count < n)
	{
		d_dst[count] = s_src[count];
		if ((char)c == d_dst[count])
			return ((void *)&d_dst[count + 1]);
		count++;
	}
	return (NULL);
}
