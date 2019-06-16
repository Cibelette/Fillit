/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeltour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 19:05:47 by mdeltour          #+#    #+#             */
/*   Updated: 2019/04/15 15:34:38 by mdeltour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int		i;
	int		j;

	i = 0;
	if (*haystack == '\0' && *needle != '\0')
		return (NULL);
	if (*haystack == '\0' || *needle == '\0')
		return ((char *)haystack);
	if (haystack || needle)
	{
		while (haystack[i])
		{
			j = 0;
			while (needle[j] == haystack[i + j])
			{
				if (needle[j + 1] == '\0')
					return ((char *)haystack + i);
				j++;
			}
			i++;
		}
	}
	return (NULL);
}
