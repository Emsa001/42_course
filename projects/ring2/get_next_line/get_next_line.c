/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escura <escura@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 15:12:40 by escura            #+#    #+#             */
/*   Updated: 2023/11/20 17:39:31 by escura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*get_line(int fd, char *buf, char *total_buffer)
{
	int		read_line;
	char	*char_temp;

	read_line = 1;
	while (read_line != '\0')
	{
		read_line = read(fd, buf, BUFFER_SIZE);
		if (read_line == -1)
			return (NULL);
		else if (read_line == 0)
			break ;
		buf[read_line] = '\0';
		if (!total_buffer)
			total_buffer = ft_strdup("");
		char_temp = total_buffer;
		total_buffer = ft_strjoin(char_temp, buf);
		free(char_temp);
		char_temp = NULL;
		if (ft_strchr(buf, '\n'))
			break ;
	}
	return (total_buffer);
}

static char	*extract(char *line)
{
	size_t	count;
	char	*total_buffer;

	count = 0;
	while (line[count] != '\n' && line[count] != '\0')
		count++;
	if (line[count] == '\0')
		return (NULL);
	total_buffer = ft_substr(line, count + 1, ft_strlen(line) - count);
	if (*total_buffer == '\0')
	{
		free(total_buffer);
		return (NULL);
	}
	line[count + 1] = '\0';
	return (total_buffer);
}

char	*get_next_line(int fd)
{
	char		*line;
	char		*buffer;
	static char	*total_buffer;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	line = get_line(fd, buffer, total_buffer);
	free(buffer);
	buffer = NULL;
	if (!line || read(fd, buffer, 0) == -1)
	{
		free(total_buffer);
		total_buffer = NULL;
		return (NULL);
	}
	total_buffer = extract(line);
	return (line);
}
