/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_check_NSWE.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkari <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 18:24:36 by pkari             #+#    #+#             */
/*   Updated: 2022/04/01 18:24:39 by pkari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	set_position(t_all *all, int nswe, double i, double j)
{
	all->plr.pos.x = j;
	all->plr.pos.y = i;
	if (nswe == 'N')
	{
		all->plr.dir.y = -1;
		all->ray.plane.x = 0.66;
	}
	else if (nswe == 'S')
	{
		all->plr.dir.y = 1;
		all->ray.plane.x = -0.66;
	}
	else if (nswe == 'W')
	{
		all->plr.dir.x = -1;
		all->ray.plane.y = -0.66;
	}
	else if (nswe == 'E')
	{
		all->plr.dir.x = 1;
		all->ray.plane.y = 0.66;
	}
}

void	check_duplicate(t_all *all)
{
	double	i;
	double	j;
	int		count;
	int		nswe;

	count = 0;
	i = -1;
	while (all->map.map[(int)++i])
	{
		j = -1;
		while (all->map.map[(int)i][(int)++j])
		{
			nswe = all->map.map[(int)i][(int)j];
			if (nswe == 'N' || nswe == 'S' || nswe == 'W' || nswe == 'E')
			{
				count++;
				if (count == 2)
					ft_error("Error: find duplicate", all);
				set_position(all, nswe, i, j);
				all->map.map[(int)i][(int)j] = '0';
			}
		}
	}
	if (count == 0)
		ft_error("Error: find duplicate", all);
}

void	*texture_xpm(t_all *all, char *line)
{
	int		i;
	int		x;
	int		y;
	void	*img;
	char	*adr;

	i = 0;
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	if (line[i] == '.' || line[i] == '/')
	{
		img = mlx_xpm_file_to_image(all->mlx.mlx, line + i, &x, &y);
		if (img == NULL || x != 64 || y != 64)
			ft_error("Error: wrong xpm file", all);
		adr = mlx_get_data_addr(img, &x, &y, &i);
		return (adr);
	}
	ft_error("Error: wrong texture file", all);
	return (NULL);
}

void	check_nswe(t_all *all, char *line)
{
	if ((ft_strncmp(line, "NO ", 3) == 0) && all->map.north == NULL)
		all->map.north = texture_xpm(all, line + 3);
	else if ((ft_strncmp(line, "SO ", 3) == 0) && all->map.south == NULL)
		all->map.south = texture_xpm(all, line + 3);
	else if ((ft_strncmp(line, "WE ", 3) == 0) && all->map.west == NULL)
		all->map.west = texture_xpm(all, line + 3);
	else if ((ft_strncmp(line, "EA ", 3) == 0) && all->map.east == NULL)
		all->map.east = texture_xpm(all, line + 3);
	else
		ft_error("Error: textures NO/SO/WE/EA not found", all);
}
