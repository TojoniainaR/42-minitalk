/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: torandri <torandri@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 15:16:59 by torandri          #+#    #+#             */
/*   Updated: 2024/06/01 17:33:12 by torandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_size(long n)
{
	size_t	size;

	size = 0;
	if (n < 0)
	{
		size++;
		n *= -1;
	}
	if (n == 0)
		size++;
	while (n)
	{
		n /= 10;
		size++;
	}
	return (size);
}

char	*ft_itoa(int n)
{
	size_t	i;
	size_t	size;
	long	nb;
	char	*result;

	nb = (long)n;
	size = count_size(nb);
	result = (char *)malloc(sizeof(char) * (size + 1));
	if (!result)
		return (NULL);
	i = 0;
	if (nb < 0)
	{
		result[0] = '-';
		nb *= -1;
		i = 1;
	}
	result[size] = '\0';
	while (size > i)
	{
		result[size - 1] = ((nb % 10) + '0');
		nb /= 10;
		size--;
	}
	return (result);
}
