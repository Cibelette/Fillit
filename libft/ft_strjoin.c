/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeltour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 15:25:55 by mdeltour          #+#    #+#             */
/*   Updated: 2019/04/13 16:34:32 by mdeltour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*strnew;

	if (!s1 || !s2 || !(strnew = ft_strnew((ft_strlen(s1) + ft_strlen(s2)))))
		return (NULL);
	strnew = ft_strcpy(strnew, s1);
	strnew = ft_strcat(strnew, s2);
	return (strnew);
}
