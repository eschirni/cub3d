#include "../includes/main_menu.h"

static void	reset_hover(t_game *game)
{
	if (game->menu->started_game == true)
		game->menu->imgs[65]->enabled = true;
	else
		game->menu->imgs[7]->enabled = true;
	game->menu->imgs[66]->enabled = false;
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
		if (game->menu->started_game == true)
		{
			game->menu->imgs[66]->enabled = true;
			return ;
		}
		game->menu->imgs[8]->enabled = true;
	}
	else if (x >= 120 && x <= 374 && y >= 350 && y <= 415)
		game->menu->imgs[10]->enabled = true;
	else if (x >= 120 && x <= 238 && y >= 450 && y <= 506)
		game->menu->imgs[12]->enabled = true;
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
	else if (game->menu->scroll_mode == 'O')
		menu_sliders(game, x, y);
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
