/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkari <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 18:33:21 by pkari             #+#    #+#             */
/*   Updated: 2022/04/01 18:33:23 by pkari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	check_position(t_all *all, int i, int j)
{
	if (i == 0 || j == 0)
		ft_error("Error: invalid map", all);
	if (!(all->map.map[i - 1][j]) || !(all->map.map[i][j - 1])
		|| !(all->map.map[i + 1][j]) || !(all->map.map[i][j + 1]))
		ft_error("Error: invalid map", all);
	if (all->map.map[i - 1][j] != '1' && all->map.map[i - 1][j] != '0')
		ft_error("Error: invalid map", all);
	if (all->map.map[i][j - 1] != '1' && all->map.map[i][j - 1] != '0')
		ft_error("Error: invalid map", all);
	if (all->map.map[i + 1][j] != '1' && all->map.map[i + 1][j] != '0')
		ft_error("Error: invalid map", all);
	if (all->map.map[i][j + 1] != '1' && all->map.map[i][j + 1] != '0')
		ft_error("Error: invalid map", all);
}

void	check_map_close(t_all *all)
{
	int	i;
	int	j;

	i = 0;
	while (all->map.map[i])
	{
		j = 0;
		while (all->map.map[i][j])
		{
			if (all->map.map[i][j] == '0')
				check_position(all, i, j);
			j++;
		}
		i++;
	}
}

int	check_line(char *line, int n)
{
	while (line[n])
	{
		if (line[n] != '1' && line[n] != '0' && line[n] != 'N'
			&& line[n] != 'S' && line[n] != 'W' && line[n] != 'E'
			&& !ft_isspace(line[n]))
			return (0);
		n++;
	}
	return (1);
}

void	pars_map(t_all *all, char *line, int n)
{
	char	**tmp;
	int		i;

	i = -1;
	all->map.height++;
	tmp = (char **)malloc(sizeof(char *) * (all->map.height + 1));
	if (!tmp)
		ft_error("Error: malloc fail", all);
	tmp[all->map.height] = NULL;
	while (++i < (all->map.height - 1))
		tmp[i] = ft_strdup(all->map.map[i]);
	if (check_line(line, n))
		tmp[i] = ft_strdup(line);
	else
	{
		tmp[i] = NULL;
		free_tmp(tmp);
		ft_error("Error: invalid map", all);
	}
	if (all->map.height > 1)
		free_tmp(all->map.map);
	all->map.map = tmp;
}
