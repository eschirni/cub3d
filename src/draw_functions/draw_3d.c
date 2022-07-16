#include "../includes/cub3d.h"

static void	get_color(t_game *game, t_ray *ray, u_int32_t *col, float dy)
{
	float	angle;
	float	tx;
	float	ty;
	int		tex[2];

	tex[0] = game->textures->floor_size[0];
	tex[1] = game->textures->floor_size[1];
	angle = game->chars[0]->pa - ray->ra;
	if (angle >= (float)M_PI * 2)
		angle -= (float)M_PI * 2;
	else if (angle < 0)
		angle += (float)M_PI * 2;
	angle = cos(angle);
	tx = game->map->player[0] + cos(ray->ra) * (HEIGHT / 2) * 32 / dy / angle;
	ty = game->map->player[1] + sin(ray->ra) * (HEIGHT / 2) * 32 / dy / angle;
	ray->color = col[((int)ty % tex[1]) * tex[1] + ((int)tx % tex[0])];
	if (dy * angle < 480 && ray->color >= 0x0F0F0FFF)
		ray->color -= 0x0F0F0F00;
	if (dy * angle < 240 && ray->color >= 0x0F0F0FFF)
		ray->color -= 0x0F0F0F00;
	if (dy * angle < 120)
		ray->color = 0x000000FF;
}

static void	*draw_env(void *tmp)
{
	t_game	*game;
	t_ray	*ray;
	int		y;
	int		y_top;

	game = tmp;
	ray = game->chars[0]->ray;
	y = ray->end[1];
	while (y < HEIGHT)
	{
		get_color(game, ray, game->textures->floor, y - (HEIGHT / 2));
		if (!(ray->start[0] < MINIMAP && y < MINIMAP))
			mlx_put_pixel(game->game_img, ray->start[0], y, ray->color);
		get_color(game, ray, game->textures->top, y - (HEIGHT / 2));
		if (!(ray->start[0] < MINIMAP && (HEIGHT - y) < MINIMAP))
		{
			y_top = HEIGHT - y - 1;
			mlx_put_pixel(game->game_img, ray->start[0], y_top, ray->color);
		}
		y++;
	}
	return (NULL);
}

static float	init_vars(t_game *game, t_ray *ray, float *lh, float *lw)
{
	float	angle_distance;
	float	out_of_bounds;

	angle_distance = game->chars[0]->pa - ray->ra;
	if (angle_distance < 0)
		angle_distance += (float)M_PI * 2;
	else if (angle_distance >= (float) M_PI * 2)
		angle_distance -= (float)M_PI * 2;
	ray->dist *= cos(angle_distance);
	*lh = 32 * HEIGHT / ray->dist;
	game->textures->offset = game->textures->wall_size[1] / *lh;
	out_of_bounds = 0;
	if (*lh > HEIGHT + 1)
	{
		out_of_bounds = (*lh - HEIGHT - 1) / 2;
		*lh = HEIGHT - 1;
	}
	*lw = WIDTH / game->menu->settings->fov;
	return (out_of_bounds);
}

static void	draw_tex_line(t_game *game, t_ray *ray, float pos, long ray_end)
{
	int		texture_x;
	int		texture_y;
	int		ray_start;

	ray_start = ray->start[1];
	while (ray_start <= ray->end[1])
	{
		texture_x = (int)pos * game->textures->wall_size[1];
		texture_y = ray_end % game->textures->wall_size[0];
		ray->color = game->textures->current[texture_x + texture_y];
		if (!(ray->start[0] < MINIMAP && ray_start < MINIMAP))
		{
			if (ray->dist > 70 && ray->color >= 0x0F0F0FFF)
				ray->color -= 0x0F0F0F00;
			if (ray->dist > 30 && ray->color >= 0x0F0F0FFF)
				ray->color -= 0x0F0F0F00;
			if (ray->dist > 144)
				ray->color = 0x000000FF;
			mlx_put_pixel(game->game_img, ray->start[0], ray_start, ray->color);
		}
		ray_start += 1;
		pos += game->textures->offset;
	}
}

static void	draw_tex(t_game *game, t_ray *ray, int count_x, int *line_x) //segfaults with bigger pics, need to calculate with actual image with in player pos over minimap, to avoid image spreading over multiple tiles in 3d
{
	float	line_height;
	float	line_width;
	float	pixel_pos;
	float	out_of_bounds;
	long	ray_end;
	pthread_t	id;

	out_of_bounds = init_vars(game, ray, &line_height, &line_width);
	// pthread_create(&id, NULL, draw_env, game);
	// pthread_join(id, NULL);
	ray_end = ray->end[1] / 32 * game->textures->wall_size[1];
	if (ray->dir == 'E')
		ray_end = ray->end[0] / 32 * game->textures->wall_size[0];
	while (count_x < line_width)
	{
		ray->start[0] = *line_x;
		ray->start[1] = HEIGHT / 2 - line_height / 2;
		ray->end[1] = ray->start[1] + line_height;
		pixel_pos = out_of_bounds * game->textures->offset;
		draw_tex_line(game, ray, pixel_pos, ray_end);
		draw_env(game);
		*line_x += 1;
		count_x++;
	}
	// pthread_detach(id);
}

void	draw_3d(t_game *game, t_ray *ray, int count_x, int *line_x)
{
	int	x;
	int	y;

	x = (int)ray->end[0] / 32;
	y = (int)ray->end[1] / 32;
	if (game->map->big_map[y][x] == '1')
		game->textures->current = game->textures->wall;
	else if (game->map->big_map[y][x] == '8'
		|| game->map->big_map[y][x] == '9')
		game->textures->current = game->textures->door;
	else if (game->map->big_map[y][x] == '7')
		game->textures->current = game->textures->door_o;
	else if (game->map->big_map[y][x] == 'X')
		game->textures->current = game->textures->exit;
	draw_tex(game, ray, count_x, line_x);
}
