#include "cub3d.h"

static void	draw_rays(t_ray *ray, t_game *game, int x, int y)
{
	float	ra;
	int		i;

	ra = game->chars[0]->pa - 30 * ((float)M_PI / 180);
	if (ra < 0)
		ra += (float)M_PI * 2;
	ray->img = mlx_new_image(game->mlx, game->mlx->width, game->mlx->height);
	i = 0;
	while (i < 61)
	{
		ra += (float)M_PI / 180;
		if (ra >= (float)M_PI * 2)
			ra -= (float)M_PI * 2;
		calc_rays(ray, game->map, ra, x, y);
		draw_line(game, ray, ray->img);
		i++;
	}
	mlx_image_to_window(game->mlx, ray->img, 0, 0);
}

void	calc_rotate(t_game *game, t_map *map, float rotation, int n)
{
	int		x;
	int		y;

	x = game->chars[n]->img->instances[0].x;
	y = game->chars[n]->img->instances[0].y;
	mlx_delete_image(game->mlx, game->chars[n]->ray->img);
	game->chars[n]->pa += rotation;
	if (game->chars[n]->pa < 0)
		game->chars[n]->pa = (float)(M_PI * 2);
	else if (game->chars[n]->pa > (float)M_PI * 2)
		game->chars[n]->pa = 0.1f;
	game->chars[n]->w[0] = cos(game->chars[n]->pa) * 5; //make w to float (idea)
	game->chars[n]->w[1] = sin(game->chars[n]->pa) * 5;
	game->chars[n]->s[0] = game->chars[n]->w[0] * -1;
	game->chars[n]->s[1] = game->chars[n]->w[1] * -1;
	game->chars[n]->d[0] = cos(game->chars[n]->pa + (float)M_PI_2) * 5;
	game->chars[n]->d[1] = sin(game->chars[n]->pa + (float)M_PI_2) * 5;
	game->chars[n]->a[0] = game->chars[n]->d[0] * -1;
	game->chars[n]->a[1] = game->chars[n]->d[1] * -1;
	draw_rays(game->chars[n]->ray, game, x + 8, y + 8);
}

static void	set_coords(t_game *game, int addX, int addY)
{
	game->chars[0]->img->instances[0].x += addX;
	game->chars[0]->img->instances[0].y += addY;
	calc_rotate(game, game->map, 0.0f, 0);
}

void	hook(void *tmp)
{
	t_game	*game;

	game = tmp;
	if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(game->mlx);
	if (mlx_is_key_down(game->mlx, MLX_KEY_W))
		set_coords(game, game->chars[0]->w[0], game->chars[0]->w[1]);
	if (mlx_is_key_down(game->mlx, MLX_KEY_A))
		set_coords(game, game->chars[0]->a[0], game->chars[0]->a[1]);
	if (mlx_is_key_down(game->mlx, MLX_KEY_S))
		set_coords(game, game->chars[0]->s[0], game->chars[0]->s[1]);
	if (mlx_is_key_down(game->mlx, MLX_KEY_D))
		set_coords(game, game->chars[0]->d[0], game->chars[0]->d[1]);
	if (mlx_is_key_down(game->mlx, MLX_KEY_LEFT))
		calc_rotate(game, game->map, -0.06f, 0);
	if (mlx_is_key_down(game->mlx, MLX_KEY_RIGHT))
		calc_rotate(game, game->map, 0.06f, 0);
}
