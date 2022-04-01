/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkari <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 17:25:58 by pkari             #+#    #+#             */
/*   Updated: 2022/04/01 17:26:00 by pkari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_gnl_memmove(void *dst, const void *src, size_t n)
{
	unsigned char	*s1;
	unsigned char	*s2;

	s1 = (unsigned char *)dst;
	s2 = (unsigned char *)src;
	if (!dst && !src)
		return (NULL);
	if (s1 < s2)
	{
		while (n--)
			*s1++ = *s2++;
	}
	else
	{
		while (n > 0)
		{
			n--;
			s1[n] = s2[n];
		}
	}
	return (dst);
}

int	ft_check_reminder(char *reminder, char **line, int i)
{
	*line = ft_gnl_substr(reminder, 0, i);
	ft_gnl_memmove(reminder, reminder + i + 1, ft_gnl_strlen
		(reminder + i + 1) + 1);
	return (1);
}

int	ft_find_i(const char *reminder, int c)
{
	int	i;

	i = 0;
	while (reminder[i] && reminder[i] != (char)c)
		i++;
	if (reminder[i] != (char)c)
		return (-1);
	return (i);
}

int	ft_eof(char **line, int br)
{
	*line = ft_gnl_strdup("");
	return (br);
}

int	get_next_line(int fd, char **line)
{
	char			buff[BUFFER_SIZE + 1];
	static char		*reminder;
	int				br;

	br = 1;
	if (read(fd, buff, 0) < 0 || fd < 0 || BUFFER_SIZE < 1 || !line)
		return (-1);
	if (reminder && (ft_find_i(reminder, '\n') != (-1)))
		return (ft_check_reminder(reminder, line, ft_find_i(reminder, '\n')));
	while (br)
	{
		br = read(fd, buff, BUFFER_SIZE);
		buff[br] = '\0';
		reminder = ft_gnl_strjoin(reminder, buff);
		if (ft_find_i(reminder, '\n') != (-1))
			return (ft_check_reminder(reminder, line,
					ft_find_i(reminder, '\n')));
	}
	if (!reminder)
		return (ft_eof(line, br));
	*line = ft_gnl_strdup(reminder);
	free(reminder);
	reminder = NULL;
	return (br);
}
