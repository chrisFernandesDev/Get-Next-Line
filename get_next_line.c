#include "get_next_line.h"

int read_to_buffer(int fd, char *buffer, size_t size)
{
	int	bytes_read;

	if (!buffer)
	{
		write(2, BUFFER_ERROR, ft_strlen(BUFFER_ERROR));
		return (-1);
	}
	if (size == 0)
	{
		write(2, SIZE_ERROR, ft_strlen(SIZE_ERROR));
		return (0);
	}
	if (fd < 0)
	{
		write(2, FD_ERROR, ft_strlen(FD_ERROR));
		return (-1);
	}
	//Rever a recursiva
	//bytes_read = read(fd, buffer, size);
	bytes_read = read_to_buffer(fd, buffer, size);
	if (bytes_read > 0)
		return (bytes_read);
	else if (bytes_read == 0)
		return (0);
	return (-1);
}

char	*ft_extract_line(char *file)
{
	char	*new_line;
	int		i;

	if (!file || file[0] == '\0')
		return (NULL);
	i = 0;
	while (file[i] != ft_find_newline(file) && file[i] != '\0')
		i++;
	new_line = (char *)ft_calloc(ft_strlen(file) + 1, sizeof(char));
	if (!new_line)
		return NULL;
	i = 0;
	while (file[i] != ft_find_newline(file) && file[i] != '\0')
	{
		new_line[i] = file[i];
		i++;
	}
	new_line[i] = '\0';
	return new_line;
}

char *get_next_line(int fd)
{
	static char	*temp;
	char	*temp_pr;
	char	*new_line;
	char	*filename;
	int	bytes_read;

	filename = (char *)ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!filename)
		return (NULL);
	bytes_read = read_to_buffer(fd, filename, BUFFER_SIZE);
	if (bytes_read <= 0)
	{
		free(filename);
		return (NULL);
	}
	if (temp)
	{
		temp_pr = ft_strjoin(temp, filename);
		free(temp);
		temp = temp_pr;
	}
	else
		temp = filename;
	new_line = ft_extract_line(temp);
	if (!new_line)
	{
		free(new_line);
		return (NULL);
	}
	temp_pr = temp + ft_strlen(new_line);
	free(temp);
	temp = temp_pr;
	return (new_line);
}
