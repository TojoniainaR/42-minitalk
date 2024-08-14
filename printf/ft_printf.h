/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: torandri <torandri@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 12:04:35 by torandri          #+#    #+#             */
/*   Updated: 2024/04/09 12:49:31 by torandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int	ft_print_char(char c);
int	ft_print_str(char *str);
int	ft_print_pointer(void *input);
int	ft_print_int(int nb);
int	ft_print_unsd(unsigned int nbr);
int	ft_print_hexa_low(unsigned long nb);
int	ft_print_hexa_high(unsigned long nb);
int	ft_printf(const char *input, ...);

#endif
