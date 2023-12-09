/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escura <escura@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 12:45:32 by escura            #+#    #+#             */
/*   Updated: 2023/12/09 14:27:43 by escura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
**
** Description:
**   Reads lines from the given file descriptor (fd) and accumulates them in
**   a dynamic buffer (total_buffer). Uses a buffer (buf) to read lines
**   incrementally.
**
** Parameters:
**   fd:            The file descriptor to read from.
**   buf:           A buffer to store the content of each read.
**   total_buffer:  A cumulative buffer for storing all lines read so far.
**
** Returns:
**   total_buffer:  A dynamically allocated string containing all lines read
**                  from the file descriptor, or NULL in case of an error.
*/
static char	*get_line(int fd, char *buffer, char *total_buffer)
{
	int		read_line;
	char	*temp;

	read_line = 1;
	while (read_line != '\0')
	{
		read_line = read(fd, buffer, BUFFER_SIZE);
		if (read_line < 0)
			return (NULL);
		if (read_line == 0)
			break ;
		buffer[read_line] = '\0';
		if (total_buffer == NULL)
			total_buffer = ft_strdup("");
		temp = total_buffer;
		total_buffer = ft_strjoin(temp, buffer);
		free(temp);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (total_buffer);
}

/*
**
** Description:
**   Removes the part of the line that has already been processed (up to the
**   newline). Returns the remaining unprocessed content of the line
**   and updates the original line to truncate at the newline.
**
** Parameters:
**   line:  The line to process.
**
** Returns:
**   total_buffer:  A dynamically allocated string containing the remaining
**                  unprocessed content of the line, or NULL if no newline
**                  is found.
*/
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

/*
**
** Description:
**   Reads the next line from the given file descriptor (fd) using the
**   get_line function. Manages a static variable (total_buffer) to keep track
**   of total lines. Allocates memory for a buffer (buffer) to read from the
**   file.
**
** Parameters:
**   fd:  The file descriptor to read from.
**
** Returns:
**   line:  A dynamically allocated string containing the next line from the
**          file, or NULL in case of an error or reaching the end of the file.
*/
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
