/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkari <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 17:53:15 by pkari             #+#    #+#             */
/*   Updated: 2022/04/01 17:53:19 by pkari            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <math.h>
# include "../libft/libft.h"
# include "../mlx/mlx.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <errno.h>
# include <string.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# define WIDTH 1280
# define HEIGHT 960
# define W 13
# define A 0
# define S 1
# define D 2
# define ESC 53
# define LEFT 123
# define RIGHT 124
# define SM 0.1
# define SR 0.05

typedef struct s_mlx
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*addr;
	int			bpp;
	int			line_l;
	int			end;
}				t_mlx;

typedef struct s_map
{
	char	**map;
	int		height;
	char	*north;
	char	*south;
	char	*west;
	char	*east;
	int		floor;
	int		ceiling;
	int		x;
	int		y;
}			t_map;

typedef struct s_point
{
	double	x;
	double	y;
}			t_point;

typedef struct s_plr
{
	t_point	pos;
	t_point	dir;
}			t_plr;

typedef struct s_ray
{
	double	camera_x;
	t_point	raydir;
	t_point	plane;
	t_point	dd;
	t_point	sd;
	int		step_x;
	int		step_y;
	int		hit;
	int		side;
	double	walldist;
	int		height;
	int		start;
	int		end;
}			t_ray;

typedef struct s_wall
{
	int		tex_x;
	int		tex_y;
	double	tex_pos;
	double	step;
}			t_wall;

typedef struct s_all
{
	t_mlx	mlx;
	t_map	map;
	t_plr	plr;
	t_ray	ray;
	t_wall	wall;
}			t_all;

//*** main.c ***//
void	ft_error(char *str, t_all *all);

//*** init.c ***//
void	init_cub(t_all *all);
void	init_cub_help(t_all *all);
void	init_mlx(t_all *all);

//*** pars.c ***//
void	pars_cub(t_all *all, char *map);
void	check_cub(t_all *all, int fd);
void	check_cub_helper(t_all *all, char *line);

//*** pars_check_FC.c ***//
void	check_fc(t_all *all, char *line);
void	check_comma(char *line, t_all *all);
int		rgb(char *line, t_all *all);
int		get_color(int r, int g, int b);
int		color_atoi(const char *str, t_all *all);

//*** pars_check_NSWE.c ***//
void	check_nswe(t_all *all, char *line);
void	*texture_xpm(t_all *all, char *line);
void	check_duplicate(t_all *all);
void	set_position(t_all *all, int nswe, double i, double j);

//*** pars_map.c ***//
void	pars_map(t_all *all, char *line, int n);
int		check_line(char *line, int n);
void	check_map_close(t_all *all);
void	check_position(t_all *all, int i, int j);

//*** draw.c ***//
int		draw_cub(t_all *all);
void	draw_FC(t_all *all);
void	pixel_put(t_all *all, int x, int y, int color);
void	draw_mini_map(t_all *all);
void	draw_pixel(t_all *all, int i, int j, int color);

//*** draw_raycasting.c ***//
void	draw_raycasting(t_all *all);
void	pre_raycasting(t_all *all, int x);
void	dda(t_all *all);
void	calculations(t_all *all);
void	textures(t_all *all, int x);

//*** textures.c ***//
void	textures(t_all *all, int x);
void	pre_processing(t_all *all);
int		texturing(t_all *all, unsigned int *color);

//*** hook.c ***//
int		key_hook(int key, t_all *all);
int		exit_hook(t_all *all);
void	key_hook_ws(int key, t_all *all);
void	key_hook_ad(int key, t_all *all);
void	key_hook_lr(int key, t_all *all);

//*** utils.c ***///
void	free_tmp(char **arr);
void	free_all(t_all *all);

//*** gnl ***///
int		get_next_line(int fd, char **line);
int		ft_find_i(const char *reminder, int c);
int		ft_check_reminder(char *reminder, char **line, int i);
void	*ft_gnl_memmove(void *dst, const void *src, size_t n);
size_t	ft_gnl_strlen(const char *s);
char	*ft_gnl_strdup(const char *s1);
char	*ft_gnl_substr(char const *s, unsigned int start, size_t len);
char	*ft_gnl_strjoin(char *s1, char *s2);

#endif
