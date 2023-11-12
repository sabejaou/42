/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbejaoui <sbejaoui@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 13:41:44 by sbejaoui          #+#    #+#             */
/*   Updated: 2021/11/24 01:22:09 by sbejaoui         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "gnl.h"

char	*ft_strcat(char *dest, char *src, int size)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	while (dest[i] != '\0')
		i++;
	while ((src[j] != '\0' && size == -1) || j <= size)
		dest[i++] = src[j++];
	dest[i] = '\0';
	while (src[j])
		src[k++] = src[j++];
	while (src[k])
		src[k++] = 0;
	dest[i] = '\0';
	return (dest);
}

int	ft_beginning(char **line, char *buffer, int fd, int *i)
{
	size_t	okou;

	okou = 0;
	if (!buffer[0])
	{
		*i = read(fd, buffer, BUFFER_SIZE);
		buffer[BUFFER_SIZE] = '\0';
	}
	else
	{
		okou = ft_strclen(buffer);
		if (ft_strichr(buffer, '\n') != -1)
			okou = ft_strichr(buffer, '\n');
		*line = ft_strealloc(*line, okou);
		if (!(*line))
			return (-1);
		ft_strcat(*line, buffer, okou);
	}
	return (0);
}

void	*ft_end(char **line, char *buffer, int *i)
{
	int	okou;

	okou = 0;
	okou = ft_strichr(buffer, '\n');
	if (i == 0)
		okou = ft_strichr(buffer, '\0');
	*line = ft_strealloc(*line, okou);
	if (!(*line))
		return (NULL);
	ft_strcat(*line, buffer, okou);
	return (*line);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;
	int			i;

	i = 1;
	line = NULL;
	while (i && fd >= 0 && BUFFER_SIZE >= 1 && fd < OPEN_MAX && !read(fd, 0, 0))
	{
		if ((ft_beginning(&line, buffer, fd, &i)) == -1)
			return (NULL);
		if (ft_strichr(line, '\n') != -1)
			return (line);
		if (ft_strichr(buffer, '\n') == -1 && buffer[0])
		{
			line = ft_strealloc(line, BUFFER_SIZE);
			if (!line)
				return (NULL);
			ft_strcat(line, buffer, -1);
		}
		if (!buffer[0] && i == 0)
			return (line);
		else if (buffer[0] || i == 0)
			return (ft_end(&line, buffer, &i));
	}
	return (NULL);
}
