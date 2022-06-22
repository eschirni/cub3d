/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschirni <eschirni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 12:04:01 by btenzlin          #+#    #+#             */
/*   Updated: 2022/06/22 19:42:03 by eschirni         ###   ########.fr       */
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
# define WIDTH 288
# define HEIGHT 288

typedef struct s_ray
{
	int			start[2];
	int			end[2];
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

typedef struct s_game
{
	t_char		**chars;
	mlx_t		*mlx;
	mlx_image_t	*floor;
	mlx_image_t	*out;
	mlx_image_t	*wall;
	int			n_chars;
}				t_game;

typedef struct s_map
{
	char		**map_arr;
	int			player[2];
	int			x;
	int			y;
}				t_map;

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
mlx_image_t	*draw_line(t_game *game, t_ray *ray);

/* hooks */
void		calc_rotate(t_game *game, float rotation, int n);
void		hook(void *tmp);

/* rays */
void	calc_rays(t_ray *ray, float pa, int x, int y);

#endif
