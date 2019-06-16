/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeltour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 15:52:11 by mdeltour          #+#    #+#             */
/*   Updated: 2019/04/15 11:34:47 by mdeltour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*str;
	char	*strnew;
	size_t	len;
	size_t	i;

	i = 0;
	str = (char *)s;
	if (!str)
		return (NULL);
	while (*str == ' ' || *str == '\t' || *str == '\n')
		str++;
	len = ft_strlen(str) - 1;
	if (ft_strlen(str) == 0)
		return (strnew = ft_strnew(0));
	while (str[len] == ' ' || str[len] == '\t' || str[len] == '\n')
		len--;
	if (!(strnew = ft_strnew(len + 1)))
		return (NULL);
	while (i <= len)
	{
		strnew[i] = str[i];
		i++;
	}
	strnew[i] = '\0';
	return (strnew);
}
