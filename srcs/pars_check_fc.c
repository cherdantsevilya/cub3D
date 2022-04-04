/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_check_FC.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkari <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 18:22:27 by pkari             #+#    #+#             */
/*   Updated: 2022/04/01 18:22:29 by pkari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	color_atoi(const char *str, t_all *all)
{
	int	i;
	int	flag;
	int	nbr;

	i = 0;
	flag = 1;
	nbr = 0;
	while (str[i] == '\n' || str[i] == '\r' || str[i] == '\t'
		|| str[i] == '\v' || str[i] == '\f' || str[i] == ' '
		|| str[i] == 'C' || str[i] == 'F')
		i++;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			ft_error("Error: wrong color1", all);
		if (str[i] == '0' && str[i + 1] && flag)
			ft_error("Error: wrong color2", all);
		flag = 0;
		nbr = (str[i] - '0') + (nbr * 10);
		if (nbr > 255)
			ft_error("Error: wrong color3", all);
		i++;
	}
	return (nbr);
}

int	get_color(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

int	rgb(char *line, t_all *all)
{
	int		i;
	char	**colors;
	int		rgb;

	i = 0;
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	colors = ft_split(line, ',');
	if (!colors)
		ft_error("Error: malloc fail", all);
	rgb = get_color(color_atoi(colors[0], all),
			color_atoi(colors[1], all),
			color_atoi(colors[2], all));
	free_tmp(colors);
	return (rgb);
}

void	check_comma(char *line, t_all *all)
{
	int	i;
	int	comma;

	i = 0;
	comma = 0;
	while (line[i])
	{
		if (line[i] == ',')
			comma++;
		i++;
	}
	if (comma != 2)
		ft_error("Error: wrong color", all);
}

void	check_fc(t_all *all, char *line)
{
	if ((ft_strncmp(line, "F ", 2) == 0) && all->map.floor == -1)
	{
		check_comma(line, all);
		all->map.floor = rgb(line, all);
	}
	else if ((ft_strncmp(line, "C ", 2) == 0) && all->map.ceiling == -1)
	{
		check_comma(line, all);
		all->map.ceiling = rgb(line, all);
	}
	else
		ft_error("Error: color F/C not found", all);
}
