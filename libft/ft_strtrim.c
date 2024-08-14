/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: torandri <torandri@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 12:00:31 by torandri          #+#    #+#             */
/*   Updated: 2024/03/08 15:00:49 by torandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	len_s1;

	if (!s1 || !set)
		return (NULL);
	i = 0;
	while (s1[i] && ft_strchr(set, s1[i]))
		i++;
	if (i >= ft_strlen(s1))
		return (ft_strdup(""));
	len_s1 = ft_strlen(s1);
	while (len_s1 > i && ft_strchr(set, s1[len_s1]))
		len_s1--;
	return (ft_substr(s1, i, len_s1 - i + 1));
}
