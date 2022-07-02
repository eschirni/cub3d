#include "../includes/cub3d.h"

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
	line_width = WIDTH / game->settings->fov;
	while (count_x < line_width)
	{
		ray->start[0] = *line_x;
		ray->start[1] = HEIGHT / 2 - line_height / 2;
		ray->end[0] = *line_x;
		ray->end[1] = ray->start[1] + line_height;
		if (ray->start[0] < MINIMAP && ray->start[1] < MINIMAP)
			ray->start[1] = MINIMAP;
		draw_line(ray, game->game_img, 0x1a2229FF);
		*line_x += 1;
		count_x++;
	}
}

static void	reset_img(mlx_image_t *img, int width, int height)
{
	int	x;
	int	y;

	x = 0;
	while (x < width)
	{
		y = 0;
		while (y < height)
		{
			mlx_put_pixel(img, x, y, 0x000000);
			y++;
		}
		x++;
	}
}

void	draw_game(t_ray *ray, t_game *game, int x, int y)
{
	int		i;
	int		line_x;

	ray->ra = game->chars[0]->pa - 30 * ((float)M_PI / 180);
	if (ray->ra < 0)
		ray->ra += (float)M_PI * 2;
	if (game->game_img)
		mlx_delete_image(game->mlx, game->game_img);
	game->game_img = mlx_new_image(game->mlx, WIDTH, HEIGHT);
	i = 0;
	line_x = 0;
	reset_img(ray->img, MINIMAP, MINIMAP);
	while (i < game->settings->fov)
	{
		ray->ra += (float)M_PI / 180 / game->settings->graphics;
		if (ray->ra >= (float)M_PI * 2)
			ray->ra -= (float)M_PI * 2;
		ray->dist = calc_rays(ray, game->map, x, y);
		ray->start[0] = 144;
		ray->start[1] = 144;
		if (ray->end[0] > MINIMAP)
			ray->end[0] = MINIMAP;
		if (ray->end[1] > MINIMAP)
			ray->end[1] = MINIMAP;
		draw_line(ray, ray->img, ray->color); //draw ray
		draw_3d(game, ray, 0, &line_x);
		i++;
	}
	mlx_image_to_window(game->mlx, game->game_img, 0, 0);
}

// void	draw_game(t_ray *ray, t_game *game, int x, int y)
// {
// 	int		i;
// 	int		line_x;

// 	ray->ra = game->chars[0]->pa - 30 * ((float)M_PI / 180);
// 	if (ray->ra < 0)
// 		ray->ra += (float)M_PI * 2;
// 	if (game->game_img)
// 		mlx_delete_image(game->mlx, game->game_img);
// 	game->game_img = mlx_new_image(game->mlx, WIDTH, HEIGHT);
// 	i = 0;
// 	line_x = 0;
// 	reset_img(ray->img, MINIMAP - 1, MINIMAP - 1);
// 	while (i < game->settings->fov)
// 	{
// 		ray->ra += (float)M_PI / 180 / game->settings->graphics;
// 		if (ray->ra >= (float)M_PI * 2)
// 			ray->ra -= (float)M_PI * 2;
// 		ray->dist = calc_rays(ray, game->map, x, y);
// 		ray->start[0] = 144;
// 		ray->start[1] = 144;
// 		ray->end[0] += game->map->player[0];
// 		ray->end[1] += game->map->player[1];
// 		if (ray->end[0] > game->map->player[0])
// 			ray->end[0] -= game->map->player[0];
// 		if (ray->end[1] > game->map->player[1])
// 			ray->end[1] -= game->map->player[1];
// 		draw_line(ray, ray->img, 0xbad129); //draw ray
// 		draw_3d(game, ray, 0, &line_x);
// 		i++;
// 	}
// 	mlx_image_to_window(game->mlx, game->game_img, 0, 0);
// }
