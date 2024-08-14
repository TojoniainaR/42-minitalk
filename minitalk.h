/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: torandri <torandri@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 15:36:43 by torandri          #+#    #+#             */
/*   Updated: 2024/08/13 14:23:00 by torandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "./libft/libft.h"
# include "./printf/ft_printf.h"
# include "./gnl/get_next_line.h"
# include "./gnl/get_next_line_bonus.h"
# include <unistd.h>
# include <signal.h>

int		str_is_not_number(char *str);
int		ft_check_error(int pid, char **argv);

#endif
