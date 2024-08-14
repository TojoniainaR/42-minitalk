/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: torandri <torandri@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 11:51:31 by torandri          #+#    #+#             */
/*   Updated: 2024/04/08 12:34:07 by torandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_len_nbr(unsigned int nbr)
{
	int		len;

	len = 0;
	if (nbr == 0)
		len ++;
	while (nbr)
	{
		nbr /= 10;
		len++;
	}
	return (len);
}

int	ft_print_unsd(unsigned int nbr)
{
	int		len_nbr;

	len_nbr = ft_len_nbr(nbr);
	if (nbr >= 10)
	{
		ft_print_unsd(nbr / 10);
	}
	ft_print_char(nbr % 10 + '0');
	return (len_nbr);
}
