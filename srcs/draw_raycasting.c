/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_raycasting.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkari <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 18:07:48 by pkari             #+#    #+#             */
/*   Updated: 2022/04/01 18:07:50 by pkari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	calculations(t_all *all)
{
	if (all->ray.side == 0)
		all->ray.walldist = (all->ray.sd.x - all->ray.dd.x);
	else
		all->ray.walldist = (all->ray.sd.y - all->ray.dd.y);
	all->ray.height = (int)(HEIGHT / all->ray.walldist);
	all->ray.start = (-(all->ray.height) / 2 + HEIGHT / 2);
	if (all->ray.start < 0)
		all->ray.start = 0;
	all->ray.end = (all->ray.height / 2 + HEIGHT / 2);
	if (all->ray.end >= HEIGHT)
		all->ray.end = (HEIGHT - 1);
}

void	dda(t_all *all)
{
	while (all->ray.hit == 0)
	{
		if (all->ray.sd.x < all->ray.sd.y)
		{
			all->ray.sd.x += all->ray.dd.x;
			all->map.x += all->ray.step_x;
			all->ray.side = 0;
		}
		else
		{
			all->ray.sd.y += all->ray.dd.y;
			all->map.y += all->ray.step_y;
			all->ray.side = 1;
		}
		if (all->map.map[(int)(all->map.y)][(int)(all->map.x)] == '1')
			all->ray.hit = 1;
	}
}

void	pre_raycasting(t_all *all, int x)
{
	all->ray.camera_x = (2.0 * x / (double)(WIDTH) - 1.0);
	all->ray.raydir.x = all->plr.dir.x + all->ray.plane.x * all->ray.camera_x;
	all->ray.raydir.y = all->plr.dir.y + all->ray.plane.y * all->ray.camera_x;
	all->map.x = (int)(all->plr.pos.x);
	all->map.y = (int)(all->plr.pos.y);
	all->ray.dd.x = fabs(1.0 / all->ray.raydir.x);
	all->ray.dd.y = fabs(1.0 / all->ray.raydir.y);
	all->ray.hit = 0;
	all->ray.step_x = 1;
	all->ray.sd.x = (all->map.x + 1.0 - all->plr.pos.x) * all->ray.dd.x;
	all->ray.step_y = 1;
	all->ray.sd.y = (all->map.y + 1.0 - all->plr.pos.y) * all->ray.dd.y;
	if (all->ray.raydir.x < 0)
	{
		all->ray.step_x = -1;
		all->ray.sd.x = (all->plr.pos.x - all->map.x) * all->ray.dd.x;
	}
	if (all->ray.raydir.y < 0)
	{
		all->ray.step_y = -1;
		all->ray.sd.y = (all->plr.pos.y - all->map.y) * all->ray.dd.y;
	}
}

void	draw_raycasting(t_all *all)
{
	int	x;

	x = -1;
	while (++x < WIDTH)
	{
		pre_raycasting(all, x);
		dda(all);
		calculations(all);
		textures(all, x);
	}
}
