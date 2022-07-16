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
	int		line_x;
	t_ray	*mini;

	line_x = 0;
	mini = malloc(sizeof(t_ray));
	if (mini == NULL)
		ft_error("Allocation error!\n", NULL);
	while (i < game->menu->settings->fov)
	{
		ray->ra += (float)M_PI / 180 / game->menu->settings->graphics;
		if (ray->ra >= (float)M_PI * 2)
			ray->ra -= (float)M_PI * 2;
		ray->dist = calc_rays(ray, game->map, coords[0], coords[1]);
		mini->start[0] = ray->start[0] - (game->map->player[0] - 144);
		mini->start[1] = ray->start[1] - (game->map->player[1] - 144);
		mini->end[0] = ray->end[0] - (game->map->player[0] - 144);
		mini->end[1] = ray->end[1] - (game->map->player[1] - 144);
		draw_line(mini, ray->img); //draw ray
		draw_3d(game, ray, 0, &line_x);
		i++;
	}
	free(mini);
}

void	draw_game(t_game *game, t_ray *ray)
{
	int	i;
	int	line_x;
	int	rounded[2];

	ray->ra = game->chars[0]->pa - 30 * ((float)M_PI / 180);
	if (ray->ra < 0)
		ray->ra += (float)M_PI * 2;
	mlx_delete_image(game->mlx, game->game_img);
	game->game_img = mlx_new_image(game->mlx, WIDTH, HEIGHT);
	i = 0;
	line_x = 0;
	rounded[0] = (int)game->map->player[0];
	rounded[1] = (int)game->map->player[1];
	reset_img(ray->img, MINIMAP, MINIMAP);
	iterate_game(game, ray, 0, rounded);
	mlx_image_to_window(game->mlx, game->game_img, 0, 0);
}
