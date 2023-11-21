/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escura <escura@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 12:45:32 by escura            #+#    #+#             */
/*   Updated: 2023/11/21 13:07:07 by escura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*get_line(int fd, char *buf, char *total_buffer)
{
	int		read_line;
	char	*temp;

	read_line = 1;
	while (read_line != '\0')
	{
		read_line = read(fd, buf, BUFFER_SIZE);
		if (read_line < 0)
			return (NULL);
		if (read_line == 0)
			break ;
		buf[read_line] = '\0';
		if (total_buffer == NULL)
			total_buffer = ft_strdup("");
		temp = total_buffer;
		total_buffer = ft_strjoin(temp, buf);
		free(temp);
		if (ft_strchr(buf, '\n'))
			break ;
	}
	return (total_buffer);
}

static char	*remove_from_total(char *line)
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
	if (!line || read(fd, buffer, 0) < 0)
	{
		free(total_buffer);
		total_buffer = NULL;
		return (NULL);
	}
	total_buffer = remove_from_total(line);
	return (line);
}
