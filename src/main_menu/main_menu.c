#include "../includes/main_menu.h"

void	load_png(t_game *game, int pos, char *name, bool enabled)
{
	mlx_texture_t	*txt;

	txt = mlx_load_png(name);
	game->menu->imgs[pos] = mlx_texture_to_image(game->mlx, txt);
	mlx_delete_texture(txt);
	game->menu->imgs[pos]->enabled = enabled;
}

static void	create_buttons(t_game *game)
{
	load_png(game, 6, "./sprites/main/title.png", true);
	load_png(game, 7, "./sprites/main/button/start_game.png", true);
	load_png(game, 8, "./sprites/main/button/start_game_hover.png", false);
	load_png(game, 9, "./sprites/main/button/settings.png", true);
	load_png(game, 10, "./sprites/main/button/settings_hover.png", false);
	load_png(game, 11, "./sprites/main/button/exit.png", true);
	load_png(game, 12, "./sprites/main/button/exit_hover.png", false);
	load_png(game, 65, "./sprites/main/button/continue.png", false);
	load_png(game, 66, "./sprites/main/button/continue_hover.png", false);
	mlx_image_to_window(game->mlx, game->menu->imgs[6], 100, 40);
	mlx_image_to_window(game->mlx, game->menu->imgs[7], 120, 250);
	mlx_image_to_window(game->mlx, game->menu->imgs[8], 120, 250);
	mlx_image_to_window(game->mlx, game->menu->imgs[65], 120, 250);
	mlx_image_to_window(game->mlx, game->menu->imgs[66], 120, 250);
	mlx_image_to_window(game->mlx, game->menu->imgs[9], 120, 350);
	mlx_image_to_window(game->mlx, game->menu->imgs[10], 120, 350);
	mlx_image_to_window(game->mlx, game->menu->imgs[11], 120, 450);
	mlx_image_to_window(game->mlx, game->menu->imgs[12], 120, 450);
}

static void	create_background(t_game *game)
{
	int	i;

	load_png(game, 0, "./sprites/main/back/background.png", true);
	load_png(game, 1, "./sprites/main/back/background1.png", false);
	load_png(game, 2, "./sprites/main/back/background2.png", false);
	load_png(game, 3, "./sprites/main/back/background3.png", false);
	load_png(game, 4, "./sprites/main/back/background4.png", false);
	load_png(game, 5, "./sprites/main/back/background5.png", false);
	i = 0;
	while (i < 6)
	{
		mlx_image_to_window(game->mlx, game->menu->imgs[i], 0, 0);
		i++;
	}
}

//continue button when already started the game
void	main_menu(t_game *game)
{
	game->menu = malloc(sizeof(t_menu));
	if (game->menu == NULL)
		ft_error("Malloc error!", NULL);
	create_background(game);
	create_buttons(game);
	init_settings(game);
	init_textures(game);
	to_game(game);
	mlx_loop_hook(game->mlx, &fps, game);
	mlx_cursor_hook(game->mlx, &hover_buttons, game);
	mlx_mouse_hook(game->mlx, &menu_buttons, game);
}
