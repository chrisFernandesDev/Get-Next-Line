/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaciel- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 12:48:58 by cmaciel-          #+#    #+#             */
/*   Updated: 2024/12/09 12:48:58 by cmaciel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
# define BUFFER_SIZE 42
#endif

int	ft_strlen(char *str);
int	ft_find_newline(const char *str);

char	*ft_find_line(int fd, char *buffer);
char	*ft_strjoin(char const *s1, char const *s2);
char	*get_next_line(int fd);
char	*ft_extract_line(char *file);

void	*ft_calloc(size_t count, size_t size);

#endif