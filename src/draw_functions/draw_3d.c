#include "../includes/cub3d.h"

static void	draw_ground(t_game *game, t_ray *ray, float player[2], int tex[2])
{
	float	angle;
	float	dy;
	float	tx;
	float	ty;
	int		y;

	y = ray->end[1] + 1;
	while (y < HEIGHT)
	{
		dy = y - (HEIGHT / 2);
		angle = game->chars[0]->pa - ray->ra;
		if (angle >= (float)M_PI * 2)
			angle -= (float)M_PI * 2;
		else if (angle < 0)
			angle += (float)M_PI * 2;
		angle = cos(angle);
		tx = player[0] + cos(ray->ra) * (HEIGHT / 2) * 32 / dy / angle;
		ty = player[1] + sin(ray->ra) * (HEIGHT / 2) * 32 / dy / angle;
		ray->color = game->textures->floor[((int)ty % tex[1]) * tex[1] + ((int)tx % tex[0])];
		if (dy * angle < 480 && ray->color >= 0x0F0F0FFF)
			ray->color -= 0x0F0F0F00;
		if (dy * angle < 240 && ray->color >= 0x0F0F0FFF)
			ray->color -= 0x0F0F0F00;
		if (dy * angle < 120)
			ray->color = 0x000000FF;
		mlx_put_pixel(game->game_img, ray->start[0], y, ray->color);
		ray->color = game->textures->top[((int)ty % tex[1]) * tex[1] + ((int)tx % tex[0])];
		if (dy * angle < 480 && ray->color >= 0x0F0F0FFF)
			ray->color -= 0x0F0F0F00;
		if (dy * angle < 240 && ray->color >= 0x0F0F0FFF)
			ray->color -= 0x0F0F0F00;
		if (dy * angle < 120)
			ray->color = 0x000000FF;
		if (HEIGHT - y > MINIMAP || ray->start[0] > MINIMAP)
			mlx_put_pixel(game->game_img, ray->start[0], HEIGHT - y, ray->color);
		y++;
	}
}

static void	draw_env(t_game *game, t_ray *ray)
{
	int	y;
	int	tex[2];

	y = 0;
	if (ray->start[0] < MINIMAP)
		y = MINIMAP;
	while (y < ray->start[1])
	{
		mlx_put_pixel(game->game_img, ray->start[0], y, 0x000000FF);
		y++;
	}
	tex[0] = game->textures->floor_size[0];
	tex[1] = game->textures->floor_size[1];
	draw_ground(game, ray, game->map->player, tex);
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
		ray->color = game->textures->wall[texture_x + texture_y]; //numbers besides 32 in with won't scale bec our tile size is 32
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

void	draw_3d(t_game *game, t_ray *ray, int count_x, int *line_x) //segfaults with bigger pics, need to calculate with actual image with in player pos over minimap, to avoid image spreading over multiple tiles in 3d
{
	float	line_height;
	float	line_width;
	float	pixel_pos;
	float	out_of_bounds;
	long	ray_end;

	out_of_bounds = init_vars(game, ray, &line_height, &line_width);
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
		draw_env(game, ray);
		*line_x += 1;
		count_x++;
	}
}
