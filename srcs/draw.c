/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkari <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 18:07:12 by pkari             #+#    #+#             */
/*   Updated: 2022/04/01 18:07:14 by pkari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	draw_pixel(t_all *all, int i, int j, int color)
{
	int	y;
	int	x;

	y = HEIGHT * 0.01 * i;
	while (y < HEIGHT * 0.01 * (i + 1))
	{
		x = HEIGHT * 0.01 * j;
		while (x < HEIGHT * 0.01 * (j + 1))
		{
			pixel_put(all, x + 5, y + 5, color);
			x++;
		}
		y++;
	}
}

void	draw_mini_map(t_all *all)
{
	int	i;
	int	j;

	i = 0;
	while (all->map.map[i])
	{
		j = 0;
		while (all->map.map[i][j])
		{
			if (all->map.map[i][j] == '1')
				draw_pixel(all, i, j, 0xEEEEEE);
			else
			{
				j++;
				continue ;
			}
			j++;
		}
		i++;
	}
	draw_pixel(all, all->plr.pos.y, all->plr.pos.x, 0x27CE06);
}

void	pixel_put(t_all *all, int x, int y, int color)
{
	int	i;

	i = (x * all->mlx.bpp / 8) + (y * all->mlx.line_l);
	all->mlx.addr[i] = (char)(color);
	all->mlx.addr[i + 1] = (char)(color >> 8);
	all->mlx.addr[i + 2] = (char)(color >> 16);
}

void	draw_fc(t_all *all)
{
	int	x;
	int	y;

	x = -1;
	while (++x < WIDTH)
	{
		y = -1;
		while (++y < HEIGHT)
		{
			if (y < HEIGHT / 2)
				pixel_put(all, x, y, all->map.ceiling);
			else
				pixel_put(all, x, y, all->map.floor);
		}
	}
}

int	draw_cub(t_all *all)
{
	draw_fc(all);
	draw_raycasting(all);
	draw_mini_map(all);
	mlx_put_image_to_window(all->mlx.mlx, all->mlx.win, all->mlx.img, 0, 0);
	return (1);
}
