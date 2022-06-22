#include "cub3d.h"

static void	set_coords(t_game *game, int addX, int addY)
{
	int	dir_x;
	int	dir_y;

	dir_x = game->chars[0]->w[0] * 3;
	dir_y = game->chars[0]->w[1] * 3;
	game->chars[0]->img->instances[0].x += addX;
	game->chars[0]->img->instances[0].y += addY;
	mlx_delete_image(game->mlx, game->chars[0]->ray->img);
	game->chars[0]->ray->start[0] = game->chars[0]->img->instances[0].x + 8;
	game->chars[0]->ray->start[1] = game->chars[0]->img->instances[0].y + 8;
	game->chars[0]->ray->end[0] = game->chars[0]->img->instances[0].x + dir_x + 8;
	game->chars[0]->ray->end[1] = game->chars[0]->img->instances[0].y + dir_y + 8;
	game->chars[0]->ray->img = draw_line(game, game->chars[0]->ray);
}

void	calc_rotate(t_game *game, float rotation, int n)
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
	game->chars[n]->d[0] = cos(game->chars[n]->pa + M_PI_2) * 5;
	game->chars[n]->d[1] = sin(game->chars[n]->pa + M_PI_2) * 5;
	game->chars[n]->a[0] = game->chars[n]->d[0] * -1;
	game->chars[n]->a[1] = game->chars[n]->d[1] * -1;

	game->chars[n]->ray->start[0] = x + 8;
	game->chars[n]->ray->start[1] = y + 8;
	// if (game->chars[n]->pa < M_PI && game->chars[n]->pa > 0)
	// {
	// 	game->chars[n]->ray->end[1] = (y + 8) / 32 * 32 + 32;
	// 	game->chars[n]->ray->end[0] = ((y + 8) - game->chars[n]->ray->end[1]) * (-1 / tan(game->chars[n]->pa)) + (x + 8);
	// }
	// else if (game->chars[n]->pa > M_PI)
	// {
	// 	game->chars[n]->ray->end[1] = (y + 8) / 32 * 32;
	// 	game->chars[n]->ray->end[0] = ((y + 8) - game->chars[n]->ray->end[1]) * (-1 / tan(game->chars[n]->pa)) + (x + 8);
	// }
	// else
	// {
	// 	game->chars[n]->ray->end[0] = x + 8;
	// 	game->chars[n]->ray->end[1] = y + 8;
	// }
	if (game->chars[n]->pa < M_PI_2 || game->chars[n]->pa > (M_PI_2 * 3))
	{
		game->chars[n]->ray->end[0] = (x + 8) / 32 * 32 + 32;
		game->chars[n]->ray->end[1] = ((x + 8) - game->chars[n]->ray->end[0]) * (-tan(game->chars[n]->pa)) + (y + 8);
	}
	else if (game->chars[n]->pa > M_PI_2 && game->chars[n]->pa < (M_PI_2 * 3))
	{
		game->chars[n]->ray->end[0] = (x + 8) / 32 * 32;
		game->chars[n]->ray->end[1] = ((x + 8) - game->chars[n]->ray->end[0]) * (-tan(game->chars[n]->pa)) + (y + 8);
	}
	else
	{
		game->chars[n]->ray->end[0] = x + 8;
		game->chars[n]->ray->end[1] = y + 8;
	}
	game->chars[n]->ray->img = draw_line(game, game->chars[n]->ray);
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
		calc_rotate(game, -0.1f, 0);
	if (mlx_is_key_down(game->mlx, MLX_KEY_RIGHT))
		calc_rotate(game, 0.1f, 0);
}
