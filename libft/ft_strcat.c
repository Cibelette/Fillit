/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeltour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 13:19:18 by mdeltour          #+#    #+#             */
/*   Updated: 2019/04/09 13:45:57 by mdeltour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	int		i;
	int		size;

	i = 0;
	size = 0;
	while (s1[size])
		size++;
	while (s2[i])
	{
		s1[size] = s2[i];
		size++;
		i++;
	}
	s1[size] = '\0';
	return (s1);
}
