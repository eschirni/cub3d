/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschirni <eschirni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 12:04:01 by btenzlin          #+#    #+#             */
/*   Updated: 2022/07/15 01:32:08 by eschirni         ###   ########.fr       */
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
	char		dir;
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
	mlx_image_t	*doorv;
	mlx_image_t	*doorh;
	mlx_image_t	*chest;
	mlx_image_t	*exit;
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
	bool		started_game;
	char		scroll_mode;
	int			back_frame;
	int			scroll_frame;
	long		back_seconds;
	long		music_start;
	long		scroll_seconds;
	mlx_image_t	*imgs[69];
}				t_menu;

typedef struct s_textures
{
	u_int32_t	*floor;
	u_int32_t	*top;
	u_int32_t	*wall;
	u_int32_t	*door;
	u_int32_t	*door_o;
	u_int32_t	*exit;
	u_int32_t	*current;
	int			floor_size[2];
	int			top_size[2];
	int			wall_size[2];
	float		offset;
}				t_textures;

typedef struct s_sounds
{
	long		music_start;
	long		step;
	bool		sound;
}				t_sounds;

typedef struct s_game
{
	t_char		**chars;
	t_map		*map;
	t_menu		*menu;
	t_sounds	*sounds;
	t_textures	*textures;
	mlx_t		*mlx;
	mlx_image_t	*game_img;
	int			ps;
	int			loot;
}				t_game;

typedef struct s_mapgen
{
	int			dirs[4][2];
	int			rand_dir[2];
	int			last_dir[2];
	int			start[2];
	int			player_start[2];
	int			exit[2];
	int			rand;
	int			size;
	char		**map;
}				t_mapgen;

/* map parsing */
t_map	*init_map(t_mapgen *mapg);

/* char fuctions */
void	set_direction(t_game *game, char direction, int n);

/* utils */
bool	is_char_obj(char c);
int		check_file(char *file);
int		find_instance(t_game *game, int x, int y);
int		ft_strlen(char *s);
void	check_pos(t_game *game);
void	free_exit(t_map *map, t_game *game);
void	ft_error(char *msg, char *arg);
void	free_2d_array(char **arr);
void	open_door(t_game *game, int addX, int addY);

/* draw functions */
void	draw_3d(t_game *game, t_ray *ray, int count_x, int *line_x);
void	draw_chars(t_game *game, char **map);
void	draw_game(t_ray *ray, t_game *game, float coords[2]);
void	draw_map(t_game *game, t_map *map);
void	draw_line(t_ray *ray, mlx_image_t *img);
void	draw_crosshair(t_game *game, int color, char type);
void	get_map_textures(t_game *game);

/* hooks */
void	calc_rotate(t_game *game, float rotation, int n);
void	fps(void *tmp);
void	move_map(t_game *game, int addX, int addY);

/* rays */
float	calc_rays(t_ray *ray, t_map *map, int x, int y);

/* main menu */
void	animate_menu(t_game *game);
void	hover_buttons(double x, double y, void *tmp);
void	main_menu(t_game *game);
void	to_game(t_game *game);
void	to_menu(t_game *game);

/* map gen */
t_mapgen	*create_map(int size, int tunnels, int tunnel_len, int end_len);
int		get_random_num(int from, int to);
int		is_corner(char **map, int i, int j);
int		is_corridor(char **map, int i, int j);
void	refactor_map(t_mapgen *mapg, int i, int j);
void	set_entities(char **map, char c, int chance);
void	check_floors(t_mapgen *mapg);

#endif
