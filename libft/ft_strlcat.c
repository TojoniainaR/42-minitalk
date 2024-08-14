/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: torandri <torandri@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 11:08:39 by torandri          #+#    #+#             */
/*   Updated: 2024/02/29 15:28:13 by torandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (i < size && dst[i])
		i++;
	j = i;
	while (i + 1 < size && src[i - j])
	{
		dst[i] = src [i - j];
		i++;
	}
	if (j < size)
		dst[i] = '\0';
	while (src[i - j])
		i++;
	return (i);
}
