/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaciel- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 12:48:46 by cmaciel-          #+#    #+#             */
/*   Updated: 2024/12/09 12:48:46 by cmaciel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_find_line(int fd, char *buffer)
{
	char	*line_tmp;
	char	*line_res;
	ssize_t	byte_read;

	byte_read = 1;
	line_tmp = (char *)ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!line_tmp)
		return (NULL);
	while (byte_read != 0 && ft_find_newline(buffer) == 0)
	{
		line_tmp = (char *)ft_calloc(BUFFER_SIZE + 1, sizeof(char));
		if (!line_tmp)
			return (NULL);
		byte_read = read(fd, line_tmp, BUFFER_SIZE);
		if (byte_read == -1)
			return (free(line_tmp), free(buffer), NULL);
		line_res = ft_strjoin(buffer, line_tmp);
		if (!line_res)
			return (free(line_tmp), NULL);
		free(buffer);
		buffer = line_res;
	}
	if (ft_find_newline(buffer) == 1)
		buffer = ft_extract_line(buffer);
	return (buffer);
}

char	*ft_extract_line(char *file)
{
	char	*new_line;
	int		i;

	if (!file || file[0] == '\0')
		return (NULL);
	i = 0;
	while (file[i] != '\n' && file[i] != '\0')
		i++;
	new_line = (char *)ft_calloc(i + 2, sizeof(char));
	if (!new_line)
		return NULL;
	i = 0;
	while (file[i] != '\n' && file[i] != '\0')
	{
		new_line[i] = file[i];
		i++;
	}
	if (file[i] == '\n')
		new_line[i++] = '\n';
	new_line[i] = '\0';
	return (new_line);
}

char *get_next_line(int fd)
{
	static char	*buffer;
	char	*file;
	ssize_t	bytes_read;

	//TO DO
	return (file);
}
