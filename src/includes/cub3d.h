/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschirni <eschirni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 12:04:01 by btenzlin          #+#    #+#             */
/*   Updated: 2022/07/28 10:46:34 by eschirni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../../MLX42/include/MLX42/MLX42.h"
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
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
	float		w[2];
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
	float		enemy[2];
	float		**chests;
	int			loot;
	int			n_chars;
	int			x;
	int			y;
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

typedef struct s_end
{
	mlx_image_t	*back[8];
	mlx_image_t	*cat[33];
	bool		in_end;
	int			back_frame;
	int			cat_frame;
	long		back_seconds;
	long		music_start;
	float		end_pos;
}				t_end;

typedef struct s_textures
{
	u_int32_t	*floor;
	u_int32_t	*wall;
	u_int32_t	*door;
	u_int32_t	*door_o;
	u_int32_t	*exit;
	u_int32_t	*luci[8];
	u_int32_t	*chest;
	u_int32_t	*chuci;
	u_int32_t	*current;
	int			luci_frame;
	int			wall_size[2];
	int			luci_size[2];
	int			chest_size[2];
	int			chuci_size[2];
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
	t_end		*end;
	t_map		*map;
	t_menu		*menu;
	t_sounds	*sounds;
	t_textures	*textures;
	mlx_t		*mlx;
	mlx_image_t	*game_img;
	mlx_image_t	*torch;
	bool		ray_tiles[MINIMAP][MINIMAP];
	int			ps;
	int			torch_frame;
	float		*rays;
	float		loot;
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
	int			loot;
	char		**map;
}				t_mg;

typedef struct s_sprite_vars
{
	int		x;
	int		y;
	int		size[2];
	float	t_pos[2];
	float	offset[2];
	float	s_pos[3];
	float	tmp[2];
}			t_sprite_vars;

/* map parsing */
t_map	*init_map(t_mg *mapg);

/* char fuctions */
void	set_direction(t_game *game, char direction, int n);

/* utils */
void	check_pos(t_game *game);
void	free_exit(t_map *map, t_game *game);
void	free_2d_array(char **arr);
void	ft_error(char *msg, char *arg);
void	open_door(t_game *game, int addX, int addY);
bool	is_char_obj(char c);
int		ft_strlen(char *s);
int		check_file(char *file);
int		find_instance(t_game *game, int x, int y);
char	*ft_append(char *start, char *end);
char	*ft_itoa(int n);
char	*ft_strcdup(char *s1, char c, size_t start);
void	init_end_textures(t_game *game);

/* draw functions */
void	draw_3d(t_game *game, t_ray *ray, int count_x, int *line_x);
void	draw_chars(t_game *game, char **map);
void	draw_game(t_game *game, t_ray *ray);
void	draw_map(t_game *game, t_map *map);
void	draw_line(t_game *game, t_ray *ray, mlx_image_t *img);
void	draw_crosshair(t_game *game, int color, char type);
void	get_map_textures(t_game *game);
void	draw_sprite(t_game *game, float sp_x, float sp_y, char c);
void	draw_torch(t_game *game);
void	sort_chests(t_game *game);
void	draw_tex_line(t_game *game, t_ray *ray, float pos, long ray_end);
void	set_z(mlx_image_t *img, int z);
float	calc_dist(float player[2], float chest[2]);

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
t_mg	*create_map(int size, int tunnels, int tunnel_len, int end_len);
int		get_random_num(int from, int to);
int		is_corner(char **map, int i, int j);
int		is_corridor(char **map, int i, int j);
void	refactor_map(t_mg *mapg, int i, int j);
void	set_entities(char **map, char c, int chance);
void	check_floors(t_mg *mapg);
void	checker(t_mg *mapg);
int		set_rnd_direction(t_mg *mapg);

/* end game */
void	animate_end(mlx_t *mlx, t_end *end);
void	end_game(t_game *game);

/* gameplay */
void	move_enemies(t_game *game);

#endif
