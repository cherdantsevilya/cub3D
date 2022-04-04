/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkari <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 18:19:18 by pkari             #+#    #+#             */
/*   Updated: 2022/04/01 18:19:20 by pkari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_error(char *str, t_all *all)
{
	free_all(all);
	printf("\x1b[31m%s\x1b[0m\n", str);
	exit(EXIT_FAILURE);
}

int	main(int argc, char **argv)
{
	t_all	all;

	if (argc != 2)
		ft_error("Error: wrong numb of arg", &all);
	init_cub(&all);
	pars_cub(&all, argv[1]);
	mlx_loop_hook(all.mlx.mlx, draw_cub, &all);
	mlx_hook(all.mlx.win, 2, 0, key_hook, &all);
	mlx_hook(all.mlx.win, 17, 0, exit_hook, &all);
	mlx_loop(all.mlx.mlx);
	return (0);
}
