/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeltour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 17:05:32 by mdeltour          #+#    #+#             */
/*   Updated: 2019/04/15 11:49:19 by mdeltour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
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
		count++;
	}
	return ((void *)dst);
}
