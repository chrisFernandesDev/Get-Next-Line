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

	line_tmp = (char *)ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!line_tmp)
		return (NULL);
	byte_read = 1;
	while (byte_read > 0 && ft_find_newline(buffer) == 0)
	{
		byte_read = read(fd, line_tmp, BUFFER_SIZE);
		if (byte_read < 0)
			return (free(line_tmp), free(buffer), NULL);
		line_tmp[byte_read] = '\0';
		line_res = ft_strjoin(buffer, line_tmp);
		if (!line_res)
			return (free(line_tmp), free(buffer), NULL);
		free(buffer);
		buffer = line_res;
	}
	free(line_tmp);
	return (buffer);
}

char	*ft_extract_line(char *buffer)
{
	char	*new_line;
	int		i;

	if (!buffer || buffer[0] == '\0')
		return (NULL);
	i = 0;
	while (buffer[i] != '\n' && buffer[i] != '\0')
		i++;
	new_line = (char *)ft_calloc(i + 2, sizeof(char));
	if (!new_line)
		return (NULL);
	i = 0;
	while (buffer[i] != '\n' && buffer[i] != '\0')
	{
		new_line[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
		new_line[i++] = '\n';
	new_line[i] = '\0';
	return (new_line);
}

char	*ft_read_line(char *buffer)
{
	char	*remainder;
	int		i;
	int		j;

	if (!buffer)
		return (NULL);
	i = 0;
	while (buffer[i] != '\n' && buffer[i] != '\0')
		i++;
	if (buffer[i] == '\0')
		return (free(buffer), NULL);
	remainder = (char *)ft_calloc(ft_strlen(buffer) - i, sizeof(char));
	if (!remainder)
		return (free(buffer), NULL);
	i++;
	j = 0;
	while (buffer[i] != '\0')
		remainder[j++] = buffer[i++];
	remainder[j] = '\0';
	free(buffer);
	return (remainder);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!buffer)
	{
		buffer = ft_calloc(1, sizeof(char));
		if (!buffer)
			return (NULL);
	}
	buffer = ft_find_line(fd, buffer);
	if (!buffer)
		return (NULL);
	line = ft_extract_line(buffer);
	buffer = ft_read_line(buffer);
	if (!line)
		return (free(buffer), NULL);
	return (line);
}
/*
int	main(void)
{
	int fd = open("text.txt", O_RDONLY);
	char	*line;
	//char	*line1;
	//char	*line2;

	line = get_next_line(fd);
	//line1 = get_next_line(fd);
	//line2 = get_next_line(fd);

	printf("%s", line);
	//printf("%s", line1);
	//printf("%s", line2);

	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
		free(line);
	}
	free(line);
	//free(line1);
	//free(line2);
	close(fd);
	return (0);
}
*/