/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeltour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 18:24:09 by mdeltour          #+#    #+#             */
/*   Updated: 2019/04/15 15:09:07 by mdeltour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*str;

	str = (char *)s;
	i = (ft_strlen(s) - 1);
	if (str)
	{
		while (str[i])
			i++;
		while (str[i] != (char)c && i >= 0)
			i--;
		if (str[i] == (char)c)
			return (str + i);
	}
	return (NULL);
}
