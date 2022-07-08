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
	*offset = 32 / *lh;
	out_of_bounds = 0;
	if (*lh >= HEIGHT)
	{
		out_of_bounds = (*lh - HEIGHT - 1) / 2;
		*lh = HEIGHT - 1;
	}
	*lw = WIDTH / game->menu->settings->fov;
	return (out_of_bounds);
}

void	draw_3d(t_game *game, t_ray *ray, int count_x, int *line_x)
{
	float	line_height;
	float	line_width;
	float	offset;
	float	pixel_pos;
	float	out_of_bounds;
	int		ray_start;

	out_of_bounds = init_vars(game, ray, &line_height, &line_width, &offset);
	while (count_x < line_width)
	{
		ray->start[0] = *line_x;
		ray->start[1] = HEIGHT / 2 - line_height / 2;
		ray->end[1] = ray->start[1] + line_height;
		pixel_pos = out_of_bounds * offset;
		ray_start = ray->start[1];
		while (ray->start[1] <= ray->end[1])
		{
			ray->color = game->wall[((int)(pixel_pos) * 128) + ((((int)ray->end[0])) % 128)]; //why 128?? It's a 64 x 64 pic
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
