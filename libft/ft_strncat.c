/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeltour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 15:00:06 by mdeltour          #+#    #+#             */
/*   Updated: 2019/04/09 15:01:31 by mdeltour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t		i;
	size_t		size;

	i = 0;
	size = 0;
	while (s1[size])
		size++;
	while (s2[i] && i < n)
	{
		s1[size] = s2[i];
		size++;
		i++;
	}
	s1[size] = '\0';
	return (s1);
}
