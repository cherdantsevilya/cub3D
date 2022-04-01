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

#include "../includes/cub3D.h"

void	free_all(t_all *all)
{
	if (all->map.map)
		free_tmp(all->map.map);
	if (all->map.north)
		free(all->map.north);
	if (all->map.south)
		free(all->map.south);
	if (all->map.west)
		free(all->map.west);
	if (all->map.east)
		free(all->map.east);
	if (all->mlx.img)
		mlx_destroy_image(all->mlx.mlx, all->mlx.img);
	if (all->mlx.win)
		mlx_destroy_window(all->mlx.mlx, all->mlx.win);
}

void	free_tmp(char **arr)
{
	int	i;

	i = 0;
	if (arr)
	{
		while (arr[i])
			free(arr[i++]);
		free(arr);
		arr = NULL;
	}
}
