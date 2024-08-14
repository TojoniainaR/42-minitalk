/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: torandri <torandri@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 21:24:52 by torandri          #+#    #+#             */
/*   Updated: 2024/04/09 14:17:57 by torandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0' && s[i] != (char)c)
	{
		if (c == s[i])
			return (0);
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)(s + i));
	return (0);
}

static int	ft_format_type(const char *format, va_list args)
{
	int	i;

	i = 0;
	if (*format == 'c')
		i += ft_print_char(va_arg(args, int));
	else if (*format == 's')
		i += ft_print_str(va_arg(args, char *));
	else if (*format == 'p')
		i += ft_print_pointer(va_arg(args, void *));
	else if (*format == 'd' || *format == 'i')
		i += ft_print_int(va_arg(args, int));
	else if (*format == 'u')
		i += ft_print_unsd(va_arg(args, unsigned int));
	else if (*format == 'x')
		i += ft_print_hexa_low(va_arg(args, unsigned long));
	else if (*format == 'X')
		i += ft_print_hexa_high(va_arg(args, unsigned long));
	return (i);
}

int	ft_printf(const char *input, ...)
{
	va_list			args;
	unsigned int	i;

	i = 0;
	va_start(args, input);
	while (*input != '\0')
	{
		if (*input == '%')
		{
			input++;
			if (ft_strchr("cspdiuxX", *input))
				i += ft_format_type(input, args);
			else if (*input == '%')
				i += ft_print_char('%');
		}
		else
			i += ft_print_char(*input);
		input++;
	}
	va_end(args);
	return (i);
}
