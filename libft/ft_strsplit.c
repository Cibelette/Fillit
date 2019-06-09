/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeltour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 14:57:49 by mdeltour          #+#    #+#             */
/*   Updated: 2019/04/16 15:16:04 by mdeltour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_cwrd(char *str, char c)
{
	int			result;
	int			i;

	i = 0;
	result = 0;
	while (str[i])
	{
		if (!(str[i] == c))
		{
			while (!(str[i] == c || str[i] == '\0'))
				i++;
			result++;
		}
		while (str[i] == c)
			i++;
	}
	return (result);
}

static int		ft_l(int i, char *str, char c)
{
	int		len;

	len = 0;
	while (!(str[i] == '\0' || str[i] == c))
	{
		i++;
		len++;
	}
	return (len);
}

static int		ft_modstrcpy(int i, char *dest, char *s, char c)
{
	int		j;

	j = 0;
	while (!(s[i] == c || s[i] == '\0'))
	{
		dest[j] = s[i];
		j++;
		i++;
	}
	dest[j] = '\0';
	return (i);
}

char			**ft_strsplit(char const *s, char c)
{
	int		j;
	int		i;
	char	**t;
	char	*str;

	str = (char *)s;
	if (str == '\0')
		return (NULL);
	if (!(t = (char **)ft_memalloc(sizeof(char *) * (ft_cwrd(str, c) + 1))))
		return (NULL);
	j = 0;
	i = 0;
	while (str[i])
	{
		if (!(str[i] == c))
		{
			if (!(t[j] = (char *)malloc(sizeof(char) * (ft_l(i, str, c) + 1))))
				return (NULL);
			i = ft_modstrcpy(i, t[j++], str, c);
		}
		while (str[i] == c)
			i++;
	}
	t[j] = NULL;
	return (t);
}
