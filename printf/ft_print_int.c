/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: torandri <torandri@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 16:03:27 by torandri          #+#    #+#             */
/*   Updated: 2024/04/08 12:26:15 by torandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_len_nbr(int nb)
{
	int		len;
	long	nbr;

	len = 0;
	nbr = (long)nb;
	if (nbr < 0)
	{
		len++;
		nbr *= -1;
	}
	if (nbr == 0)
		len ++;
	while (nbr)
	{
		nbr /= 10;
		len++;
	}
	return (len);
}

int	ft_print_int(int nb)
{
	long	nbr;
	int		len_nbr;

	nbr = (long)nb;
	len_nbr = ft_len_nbr(nbr);
	if (nbr < 0)
	{
		ft_print_char('-');
		nbr = -nbr;
	}
	if (nbr >= 10)
	{
		ft_print_int(nbr / 10);
	}
	ft_print_char(nbr % 10 + '0');
	return (len_nbr);
}
