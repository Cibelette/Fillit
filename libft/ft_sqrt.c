/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeltour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 13:37:04 by mdeltour          #+#    #+#             */
/*   Updated: 2019/06/11 13:38:14 by mdeltour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_sqrt(int nb)
{
	int sqrt;

	sqrt = 1;
	while ((sqrt * sqrt) < nb && sqrt < 46341)
		sqrt++;
	if (sqrt * sqrt == nb)
		return (sqrt);
	if (sqrt * sqrt > nb)
		return (sqrt - 1);
	return (0);
}
