#include "../includes/cub3d.h"

static void	draw_ground_sky(t_ray *ray, mlx_image_t *game_img)
{
	int	y;

	y = 0;
	if (ray->start[0] < MINIMAP)
		y = MINIMAP;
	while (y < ray->start[1])
	{
		mlx_put_pixel(game_img, ray->start[0], y, 0x001100FF);
		y++;
	}
	y = ray->end[1] + 1;
	while (y < HEIGHT)
	{
		mlx_put_pixel(game_img, ray->start[0], y, 0x001100FF);
		y++;
	}
}

static float	init_vars(t_game *game, t_ray *ray, float *lh, float *lw, float *offset)
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
	*offset = game->textures->wall_size[1] / *lh;
	out_of_bounds = 0;
	if (*lh >= HEIGHT)
	{
		out_of_bounds = (*lh - HEIGHT - 1) / 2;
		*lh = HEIGHT - 1;
	}
	*lw = WIDTH / game->menu->settings->fov;
	return (out_of_bounds);
}

void	draw_3d(t_game *game, t_ray *ray, int count_x, int *line_x) //segfaults with bigger pics, need to calculate with actual image with in player pos over minimap, to avoid image spreading over multiple tiles in 3d
{
	float	line_height;
	float	line_width;
	float	offset;
	float	pixel_pos;
	float	out_of_bounds;
	int		ray_start;
	int		ray_end;

	out_of_bounds = init_vars(game, ray, &line_height, &line_width, &offset);
	ray_end = ray->end[1];
	if (ray->dir == 'E')
		ray_end = ray->end[0];
	while (count_x < line_width)
	{
		ray->start[0] = *line_x;
		ray->start[1] = HEIGHT / 2 - line_height / 2;
		ray->end[1] = ray->start[1] + line_height;
		pixel_pos = out_of_bounds * offset;
		ray_start = ray->start[1];
		while (ray->start[1] <= ray->end[1])
		{
			ray->color = game->textures->wall[((int)(pixel_pos) * game->textures->wall_size[1]) + ((ray_end) % game->textures->wall_size[0])]; //numbers besides 32 in with won't scale bec our tile size is 32
			if (!(ray->start[0] < MINIMAP && ray->start[1] < MINIMAP))
				mlx_put_pixel(game->game_img, *line_x, ray->start[1], ray->color);
			ray->start[1] += 1;
			pixel_pos += offset;
		}
		ray->start[1] = ray_start;
		draw_ground_sky(ray, game->game_img);
		*line_x += 1;
		count_x++;
	}
}
