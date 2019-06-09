/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeltour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 19:05:16 by mdeltour          #+#    #+#             */
/*   Updated: 2019/04/15 15:41:00 by mdeltour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t		i;
	size_t		j;

	i = 0;
	j = 0;
	if (*haystack == '\0' && *needle != '\0')
		return (NULL);
	if (*haystack == '\0' || *needle == '\0')
		return ((char *)haystack);
	if ((haystack || needle) && len > 0)
	{
		while (haystack[i] && i < len)
		{
			j = 0;
			while (needle[j] == haystack[i + j] && (j < (len - i)))
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
