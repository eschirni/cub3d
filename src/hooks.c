#include "includes/cub3d.h"

void	calc_rotate(t_game *game, float rotation, int n) // only draw the tiles max around the player for the minimap, that way we can use the same calculations, but draw the minimap and 3d the same way
{
	int		x;
	int		y;

	x = game->chars[n]->img->instances[0].x;
	y = game->chars[n]->img->instances[0].y;
	game->chars[n]->pa += rotation;
	if (game->chars[n]->pa < 0)
		game->chars[n]->pa += (float)M_PI * 2;
	else if (game->chars[n]->pa >= (float)M_PI * 2)
		game->chars[n]->pa -= (float)M_PI * 2;
	game->chars[n]->w[0] = roundf(cos(game->chars[n]->pa) * 3);
	game->chars[n]->w[1] = roundf(sin(game->chars[n]->pa) * 3);
	game->chars[n]->s[0] = game->chars[n]->w[0] * -1;
	game->chars[n]->s[1] = game->chars[n]->w[1] * -1;
	game->chars[n]->d[0] = roundf(cos(game->chars[n]->pa + (float)M_PI_2) * 3);
	game->chars[n]->d[1] = roundf(sin(game->chars[n]->pa + (float)M_PI_2) * 3);
	game->chars[n]->a[0] = game->chars[n]->d[0] * -1;
	game->chars[n]->a[1] = game->chars[n]->d[1] * -1;
}

static void	set_coords(t_game *game, int addX, int addY)
{
	int		pos_x;
	int		pos_y;
	int		circle_x;
	int		circle_y;
	float	angle;

	pos_x = game->chars[0]->img->instances[0].x + 8 + addX;
	pos_y = game->chars[0]->img->instances[0].y + 8 + addY;
	angle = 0;
	while (angle <= (float)M_PI * 2)
	{
		circle_x = (pos_x + 4 * cos(angle));
		circle_y = (pos_y + 4 * sin(angle));
		if (game->map->map_arr[circle_y / 32][circle_x / 32] == '1')
			return ;
		angle += (float)M_PI / 18;
	}
	game->chars[0]->img->instances[0].x += addX;
	game->chars[0]->img->instances[0].y += addY;
	calc_rotate(game, 0.0f, 0);
}

static void	mouse_rotate(t_game *game)
{
	int	x;
	int	y;

	mlx_get_mouse_pos(game->mlx, &x, &y);
	x -= WIDTH / 2;
	game->chars[0]->pa += (float)x / 4000;
	mlx_set_mouse_pos(game->mlx, WIDTH / 2, HEIGHT / 2);
}

static void	check_keys(t_game *game)
{
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
		game->chars[0]->pa -= 0.03f;
	if (mlx_is_key_down(game->mlx, MLX_KEY_RIGHT))
		game->chars[0]->pa += 0.03f;
}

void	fps(void *tmp)
{
	t_game	*game;

	game = tmp;

	if (game->menu->in_menu == true)
		animate_menu(game->menu);
	else
	{
		mouse_rotate(game);
		check_keys(game);
		calc_rotate(game, 0.0f, 0);
		draw_game(game->chars[0]->ray, game, game->chars[0]->img->instances[0].x + 8, game->chars[0]->img->instances[0].y + 8);
	}
}
