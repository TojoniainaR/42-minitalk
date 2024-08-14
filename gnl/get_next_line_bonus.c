/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: torandri <torandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 13:25:01 by torandri          #+#    #+#             */
/*   Updated: 2024/05/18 11:22:36 by torandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen_gnl_bonus(const char *str)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_read(int fd, char *rest)
{
	char	*buffer;
	int		bytes_read;

	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	while ((ft_strchr_gnl_bonus(rest, '\n') < 0))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
			return (free(buffer), free(rest), NULL);
		if (bytes_read == 0)
			break ;
		buffer[bytes_read] = '\0';
		if (rest == NULL)
			rest = ft_strdup_gnl_bonus("");
		rest = ft_strjoin_gnl_bonus(rest, buffer);
	}
	free(buffer);
	return (rest);
}

char	*ft_get_line(char *rest)
{
	int		i;
	char	*line;

	if (!rest || rest[0] == '\0')
		return (NULL);
	i = 0;
	while (rest[i] != '\0' && rest[i] != '\n')
		i++;
	line = ft_substr_gnl_bonus(rest, 0, i + 1);
	if (!line)
		return (NULL);
	return (line);
}

char	*ft_get_rest(char *buf, char *line)
{
	int		i;
	int		j;
	char	*rest;

	i = 0;
	j = 0;
	if (!line)
	{
		if (buf)
			free(buf);
		return (NULL);
	}
	while (buf[i] != '\0' && buf[i] != '\n')
		i++;
	if (buf[i] == '\0')
		return (free(buf), NULL);
	else
		i++;
	rest = (char *)malloc((ft_strlen_gnl_bonus(buf) - i + 1) * sizeof(char));
	j = 0;
	while (buf[i] != '\0')
		rest[j++] = buf[i++];
	rest[j] = '\0';
	free(buf);
	return (rest);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*rest[1024];

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	rest[fd] = ft_read(fd, rest[fd]);
	if (rest[fd] == NULL)
		return (NULL);
	line = ft_get_line(rest[fd]);
	rest[fd] = ft_get_rest(rest[fd], line);
	return (line);
}
