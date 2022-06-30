#include "main_menu.h"

void	start_game(t_game *game)
{
	int	i;

	i = 0;
	game->menu->in_menu = false;
	mlx_set_cursor_mode(game->mlx, MLX_MOUSE_HIDDEN);
	while (i < 11)
	{
		game->menu->imgs[i]->enabled = false;
		i++;
	}
	draw_map(game, game->map, game->map->player);
	draw_crosshair(game->mlx, 0xFFFFFFAA);
}

static void	create_buttons(t_game *game, mlx_texture_t *txt)
{
	txt = mlx_load_png("./sprites/title.png");
	game->menu->imgs[6] = mlx_texture_to_image(game->mlx, txt);
	mlx_delete_texture(txt);
	txt = mlx_load_png("./sprites/start_game.png");
	game->menu->imgs[7] = mlx_texture_to_image(game->mlx, txt);
	mlx_delete_texture(txt);
	txt = mlx_load_png("./sprites/start_game_hover.png");
	game->menu->imgs[8] = mlx_texture_to_image(game->mlx, txt);
	game->menu->imgs[8]->enabled = false;
	mlx_delete_texture(txt);
	txt = mlx_load_png("./sprites/exit.png");
	game->menu->imgs[9] = mlx_texture_to_image(game->mlx, txt);
	mlx_delete_texture(txt);
	txt = mlx_load_png("./sprites/exit_hover.png");
	game->menu->imgs[10] = mlx_texture_to_image(game->mlx, txt);
	game->menu->imgs[10]->enabled = false;
	mlx_delete_texture(txt);
	mlx_image_to_window(game->mlx, game->menu->imgs[6], 100, 40);
	mlx_image_to_window(game->mlx, game->menu->imgs[7], 120, 250);
	mlx_image_to_window(game->mlx, game->menu->imgs[8], 120, 250);
	mlx_image_to_window(game->mlx, game->menu->imgs[9], 120, 350);
	mlx_image_to_window(game->mlx, game->menu->imgs[10], 120, 350);
}

static void	create_background(t_game *game, mlx_texture_t *txt, int frame)
{
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
	while (frame < 6)
	{
		mlx_image_to_window(game->mlx, game->menu->imgs[frame], 0, 0);
		game->menu->imgs[frame]->enabled = false;
		frame++;
	}
}

void	main_menu(t_game *game)
{
	mlx_texture_t	*txt;

	game->menu = malloc(sizeof(t_menu));
	if (game->menu == NULL)
		ft_error("Malloc error!", NULL);
	txt = NULL;
	create_background(game, txt, 0);
	create_buttons(game, txt);
	game->menu->frame = 0;
	game->menu->in_menu = true;
	mlx_loop_hook(game->mlx, &animate_menu, game->menu);
	mlx_mouse_hook(game->mlx, &menu_buttons, game);
	mlx_cursor_hook(game->mlx, &hover_buttons, game);
}
