/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btenzlin <btenzlin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 12:04:01 by btenzlin          #+#    #+#             */
/*   Updated: 2022/07/04 21:56:50 by eschirni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//todo: draw live instead of creating a new image every second

#ifndef CUB3D_H
# define CUB3D_H

# include "../../MLX42/include/MLX42/MLX42.h"
# include "../../get_next_line/get_next_line.h"
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <fcntl.h>
# include <math.h>
# include <stdio.h>	//debug
# include <sys/time.h>

# define RED "\033[31m"
# define RESET "\033[0m"
# define WIDTH 1920
# define HEIGHT 1080
# define MINIMAP 288

typedef struct s_ray
{
	int			color;
	int			start[2];
	float		end[2];
	float		ra;
	float		dist;
	mlx_image_t	*img;
}				t_ray;

typedef struct s_char
{
	t_ray		*ray;
	mlx_image_t	*img;
	float		w[2]; //x, y
	float		a[2];
	float		s[2];
	float		d[2];
	float		pa;
	float		x;
	float		y;
}				t_char;

typedef struct s_map
{
	char		**big_map;
	float		player[2];
	int			x;
	int			y;
	int			n_chars;
	mlx_image_t	*floor;
	mlx_image_t	*out;
	mlx_image_t	*wall;
}				t_map;

typedef struct s_settings
{
	char		cross_type;
	int			fov;
	int			graphics;
	float		rs;
}				t_settings;

typedef struct s_menu
{
	t_settings	*settings;
	bool		in_menu;
	char		scroll_mode;
	int			back_frame;
	int			scroll_frame;
	long		back_seconds;
	long		scroll_seconds;
	mlx_image_t	*imgs[65];
}				t_menu;

typedef struct s_game
{
	t_char		**chars;
	t_map		*map;
	t_menu		*menu;
	mlx_t		*mlx;
	mlx_image_t	*game_img;
	int			ps;
}				t_game;

typedef struct s_mapgen
{
	int			dirs[4][2];
	int			rand_dir[2];
	int			last_dir[2];
	int			start[2];
	int			player_start[2];
	int			rand;
	int			size;
	char		**map;
}				t_mapgen;

/* map parsing */
t_map	*init_map(char *mapfile);

/* char fuctions */
void	set_direction(t_game *game, char direction, int n);

/* utils */
bool	is_char_obj(char c);
void	free_exit(t_map *map, t_game *game, t_mapgen *mapg);
void	ft_error(char *msg, char *arg);
int		ft_strlen(char *s);
int		check_file(char *file);
void	free_2d_array(char **arr);

/* draw functions */
void	draw_3d(t_game *game, t_ray *ray, int count_x, int *line_x);
void	draw_chars(t_game *game, char **map);
void	draw_game(t_ray *ray, t_game *game, float coords[2]);
void	draw_map(t_game *game, t_map *map);
void	draw_line(t_ray *ray, mlx_image_t *img, int color);
void	draw_crosshair(t_game *game, int color, char type);
void	get_map_textures(t_game *game);

/* hooks */
void	calc_rotate(t_game *game, float rotation, int n);
void	fps(void *tmp);
void	move_map(t_game *game, int addX, int addY);

/* rays */
float	calc_rays(t_ray *ray, t_map *map, int x, int y);

/* main menu */
void	animate_menu(t_menu *menu);
void	hover_buttons(double x, double y, void *tmp);
void	main_menu(t_game *game);
void	to_game(t_game *game);
void	to_menu(t_game *game);

/* map gen */
t_mapgen	*create_map(int size, int tunnels, int tunnel_len, int end_len);
int		get_random_num(int from, int to);
void	refactor_map(t_mapgen *mapg);

#endif
