#include "includes/cub3d.h"

static void	set_coords(t_game *game, int addX, int addY)
{
	int		pos_x;
	int		pos_y;
	int		circle_x;
	int		circle_y;
	float	angle;

	pos_x = game->map->player[0] + addX;
	pos_y = game->map->player[1] + addY;
	angle = 0;
	while (angle <= (float)M_PI * 2)
	{
		circle_x = (pos_x + 4 * cos(angle));
		circle_y = (pos_y + 4 * sin(angle));
		if (game->map->big_map[circle_y / 32][circle_x / 32] == '1'
			|| game->map->big_map[circle_y / 32][circle_x / 32] == '8'
			|| game->map->big_map[circle_y / 32][circle_x / 32] == '9')
			return ;
		angle += (float)M_PI / 18;
	}
	move_map(game, addX, addY);
	game->map->player[0] += addX;
	game->map->player[1] += addY;
}

static void	mouse_rotate(t_game *game)
{
	int	x;
	int	y;

	mlx_get_mouse_pos(game->mlx, &x, &y);
	x -= WIDTH / 2;
	game->chars[0]->pa += (float)x / 4000 * game->menu->settings->rs;
	mlx_set_mouse_pos(game->mlx, WIDTH / 2, HEIGHT / 2);
}

static void	open_door(t_game *game, int addX, int addY)
{
	float	x;
	float	y;
	int		next_x;
	int		next_y;

	x = game->map->player[0];
	y = game->map->player[1];
	next_x = (x + addX * 16) / 32;
	next_y = (y + addY * 16) / 32;
	if (game->map->big_map[next_y][next_x] == '8'
		|| game->map->big_map[next_y][next_x] == '9')
		game->map->big_map[next_y][next_x] = '7';
}

static void	check_keys(t_game *game)
{
	if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
		to_menu(game);
	if (mlx_is_key_down(game->mlx, MLX_KEY_SPACE))
		system("say -v Fred I think I should go to the gym more often... &");
	if (mlx_is_key_down(game->mlx, MLX_KEY_W))
		set_coords(game, game->chars[0]->w[0], game->chars[0]->w[1]);
	if (mlx_is_key_down(game->mlx, MLX_KEY_A))
		set_coords(game, game->chars[0]->a[0], game->chars[0]->a[1]);
	if (mlx_is_key_down(game->mlx, MLX_KEY_S))
		set_coords(game, game->chars[0]->s[0], game->chars[0]->s[1]);
	if (mlx_is_key_down(game->mlx, MLX_KEY_D))
		set_coords(game, game->chars[0]->d[0], game->chars[0]->d[1]);
	if (mlx_is_key_down(game->mlx, MLX_KEY_LEFT))
		game->chars[0]->pa -= 0.03f * game->menu->settings->rs;
	if (mlx_is_key_down(game->mlx, MLX_KEY_RIGHT))
		game->chars[0]->pa += 0.03f * game->menu->settings->rs;
	if (mlx_is_key_down(game->mlx, MLX_KEY_F))
		open_door(game, game->chars[0]->w[0], game->chars[0]->w[1]);
	if (mlx_is_key_down(game->mlx, MLX_KEY_LEFT_SHIFT))
		game->ps = 4;
	else
		game->ps = 2;
}

static int	find_instance(t_game *game, int x, int y)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (i < game->map->y)
	{
		j = 0;
		while (j < game->map->x)
		{
			if (i == y && j == x)
				return (count);
			if (game->map->big_map[i][j] == 'L' || game->map->big_map[i][j] == 'l')
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

static void	check_pos(t_game *game)
{
	int	player_x;
	int	player_y;

	player_x = game->map->player[0] / 32;
	player_y = game->map->player[1] / 32;
	if (game->map->big_map[player_y][player_x] == 'X')
		mlx_close_window(game->mlx);
	else if (game->map->big_map[player_y][player_x] == 'L')
	{
		game->loot++;
		game->map->chest->instances[find_instance(game, player_x, player_y)].enabled = false;
		game->map->big_map[player_y][player_x] = 'l';
	}
}

void	fps(void *tmp)
{
	t_game	*game;

	game = tmp;
	if (game->menu->in_menu == true)
	{
		animate_menu(game->menu);
		game->game_img->enabled = false;
	}
	else
	{
		mouse_rotate(game);
		check_keys(game);
		calc_rotate(game, 0.0f, 0);
		check_pos(game);
		draw_game(game->chars[0]->ray, game, game->map->player);
		draw_crosshair(game, 0xFFFFFFFF, game->menu->settings->cross_type);
	}
}
