/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkari <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 17:26:43 by pkari             #+#    #+#             */
/*   Updated: 2022/04/01 17:26:46 by pkari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

int		get_next_line(int fd, char **line);
int		ft_find_i(const char *reminder, int c);
int		ft_check_reminder(char *reminder, char **line, int i);
void	*ft_gnl_memmove(void *dst, const void *src, size_t n);
size_t	ft_gnl_strlen(const char *s);
char	*ft_gnl_strdup(const char *s1);
char	*ft_gnl_substr(char const *s, unsigned int start, size_t len);
char	*ft_gnl_strjoin(char *s1, char *s2);

#endif
