#include "../includes/cub3d.h"

static void	draw_ground_sky(t_ray *ray, mlx_image_t *game_img)
{
	int	y;

	y = 0;
	if (ray->start[0] < MINIMAP)
		y = MINIMAP;
	while (y < ray->start[1])
	{
		mlx_put_pixel(game_img, ray->start[0], y, 0x1a6629FF);
		y++;
	}
	y = ray->end[1] + 1;
	while (y < HEIGHT)
	{
		mlx_put_pixel(game_img, ray->start[0], y, 0x1a0029FF);
		y++;
	}
}

static void	init_vars(t_game *game, t_ray *ray, float *lh, float *lw)
{
	float	angle_distance;

	angle_distance = game->chars[0]->pa - ray->ra;
	if (angle_distance < 0)
		angle_distance += (float)M_PI * 2;
	else if (angle_distance >= (float) M_PI * 2)
		angle_distance -= (float)M_PI * 2;
	ray->dist *= cos(angle_distance);
	*lh = 32 * HEIGHT / ray->dist;
	if (*lh >= HEIGHT)
		*lh = HEIGHT - 1;
	*lw = WIDTH / game->menu->settings->fov;
}

void	draw_3d(t_game *game, t_ray *ray, int count_x, int *line_x)
{
	float	line_height;
	float	line_width;

	init_vars(game, ray, &line_height, &line_width);
	while (count_x < line_width)
	{
		ray->start[0] = *line_x;
		ray->start[1] = HEIGHT / 2 - line_height / 2;
		ray->end[0] = *line_x;
		ray->end[1] = ray->start[1] + line_height;
		if (ray->start[0] < MINIMAP && ray->start[1] < MINIMAP)
			ray->start[1] = MINIMAP;
		draw_line(ray, game->game_img, ray->color);
		draw_ground_sky(ray, game->game_img);
		*line_x += 1;
		count_x++;
	}
}
