#include "../includes/main_menu.h"

static void	reset_hover(t_game *game)
{
	game->menu->imgs[7]->enabled = true;
	game->menu->imgs[8]->enabled = false;
	game->menu->imgs[9]->enabled = true;
	game->menu->imgs[10]->enabled = false;
	game->menu->imgs[11]->enabled = true;
	game->menu->imgs[12]->enabled = false;
}

void	hover_buttons(double x, double y, void *tmp)
{
	t_game	*game;

	game = tmp;
	if (game->menu->in_menu == false)
		return ;
	reset_hover(game);
	if (x >= 120 && x <= 461 && y >= 250 && y <= 315)
	{
		game->menu->imgs[7]->enabled = false;
		game->menu->imgs[8]->enabled = true;
	}
	else if (x >= 120 && x <= 374 && y >= 350 && y <= 415)
	{
		game->menu->imgs[9]->enabled = false;
		game->menu->imgs[10]->enabled = true;
	}
	else if (x >= 120 && x <= 238 && y >= 450 && y <= 506)
	{
		game->menu->imgs[11]->enabled = false;
		game->menu->imgs[12]->enabled = true;
	}
}

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

static void	menu_sliders(t_game *game, int x, int y)
{
	if (x >= 1410 && x <= 1420 && y >= 350 && y <= 367)
		game->menu->settings->rs = 0.25f;
	else if (x >= 1421 && x <= 1430 && y >= 350 && y <= 367)
		game->menu->settings->rs = 0.5f;
	else if (x >= 1431 && x <= 1440 && y >= 350 && y <= 367)
		game->menu->settings->rs = 0.75f;
	else if (x >= 1441 && x <= 1450 && y >= 350 && y <= 367)
		game->menu->settings->rs = 1;
	else if (x >= 1451 && x <= 1460 && y >= 350 && y <= 367)
		game->menu->settings->rs = 1.25f;
	else if (x >= 1461 && x <= 1470 && y >= 350 && y <= 367)
		game->menu->settings->rs = 1.5f;
	else if (x >= 1471 && x <= 1480 && y >= 350 && y <= 367)
		game->menu->settings->rs = 1.75f;
	else if (x >= 1481 && x <= 1490 && y >= 350 && y <= 367)
		game->menu->settings->rs = 2;
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
			mlx_close_window(game->mlx);
		else if (game->menu->scroll_mode == 'O')
		{
			settings_buttons(game, x, y);
			menu_sliders(game, x, y);
		}
	}
}
