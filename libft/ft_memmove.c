/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: torandri <torandri@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 15:15:50 by torandri          #+#    #+#             */
/*   Updated: 2024/02/29 14:46:36 by torandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*tmp_src;
	unsigned char	*tmp_dest;

	i = 0;
	tmp_src = (unsigned char *)src;
	tmp_dest = (unsigned char *)dest;
	if (!tmp_src && !tmp_dest)
		return (NULL);
	if (dest < src)
	{
		while (i < n)
		{
			tmp_dest[i] = tmp_src[i];
			i++;
		}
	}
	else
	{
		while (i < n--)
			tmp_dest[n] = tmp_src[n];
	}
	return (dest);
}
