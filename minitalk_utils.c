/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: torandri <torandri@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 13:31:32 by torandri          #+#    #+#             */
/*   Updated: 2024/08/13 14:53:03 by torandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	str_is_not_number(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (ft_isalpha((unsigned char)str[i]) == 1)
			return (1);
		i++;
	}
	return (0);
}

int	ft_check_error(int pid, char **argv)
{
	if (str_is_not_number(argv[1]) == 1 || pid <= 0)
	{
		ft_putstr_fd("Error\nPID must be numeric\n", 2);
		return (1);
	}
	if (argv[2][0] == '\0')
	{
		ft_putstr_fd("Error\nEmpty message\n", 2);
		return (1);
	}
	return (0);
}
