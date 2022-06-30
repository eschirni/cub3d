#include "cub3d.h"

static void	start_game(t_game *game)
{
	int	i;

	i = 0;
	game->menu->in_menu = false;
	while (i < 11)
	{
		game->menu->imgs[i]->enabled = false;
		i++;
	}
	draw_map(game, game->map, game->map->player);
	draw_crosshair(game->mlx, 0xFFFFFFAA);
}

static void	animate_menu(void *tmp)
{
	t_menu	*menu;
	int		i;

	menu = tmp;
	if (menu->in_menu == false)
		return ;
	usleep(150000); //need to find another way, this also slows down everything else
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

static void	menu_buttons(mouse_key_t key, action_t act, modifier_key_t mod, void *tmp)
{
	t_game	*game;
	int		x;
	int		y;

	game = tmp;
	mlx_get_mouse_pos(game->mlx, &x, &y);
	if (mlx_is_mouse_down(game->mlx, MLX_MOUSE_BUTTON_LEFT))
	{
		if (x >= 120 && x <= 461 && y >= 250 && y <= 315)
			start_game(game);
		else if (x >= 120 && x <= 238 && y >= 350 && y <= 406)
			mlx_close_window(game->mlx);
	}
}

static void	hover_buttons(double x, double y, void *tmp)
{
	t_game	*game;

	game = tmp;
	if (game->menu->in_menu == false)
		return ;
	game->menu->imgs[7]->enabled = true;
	game->menu->imgs[8]->enabled = false;
	game->menu->imgs[9]->enabled = true;
	game->menu->imgs[10]->enabled = false;
	if (x >= 120 && x <= 461 && y >= 250 && y <= 315)
	{
		game->menu->imgs[7]->enabled = false;
		game->menu->imgs[8]->enabled = true;
	}
	else if (x >= 120 && x <= 238 && y >= 350 && y <= 406)
	{
		game->menu->imgs[9]->enabled = false;
		game->menu->imgs[10]->enabled = true;
	}
}

void	main_menu(t_game *game)
{
	int				i;
	int				pid;
	mlx_texture_t	*txt;

	game->menu = malloc(sizeof(t_menu));
	txt = mlx_load_png("./sprites/background.png");
	game->menu->imgs[0] = mlx_texture_to_image(game->mlx, txt);
	mlx_delete_texture(txt);
	txt = mlx_load_png("./sprites/background1.png");
	game->menu->imgs[1] = mlx_texture_to_image(game->mlx, txt);
	mlx_delete_texture(txt);
	txt = mlx_load_png("./sprites/background2.png");
	game->menu->imgs[2] = mlx_texture_to_image(game->mlx, txt);
	mlx_delete_texture(txt);
	txt = mlx_load_png("./sprites/background3.png");
	game->menu->imgs[3] = mlx_texture_to_image(game->mlx, txt);
	mlx_delete_texture(txt);
	txt = mlx_load_png("./sprites/background4.png");
	game->menu->imgs[4] = mlx_texture_to_image(game->mlx, txt);
	mlx_delete_texture(txt);
	txt = mlx_load_png("./sprites/background5.png");
	game->menu->imgs[5] = mlx_texture_to_image(game->mlx, txt);
	mlx_delete_texture(txt);

	/* title */
	txt = mlx_load_png("./sprites/title.png");
	game->menu->imgs[6] = mlx_texture_to_image(game->mlx, txt);
	mlx_delete_texture(txt);
	/* start */
	txt = mlx_load_png("./sprites/start_game.png");
	game->menu->imgs[7] = mlx_texture_to_image(game->mlx, txt);
	mlx_delete_texture(txt);
	txt = mlx_load_png("./sprites/start_game_hover.png");
	game->menu->imgs[8] = mlx_texture_to_image(game->mlx, txt);
	game->menu->imgs[8]->enabled = false;
	mlx_delete_texture(txt);
	/* exit */
	txt = mlx_load_png("./sprites/exit.png");
	game->menu->imgs[9] = mlx_texture_to_image(game->mlx, txt);
	mlx_delete_texture(txt);
	txt = mlx_load_png("./sprites/exit_hover.png");
	game->menu->imgs[10] = mlx_texture_to_image(game->mlx, txt);
	game->menu->imgs[10]->enabled = false;
	mlx_delete_texture(txt);
	i = 0;
	while (i < 6)
	{
		mlx_image_to_window(game->mlx, game->menu->imgs[i], 0, 0);
		game->menu->imgs[i]->enabled = false;
		i++;
	}
	mlx_image_to_window(game->mlx, game->menu->imgs[6], 100, 40);
	mlx_image_to_window(game->mlx, game->menu->imgs[7], 120, 250);
	mlx_image_to_window(game->mlx, game->menu->imgs[8], 120, 250);
	mlx_image_to_window(game->mlx, game->menu->imgs[9], 120, 350);
	mlx_image_to_window(game->mlx, game->menu->imgs[10], 120, 350);
	game->menu->frame = 0;
	game->menu->in_menu = true;
	mlx_loop_hook(game->mlx, &animate_menu, game->menu);
	mlx_mouse_hook(game->mlx, &menu_buttons, game);
	mlx_cursor_hook(game->mlx, &hover_buttons, game);
}
