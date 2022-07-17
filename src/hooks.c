#include "includes/cub3d.h"

static void	check_music(t_game *game, bool moving)
{
	struct timeval	time;
	long			micsec;

	if (gettimeofday(&time, NULL) == -1)
		ft_error("Error while reading the time", NULL);
	micsec = time.tv_sec * 1000 + time.tv_usec / 1000;
	if (time.tv_sec > game->sounds->music_start + 135)
	{
		game->sounds->music_start = time.tv_sec;
		system("afplay -v 0.5 ./music/background.mp3 &");
	}
	else if (moving == true && micsec > game->sounds->step + 1400 / game->ps)
	{
		game->sounds->step = time.tv_sec * 1000 + time.tv_usec / 1000;
		system("afplay -v 3 ./music/step.mp3 &");
	}
}

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
	if (game->sounds->sound == true)
		check_music(game, true);
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

static void	check_keys(t_game *game)
{
	if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
		to_menu(game);
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

void	fps(void *tmp)
{
	t_game	*game;

	game = tmp;
	if (game->end->in_end == true)
	{
		animate_end(game->end);
		game->game_img->enabled = false;
	}
	else if (game->menu->in_menu == false)
	{
		mouse_rotate(game);
		check_keys(game);
		calc_rotate(game, 0.0f, 0);
		check_pos(game);
		draw_game(game, game->chars[0]->ray);
		draw_crosshair(game, 0xFFFFFFFF, game->menu->settings->cross_type);
		if (game->sounds->sound == true)
			check_music(game, false);
	}
	else
	{
		animate_menu(game);
		game->game_img->enabled = false;
	}
}
