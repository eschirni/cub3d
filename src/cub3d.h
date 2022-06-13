/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschirni <eschirni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 12:04:01 by btenzlin          #+#    #+#             */
/*   Updated: 2022/06/13 20:02:04 by eschirni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//todo: ft_error also frees stuff, safe in t_char in what direction he walks when pressed w, rename game struct to map or smth

#ifndef CUB3D_H
# define CUB3D_H

# include "../MLX42/include/MLX42/MLX42.h"
# include "../get_next_line/get_next_line.h"
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <fcntl.h>
# include <stdio.h>	//debug

# define RED "\033[31m"
# define RESET "\033[0m"
# define WIDTH 512
# define HEIGHT 512
# define TILE_WIDTH 32
# define TILE_HEIGHT 32

typedef struct s_char
{
	mlx_image_t	*img;
	int			hp;
	int			speed; //just ideas
}				t_char;

typedef struct s_game
{
	t_char		**chars;
	mlx_t		*mlx;
	mlx_image_t	*floor;
	mlx_image_t	*wall;
}				t_game;

typedef struct s_map
{
	char		**map_arr;
	int			mini_size;
	int			x;
	int			y;
}				t_map;

/* map parsing */
t_map	*init_map(char *mapfile);

/* utils */
void	ft_error(char *msg, char *arg);

/* draw functions */
void	draw_map(t_game *game, t_map *map);

#endif
