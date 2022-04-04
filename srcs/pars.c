/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkari <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 18:19:57 by pkari             #+#    #+#             */
/*   Updated: 2022/04/01 18:19:59 by pkari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	check_cub_helper(t_all *all, char *line)
{
	int	n;

	n = 0;
	if (line[0] == 'N' || line[0] == 'S' || line[0] == 'W'
		|| line[0] == 'E')
		check_nswe(all, line);
	if (line[0] == 'F' || line[0] == 'C')
		check_fc(all, line);
	while (ft_isspace(line[n]))
		n++;
	if (line[n] == '1' || line[n] == '0')
		pars_map(all, line, n);
}

void	check_cub(t_all *all, int fd)
{
	int		i;
	char	*line;

	i = 1;
	while (i)
	{
		i = get_next_line(fd, &line);
		if (i == -1)
			ft_error("Error: can't read map", all);
		check_cub_helper(all, line);
		free(line);
		if (i == 0)
			break ;
	}
	if (all->map.north == NULL || all->map.south == NULL
		|| all->map.west == NULL || all->map.east == NULL
		|| all->map.floor == -1 || all->map.ceiling == -1)
		ft_error("Error: NSWE/FC fail", all);
	check_duplicate(all);
	check_map_close(all);
}

void	pars_cub(t_all *all, char *map)
{
	int	fd;

	if (ft_strncmp(map + ft_strlen(map) - 4, ".cub", 4))
		ft_error("Error: the map should look like *.cub", all);
	fd = open(map, O_RDONLY);
	if (fd == -1)
		ft_error("Error: can't open map", all);
	init_mlx(all);
	check_cub(all, fd);
	close(fd);
}
