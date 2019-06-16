/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeltour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 15:08:57 by mdeltour          #+#    #+#             */
/*   Updated: 2019/04/10 19:42:25 by mdeltour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	len;
	size_t	j;
	size_t	ret;

	len = ft_strlen(dst);
	ret = size;
	if (len > size)
		len = size;
	j = -1;
	while (src[++j] && size-- > len + 1)
		dst[j + len] = src[j];
	if (ret > j + len)
		dst[j + len] = '\0';
	return (ft_strlen(src) + len);
}
