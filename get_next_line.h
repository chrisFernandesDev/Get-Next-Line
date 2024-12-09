#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>

# define BUFFER_ERROR "Buffer is empty\n"
# define SIZE_ERROR "Size is empty\n"
# define FD_ERROR "Cannot read file.\n"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1
#endif

int	ft_strlen(char *str);
int	ft_find_newline(const char *str);
int	read_to_buffer(int fd, char *buffer, size_t size);

char	*ft_strjoin(char const *s1, char const *s2);
char	*get_next_line(int fd);
char	*ft_extract_line(char *file);

void	*ft_calloc(size_t count, size_t size);

#endif