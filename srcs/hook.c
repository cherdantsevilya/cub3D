/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkari <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 18:08:11 by pkari             #+#    #+#             */
/*   Updated: 2022/04/01 18:10:33 by pkari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	key_hook_lr(int key, t_all *all)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = all->plr.dir.x;
	old_plane_x = all->ray.plane.x;
	if (key == LEFT)
	{
		all->plr.dir.x = all->plr.dir.x * cos(-SR) - all->plr.dir.y * sin(-SR);
		all->plr.dir.y = old_dir_x * sin(-SR) + all->plr.dir.y * cos(-SR);
		all->ray.plane.x = all->ray.plane.x * cos(-SR)
			- all->ray.plane.y * sin(-SR);
		all->ray.plane.y = old_plane_x * sin(-SR) + all->ray.plane.y * cos(-SR);
	}
	if (key == RIGHT)
	{
		all->plr.dir.x = all->plr.dir.x * cos(SR) - all->plr.dir.y * sin(SR);
		all->plr.dir.y = old_dir_x * sin(SR) + all->plr.dir.y * cos(SR);
		all->ray.plane.x = all->ray.plane.x * cos(SR)
			- all->ray.plane.y * sin(SR);
		all->ray.plane.y = old_plane_x * sin(SR) + all->ray.plane.y * cos(SR);
	}
}

void	key_hook_ad(int key, t_all *all)
{
	if (key == A)
	{
		if (all->map.map[(int)(all->plr.pos.y)]
			[(int)(all->plr.pos.x - all->ray.plane.x * SM)] == '0')
			all->plr.pos.x -= all->ray.plane.x * SM;
		if (all->map.map[(int)(all->plr.pos.y - all->ray.plane.y * SM)]
			[(int)(all->plr.pos.x)] == '0')
			all->plr.pos.y -= all->ray.plane.y * SM;
	}
	if (key == D)
	{
		if (all->map.map[(int)(all->plr.pos.y)]
			[(int)(all->plr.pos.x + all->ray.plane.x * SM)] == '0')
			all->plr.pos.x += all->ray.plane.x * SM;
		if (all->map.map[(int)(all->plr.pos.y + all->ray.plane.y * SM)]
			[(int)(all->plr.pos.x)] == '0')
			all->plr.pos.y += all->ray.plane.y * SM;
	}
}

void	key_hook_ws(int key, t_all *all)
{
	if (key == W)
	{
		if (all->map.map[(int)(all->plr.pos.y)]
			[(int)(all->plr.pos.x + all->plr.dir.x * SM)] == '0')
			all->plr.pos.x += all->plr.dir.x * SM;
		if (all->map.map[(int)(all->plr.pos.y + all->plr.dir.y * SM)]
			[(int)(all->plr.pos.x)] == '0')
			all->plr.pos.y += all->plr.dir.y * SM;
	}
	if (key == S)
	{
		if (all->map.map[(int)(all->plr.pos.y)]
			[(int)(all->plr.pos.x - all->plr.dir.x * SM)] == '0')
			all->plr.pos.x -= all->plr.dir.x * SM;
		if (all->map.map[(int)(all->plr.pos.y - all->plr.dir.y * SM)]
			[(int)(all->plr.pos.x)] == '0')
			all->plr.pos.y -= all->plr.dir.y * SM;
	}
}

int	exit_hook(t_all *all)
{
	free_all(all);
	exit(EXIT_SUCCESS);
}

int	key_hook(int key, t_all *all)
{
	if (key == ESC)
		exit_hook(all);
	else if (key == W || key == S)
		key_hook_ws(key, all);
	else if (key == A || key == D)
		key_hook_ad(key, all);
	else if (key == LEFT || key == RIGHT)
		key_hook_lr(key, all);
	return (1);
}
