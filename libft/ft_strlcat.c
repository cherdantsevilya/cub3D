/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkari <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 18:34:55 by pkari             #+#    #+#             */
/*   Updated: 2022/04/01 18:34:57 by pkari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	k;
	size_t	j;

	i = ft_strlen(dst);
	j = ft_strlen(src);
	k = 0;
	if (i >= size)
		return (j + size);
	else
		j = j + i;
	while (src[k] != '\0' && size - 1 > k + i)
	{
		dst[i + k] = src[k];
		k++;
	}
	dst[i + k] = '\0';
	return (j);
}
