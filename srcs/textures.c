/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkari <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 18:34:03 by pkari             #+#    #+#             */
/*   Updated: 2022/04/01 18:34:05 by pkari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	pre_processing(t_all *all)
{
	double	wall_x;

	if (all->ray.side == 0)
		wall_x = all->plr.pos.y + all->ray.walldist * all->ray.raydir.y;
	else
		wall_x = all->plr.pos.x + all->ray.walldist * all->ray.raydir.x;
	wall_x -= floor(wall_x);
	all->wall.tex_x = (int)(wall_x * (double)(64));
	if (all->ray.side == 0 && all->ray.raydir.x > 0)
		all->wall.tex_x = 64 - all->wall.tex_x - 1;
	if (all->ray.side == 1 && all->ray.raydir.y < 0)
		all->wall.tex_x = 64 - all->wall.tex_x - 1;
	all->wall.step = 1.0 * 64 / all->ray.height;
	all->wall.tex_pos = (all->ray.start - HEIGHT / 2 + all->ray.height / 2)
		* all->wall.step;
}

int	texturing(t_all *all, unsigned int *color)
{
	if (all->ray.side == 0)
	{
		if (all->ray.raydir.x >= 0)
			*color = ((unsigned int *)(all->map.east))
			[64 * all->wall.tex_y + all->wall.tex_x];
		else
			*color = ((unsigned int *)(all->map.west))
			[64 * all->wall.tex_y + all->wall.tex_x];
	}
	else if (all->ray.side == 1)
	{
		if (all->ray.raydir.y >= 0)
			*color = ((unsigned int *)(all->map.south))
			[64 * all->wall.tex_y + all->wall.tex_x];
		else
			*color = ((unsigned int *)(all->map.north))
			[64 * all->wall.tex_y + all->wall.tex_x];
	}
	return (*color);
}

void	textures(t_all *all, int x)
{
	int				y;
	unsigned int	color;

	pre_processing(all);
	y = all->ray.start;
	while (y <= all->ray.end)
	{
		all->wall.tex_y = (int)all->wall.tex_pos & (64 - 1);
		all->wall.tex_pos += all->wall.step;
		color = texturing(all, &color);
		pixel_put(all, x, y, color);
		y++;
	}
}
