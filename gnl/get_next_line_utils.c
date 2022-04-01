/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkari <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 17:26:13 by pkari             #+#    #+#             */
/*   Updated: 2022/04/01 17:26:16 by pkari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_gnl_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_gnl_strdup(const char *s1)
{
	int		i;
	int		n;
	char	*str;

	i = 0;
	n = 0;
	while (s1[i] != '\0')
		i++;
	str = (char *)malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	while (s1[n] != '\0')
	{
		str[n] = s1[n];
		n++;
	}
	str[n] = '\0';
	return (str);
}

char	*ft_gnl_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;

	if (!s)
		return (NULL);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (i < len)
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_gnl_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*strnew;
	int		n;

	if (!s1)
		return (ft_gnl_strdup(s2));
	if (!s2)
		return (NULL);
	i = ft_gnl_strlen(s1);
	j = ft_gnl_strlen(s2);
	strnew = (char *)malloc(sizeof(char) * (i + j + 1));
	if (!strnew)
		return (NULL);
	n = -1;
	while (s1[++n])
		strnew[n] = s1[n];
	free(s1);
	s1 = NULL;
	n = -1;
	while (s2[++n] != '\0')
		strnew[n + i] = s2[n];
	strnew[i + n] = '\0';
	return (strnew);
}
