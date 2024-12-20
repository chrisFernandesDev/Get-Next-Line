/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmaciel- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 10:53:49 by cmaciel-          #+#    #+#             */
/*   Updated: 2024/12/20 10:53:49 by cmaciel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# ifndef OPEN_SIZE
#  define OPEN_SIZE 1024
# endif

int		ft_strlen(char *str);
int		ft_find_newline(const char *str);

char	*ft_strjoin(char const *s1, char const *s2);
char	*get_next_line(int fd);

void	*ft_calloc(size_t count, size_t size);

#endif