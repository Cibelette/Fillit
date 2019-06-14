/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeltour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 15:24:05 by mdeltour          #+#    #+#             */
/*   Updated: 2019/04/16 10:01:08 by mdeltour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_intlen(int nb)
{
	int		i;

	i = 0;
	if (nb == 0)
		return (1);
	if (nb < 0)
	{
		if (nb == -2147483648)
			return (11);
		i++;
		nb = nb * -1;
	}
	while (nb > 0)
	{
		i++;
		nb = nb / 10;
	}
	return (i);
}

static void		ft_setnu(char *tab, int nb, int size)
{
	int		i;

	i = 1;
	while (nb > 0 && size - i >= 0)
	{
		tab[size - i] = nb % 10 + '0';
		i++;
		nb = nb / 10;
	}
}

char			*ft_itoa(int n)
{
	char	*result;
	int		size;

	size = (ft_intlen(n));
	if (!(result = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	if (n < 0)
	{
		if (n == -2147483648)
		{
			n = -147483648;
			result[1] = '2';
		}
		ft_setnu(result, n *= -1, size);
		result[0] = '-';
	}
	else if (n == 0)
		result[0] = '0';
	else
		ft_setnu(result, n, size);
	result[size] = '\0';
	return (result);
}
