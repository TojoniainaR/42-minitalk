/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexa_low.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: torandri <torandri@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 16:19:19 by torandri          #+#    #+#             */
/*   Updated: 2024/04/08 17:18:29 by torandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hexa_low(unsigned long nb)
{
	int				i;
	char			*base;
	unsigned int	nbr;

	i = 0;
	base = "0123456789abcdef";
	nbr = (unsigned int)nb;
	if (nbr >= 16)
		i += ft_print_hexa_low(nbr / 16);
	i += ft_print_char(*(base + (nbr % 16)));
	return (i);
}
