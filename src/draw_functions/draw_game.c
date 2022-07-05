#include "../includes/cub3d.h"

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

static void	iterate_game(t_game *game, t_ray *ray, int i, int coords[2])
{
	int	line_x;

	line_x = 0;
	while (i < game->menu->settings->fov)
	{
		ray->ra += (float)M_PI / 180 / game->menu->settings->graphics;
		if (ray->ra >= (float)M_PI * 2)
			ray->ra -= (float)M_PI * 2;
		ray->dist = calc_rays(ray, game->map, coords[0], coords[1]);
		ray->start[0] -= game->map->player[0] - 144;
		ray->start[1] -= game->map->player[1] - 144;
		ray->end[0] -= game->map->player[0] - 144;
		ray->end[1] -= game->map->player[1] - 144;
		if (ray->end[0] > MINIMAP)
			ray->end[0] = MINIMAP;
		if (ray->end[1] > MINIMAP)
			ray->end[1] = MINIMAP;
		if (ray->end[0] < 0)
			ray->end[0] = 0;
		if (ray->end[1] < 0)
			ray->end[1] = 0;
		draw_line(ray, ray->img, 0xbad129); //draw ray
		draw_3d(game, ray, 0, &line_x);
		i++;
	}
}

void	draw_game(t_ray *ray, t_game *game, float coords[2])
{
	int	i;
	int	line_x;
	int	rounded[2];

	ray->ra = game->chars[0]->pa - 30 * ((float)M_PI / 180);
	if (ray->ra < 0)
		ray->ra += (float)M_PI * 2;
	if (game->game_img)
		mlx_delete_image(game->mlx, game->game_img);
	game->game_img = mlx_new_image(game->mlx, WIDTH, HEIGHT);
	i = 0;
	line_x = 0;
	rounded[0] = (int)coords[0];
	rounded[1] = (int)coords[1];
	reset_img(ray->img, MINIMAP, MINIMAP);
	iterate_game(game, ray, 0, rounded);
	mlx_image_to_window(game->mlx, game->game_img, 0, 0);
}
