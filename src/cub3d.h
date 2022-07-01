/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btenzlin <btenzlin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 12:04:01 by btenzlin          #+#    #+#             */
/*   Updated: 2022/07/01 17:25:24 by btenzlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//todo: one mlx_loop only, draw live instead of creating a new image every second

#ifndef CUB3D_H
# define CUB3D_H

# include "../MLX42/include/MLX42/MLX42.h"
# include "../get_next_line/get_next_line.h"
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <fcntl.h>
# include <math.h>
# include <stdio.h>	//debug

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
}				t_char;

typedef struct s_map
{
	char		**map_arr;
	float		player[2];
	int			x;
	int			y;
}				t_map;

typedef struct s_menu
{
	bool		in_menu;
	bool		in_settings;
	int			back_frame;
	int			scroll_frame;
	mlx_image_t	*imgs[33];
	long		back_seconds;
	long		scroll_seconds;
}				t_menu;

typedef struct s_mapgen
{
	int			dirs[4][2];
	int			rand_dir[2];
	int			last_dir[2];
	int			start[2];
	char		**map;
}				t_mapgen;

typedef struct s_game
{
	t_char		**chars;
	t_map		*map;
	t_menu		*menu;
	mlx_t		*mlx;
	mlx_image_t	*game_img;
	mlx_image_t	*floor;
	mlx_image_t	*out;
	mlx_image_t	*wall;
	int			n_chars;
}				t_game;

/* map parsing */
t_map		*init_map(char *mapfile);

/* char fuctions */
void		set_direction(t_game *game, char direction, int n);

/* utils */
bool		is_char_obj(char c);
void		free_exit(t_map *map, t_game *game);
void		ft_error(char *msg, char *arg);
int			ft_strlen(char *s);
int			check_file(char *file);

/* draw functions */
void		draw_chars(t_game *game, char **map);
void		draw_game(t_ray *ray, t_game *game, int x, int y);
void		draw_map(t_game *game, t_map *map, float player[2]);
void		draw_line(t_ray *ray, mlx_image_t *img, int color);
void		draw_crosshair(mlx_t *mlx, int color);

/* hooks */
void		calc_rotate(t_game *game, float rotation, int n);
void		hook(void *tmp);

/* rays */
float		calc_rays(t_ray *ray, t_map *map, int x, int y);

/* main menu */
void	hover_buttons(double x, double y, void *tmp);
void		main_menu(t_game *game);

/* map gen */
t_mapgen	*create_map(int size, int tunnels, int tunnel_len);

#endif
