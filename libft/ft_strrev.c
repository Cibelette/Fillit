/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeltour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 13:20:22 by mdeltour          #+#    #+#             */
/*   Updated: 2019/04/20 13:25:46 by mdeltour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *str)
{
	int		cursor;
	int		end;
	char	tmp;

	cursor = 0;
	end = 0;
	while (str[end])
		end++;
	end--;
	while (cursor < end)
	{
		tmp = str[cursor];
		str[cursor] = str[end];
		str[end] = tmp;
		cursor++;
		end--;
	}
	return (str);
}
