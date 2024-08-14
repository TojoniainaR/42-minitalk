/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexa_high.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: torandri <torandri@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 16:19:35 by torandri          #+#    #+#             */
/*   Updated: 2024/04/09 14:16:10 by torandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hexa_high(unsigned long nb)
{
	int				i;
	char			*base;
	unsigned int	nbr;

	i = 0;
	base = "0123456789ABCDEF";
	nbr = (unsigned int)nb;
	if (nbr >= 16)
		i += ft_print_hexa_high(nbr / 16);
	i += ft_print_char(*(base + (nbr % 16)));
	return (i);
}
