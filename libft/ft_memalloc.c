/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeltour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 19:44:54 by mdeltour          #+#    #+#             */
/*   Updated: 2019/04/12 16:40:53 by mdeltour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char	*s;

	s = NULL;
	if (!(s = (char *)malloc(sizeof(char) * size)))
		return (NULL);
	ft_bzero(s, size);
	return ((void *)s);
}
