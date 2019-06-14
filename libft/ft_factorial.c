/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_factorial.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeltour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 13:42:11 by mdeltour          #+#    #+#             */
/*   Updated: 2019/04/20 13:42:46 by mdeltour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_factorial(int nb)
{
	if (nb > 12 || nb < 0)
		return (0);
	else if (nb == 1 || nb == 2)
		return (nb);
	else if (nb == 0)
		return (1);
	else
		nb = (nb * ft_factorial(nb - 1));
	return (nb);
}
