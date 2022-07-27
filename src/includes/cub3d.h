/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschirni <eschirni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 12:04:01 by btenzlin          #+#    #+#             */
/*   Updated: 2022/07/27 20:11:26 by eschirni         ###   ########.fr       */
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

# define RED "\033[31m"
# define RESET "\033[0m"
# define WIDTH 1920
# define HEIGHT 1080

typedef struct s_ray
{
	char		dir;
	int			start[2];
	float		end[2];
	float		ra;
	float		dist;
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
	char		**file;
	char		*no_tex;
	char		*so_tex;
	char		*we_tex;
	char		*ea_tex;
	int			rgb_f[3];
	int			rgb_c[3];
	int			color_f;
	int			color_c;
	float		player[2];
	int			x;
	int			y;
	int			n_chars;
	mlx_image_t	*floor;
	mlx_image_t	*out;
	mlx_image_t	*wall;
}				t_map;

typedef struct s_menu
{
	bool		in_menu;
	char		scroll_mode;
	int			back_frame;
	int			scroll_frame;
	long		back_seconds;
	long		music_start;
	long		scroll_seconds;
}				t_menu;

typedef struct s_textures
{
	u_int32_t	*wall;
	u_int32_t	*floor;
	int			wall_size[2];
	int			floor_size[2];
	float		offset;
}				t_textures;

typedef struct s_game
{
	t_char		**chars;
	t_map		*map;
	t_menu		*menu;
	t_textures	*textures;
	mlx_t		*mlx;
	mlx_image_t	*game_img;
	int			ps;
}				t_game;

/* map parsing */
t_map	*init_map(char *mapfile);
void	map_checker(t_map *map);
char	**ft_split(char const *s, char c);
int		cub_atoi(char *str);
char	**cut_newlines(char **file);
int		size_2d(char **s);
char	*ft_strdup(char *str);
int		extract_infos(t_map *map, char **file, int f, int c);
int		ft_strncmp(const char *str1, const char *str2, size_t size);

/* char fuctions */
void	set_direction(t_game *game, char direction, int n);

/* utils */
bool	is_char_obj(char c);
void	free_exit(t_map *map, t_game *game);
void	ft_error(char *msg, char *arg);
int		ft_strlen(char *s);
int		check_file(char *file);
void	free_2d_array(char **arr);

/* draw functions */
void	draw_3d(t_game *game, t_ray *ray, int count_x, int *line_x);
void	draw_chars(t_game *game, char **map);
void	draw_game(t_ray *ray, t_game *game, float coords[2]);
void	draw_map(t_game *game, t_map *map);
void	draw_line(t_ray *ray, mlx_image_t *img);
void	get_map_textures(t_game *game);

/* hooks */
void	calc_rotate(t_game *game, float rotation, int n);
void	fps(void *tmp);
void	move_map(t_game *game, int addX, int addY);

/* rays */
float	calc_rays(t_ray *ray, t_map *map, int x, int y);

/* main menu */
void	main_menu(t_game *game);
void	to_game(t_game *game);

#endif
