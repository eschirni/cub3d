#include "../cub3d.h"

static void	draw_3d(t_game *game, t_ray *ray, int count_x, int *line_x)
{
	float	line_height;
	float	line_width;
	float	angle_distance;

	angle_distance = game->chars[0]->pa - ray->ra;
	if (angle_distance < 0)
		angle_distance += (float)M_PI * 2;
	else if (angle_distance >= (float) M_PI * 2)
		angle_distance -= (float)M_PI * 2;
	ray->dist *= cos(angle_distance);
	line_height = 32 * HEIGHT / ray->dist;
	if (line_height >= HEIGHT)
		line_height = HEIGHT - 1;
	line_width = WIDTH / 960;
	while (count_x < line_width)
	{
		ray->start[0] = *line_x;
		ray->start[1] = HEIGHT / 2 - line_height / 2;
		ray->end[0] = *line_x;
		ray->end[1] = ray->start[1] + line_height;
		draw_line(ray, game->game_img, ray->color);
		*line_x += 1;
		count_x++;
	}
}

void	draw_game(t_ray *ray, t_game *game, int x, int y)
{
	int		i;
	int		line_x;

	ray->ra = game->chars[0]->pa - 30 * ((float)M_PI / 180);
	if (ray->ra < 0)
		ray->ra += (float)M_PI * 2;
	ray->img = mlx_new_image(game->mlx, game->mlx->width, game->mlx->height);
	if (game->game_img)
		mlx_delete_image(game->mlx, game->game_img);
	game->game_img = mlx_new_image(game->mlx, WIDTH, HEIGHT);
	i = 0;
	line_x = 0;
	while (i < 960)
	{
		ray->ra += (float)M_PI / 180 / 16;
		if (ray->ra >= (float)M_PI * 2)
			ray->ra -= (float)M_PI * 2;
		ray->dist = calc_rays(ray, game->map, x, y);
		draw_line(ray, ray->img, 0xbad129); //draw ray
		draw_3d(game, ray, 0, &line_x);
		i++;
	}
	mlx_image_to_window(game->mlx, game->game_img, 0, 0);
	mlx_image_to_window(game->mlx, ray->img, 0, 0);
}
