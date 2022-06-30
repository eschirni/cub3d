#include "main_menu.h"

void	animate_menu(void *tmp)
{
	t_menu	*menu;
	int		i;

	menu = tmp;
	if (menu->in_menu == false)
		return ;
	usleep(150000); //use timesteps
	i = 0;
	while (i < 6)
	{
		menu->imgs[i]->enabled = false;
		i++;
	}
	menu->imgs[menu->frame]->enabled = true;
	menu->frame++;
	if (menu->frame > 5)
		menu->frame = 0;
}

void	hover_buttons(double x, double y, t_game *game)
{
	if (game->menu->in_menu == false)
		return ;
	game->menu->imgs[7]->enabled = true;
	game->menu->imgs[8]->enabled = false;
	game->menu->imgs[9]->enabled = true;
	game->menu->imgs[10]->enabled = false;
	game->menu->imgs[11]->enabled = true;
	game->menu->imgs[12]->enabled = false;
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
			start_game(game);
		else if (x >= 120 && x <= 374 && y >= 350 && y <= 415)
			printf("settings\n");
		else if (x >= 120 && x <= 238 && y >= 450 && y <= 506)
			mlx_close_window(game->mlx);
	}
}