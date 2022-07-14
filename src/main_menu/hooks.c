#include "../includes/main_menu.h"

static void	settings_buttons(t_game *game, int x, int y)
{
	if (x >= 1425 && x <= 1467 && y >= 666 && y <= 708)
	{
		game->menu->imgs[37]->enabled = false;
		game->menu->imgs[40]->enabled = false;
		game->menu->imgs[42]->enabled = false;
		game->menu->imgs[38]->enabled = true;
		game->menu->settings->cross_type = 'C';
	}
	else if (x >= 1475 && x <= 1517 && y >= 666 && y <= 708)
	{
		game->menu->imgs[38]->enabled = false;
		game->menu->imgs[39]->enabled = false;
		game->menu->imgs[42]->enabled = false;
		game->menu->imgs[40]->enabled = true;
		game->menu->settings->cross_type = 'D';
	}
	else if (x >= 1525 && x <= 1567 && y >= 666 && y <= 708)
	{
		game->menu->imgs[38]->enabled = false;
		game->menu->imgs[40]->enabled = false;
		game->menu->imgs[41]->enabled = false;
		game->menu->imgs[42]->enabled = true;
		game->menu->settings->cross_type = 'E';
	}
}

static void	play_music(t_game *game)
{
	system("pkill afplay &");
	game->sounds->sound = !game->sounds->sound;
	if (game->sounds->sound == true)
		system("afplay ./music/main_menu.mp3 &");
	game->menu->imgs[67]->enabled = !game->menu->imgs[67]->enabled;
	game->menu->imgs[68]->enabled = !game->menu->imgs[68]->enabled;
}

static void	on_mouse_click(t_game *game, int x, int y)
{
	if (x >= 120 && x <= 461 && y >= 250 && y <= 315)
		to_game(game);
	else if (x >= 120 && x <= 374 && y >= 350 && y <= 415)
	{
		if (game->menu->scroll_mode == 'O')
			game->menu->scroll_mode = 'C';
		else
			game->menu->scroll_mode = 'O';
	}
	else if (x >= 120 && x <= 238 && y >= 450 && y <= 506)
	{
		system("pkill afplay");
		mlx_close_window(game->mlx);
	}
	else if (x >= 1840 && x <= 1888 && y >= 1000 && y <= 1048)
		play_music(game);
	else if (game->menu->scroll_mode == 'O')
	{
		settings_buttons(game, x, y);
		menu_sliders(game, x, y);
	}
}

void	menu_buttons(mouse_key_t k, action_t act, modifier_key_t mod, void *tmp)
{
	t_game	*game;
	int		x;
	int		y;

	game = tmp;
	k = 0;
	act = 0;
	mod = 0;
	mlx_get_mouse_pos(game->mlx, &x, &y);
	if (mlx_is_mouse_down(game->mlx, MLX_MOUSE_BUTTON_LEFT))
		on_mouse_click(game, x, y);
}
