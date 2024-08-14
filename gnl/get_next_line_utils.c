/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: torandri <torandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 09:31:10 by torandri          #+#    #+#             */
/*   Updated: 2024/05/23 10:39:10 by torandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strchr_gnl(char *s, char c)
{
	int	i;

	if (!s)
		return (-1);
	i = 0;
	while (s[i] != '\0')
	{
		if (c == s[i])
			return (i);
		i++;
	}
	return (-1);
}

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	size_t	size;
	char	*result;

	if (!s1 || !s2)
		return (NULL);
	size = ft_strlen_gnl(s1) + ft_strlen_gnl(s2) + 1;
	result = (char *)malloc (sizeof(char) * size);
	if (!result)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i] != '\0')
	{
		result[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
		result[i++] = s2[j++];
	result[i] = '\0';
	return (free(s1), result);
}

char	*ft_strcpy_gnl(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strdup_gnl(char *s)
{
	size_t	i;
	char	*dest;

	i = ft_strlen_gnl(s);
	dest = (char *)malloc((i + 1) * sizeof(char));
	if (!dest)
		return (NULL);
	return (ft_strcpy_gnl(dest, s));
}

char	*ft_substr_gnl(char const *s, unsigned int start, size_t len)
{
	char	*result;
	size_t	i;

	if (!s)
		return (NULL);
	if (start > ft_strlen_gnl(s))
		return (ft_strdup_gnl(""));
	if (len > (ft_strlen_gnl(s) - start))
		len = ft_strlen_gnl(s) - start;
	result = (char *)malloc(len + 1);
	if (!result)
		return (NULL);
	i = 0;
	while (i < len)
	{
		result[i] = s[start];
		start++;
		i++;
	}
	result[i] = '\0';
	return (result);
}
