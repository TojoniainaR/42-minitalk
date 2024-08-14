/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: torandri <torandri@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 11:49:41 by torandri          #+#    #+#             */
/*   Updated: 2024/04/09 11:45:57 by torandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_print_in_hexa(unsigned long nbr)
{
	int				i;
	char			*base;

	i = 0;
	base = "0123456789abcdef";
	if (nbr >= 16)
		i += ft_print_in_hexa(nbr / 16);
	i += ft_print_char(*(base + (nbr % 16)));
	return (i);
}

int	ft_print_pointer(void *input)
{
	int				i;
	unsigned long	unsdl_input;

	if (!input)
	{
		ft_print_str("(nil)");
		return (5);
	}
	unsdl_input = (unsigned long)input;
	write(1, "0x", 2);
	i = 2;
	i += ft_print_in_hexa(unsdl_input);
	return (i);
}
