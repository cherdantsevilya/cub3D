/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkari <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 18:18:08 by pkari             #+#    #+#             */
/*   Updated: 2022/04/01 18:18:09 by pkari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	init_cub(t_all *all)
{
	all->mlx.mlx = NULL;
	all->mlx.win = NULL;
	all->mlx.img = NULL;
	all->mlx.addr = NULL;
	all->mlx.bpp = 0;
	all->mlx.line_l = 0;
	all->mlx.end = 0;
	all->map.map = NULL;
	all->map.height = 0;
	all->map.north = NULL;
	all->map.south = NULL;
	all->map.west = NULL;
	all->map.east = NULL;
	all->map.floor = -1;
	all->map.ceiling = -1;
	all->plr.pos.x = 0;
	all->plr.pos.y = 0;
	all->plr.dir.x = 0;
	all->plr.dir.y = 0;
	all->ray.plane.x = 0;
	all->ray.plane.y = 0;
}

void	init_mlx(t_all *all)
{
	all->mlx.mlx = mlx_init();
	if (!all->mlx.mlx)
		ft_error("Error: mlx_init", all);
	all->mlx.win = mlx_new_window(all->mlx.mlx, WIDTH, HEIGHT, "cub3D");
	if (!all->mlx.win)
		ft_error("Error: mlx_new_window", all);
	all->mlx.img = mlx_new_image(all->mlx.mlx, WIDTH, HEIGHT);
	if (!all->mlx.img)
		ft_error("Error: mlx_new_image", all);
	all->mlx.addr = mlx_get_data_addr(all->mlx.img, &(all->mlx.bpp),
			&(all->mlx.line_l), &(all->mlx.end));
	if (!all->mlx.addr)
		ft_error("Error: mlx_get_data_addr", all);
}
