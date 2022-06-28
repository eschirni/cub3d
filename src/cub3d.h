/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btenzlin <btenzlin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 12:04:01 by btenzlin          #+#    #+#             */
/*   Updated: 2022/06/28 14:53:05 by btenzlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//todo: ft_error also frees stuff, use pixels to draw chars for rotation

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
	int			w[2]; //x, y
	int			a[2];
	int			s[2];
	int			d[2];
	float		pa;
}				t_char;

typedef struct s_map
{
	char		**map_arr;
	float		player[2];
	int			x;
	int			y;
}				t_map;

typedef struct s_game
{
	t_char		**chars;
	t_map		*map;
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
void		ft_error(char *msg, char *arg);
int			ft_strlen(char *s);
int			check_file(char *file);

/* draw functions */
void		draw_map(t_game *game, t_map *map);
void		draw_line(t_ray *ray, mlx_image_t *img, int color);

/* hooks */
void		calc_rotate(t_game *game, float rotation, int n);
void		hook(void *tmp);

/* rays */
float		calc_rays(t_ray *ray, t_map *map, float pa, int x, int y);

#endif
