#include "../includes/main_menu.h"

static void	put_to_win(t_game *game)
{
	int	i;

	i = 13;
	while (i < 33)
	{
		mlx_image_to_window(game->mlx, game->menu->imgs[i], WIDTH - 850, 60);
		i++;
	}
	mlx_image_to_window(game->mlx, game->menu->imgs[33], 1334, 288);
	mlx_image_to_window(game->mlx, game->menu->imgs[34], 1372, 405);
	mlx_image_to_window(game->mlx, game->menu->imgs[35], 1418, 519);
	mlx_image_to_window(game->mlx, game->menu->imgs[36], 1408, 633);
	mlx_image_to_window(game->mlx, game->menu->imgs[37], 1425, 666);
	mlx_image_to_window(game->mlx, game->menu->imgs[38], 1425, 666);
	mlx_image_to_window(game->mlx, game->menu->imgs[39], 1475, 666);
	mlx_image_to_window(game->mlx, game->menu->imgs[40], 1475, 666);
	mlx_image_to_window(game->mlx, game->menu->imgs[41], 1525, 666);
	mlx_image_to_window(game->mlx, game->menu->imgs[42], 1525, 666);
}

static void	init_scroll(t_game *game)
{
	load_png(game, 13, "./sprites/main/scroll/scroll.png", false);
	load_png(game, 14, "./sprites/main/scroll/scroll1.png", false);
	load_png(game, 15, "./sprites/main/scroll/scroll2.png", false);
	load_png(game, 16, "./sprites/main/scroll/scroll3.png", false);
	load_png(game, 17, "./sprites/main/scroll/scroll4.png", false);
	load_png(game, 18, "./sprites/main/scroll/scroll5.png", false);
	load_png(game, 19, "./sprites/main/scroll/scroll6.png", false);
	load_png(game, 20, "./sprites/main/scroll/scroll7.png", false);
	load_png(game, 21, "./sprites/main/scroll/scroll8.png", false);
	load_png(game, 22, "./sprites/main/scroll/scroll9.png", false);
	load_png(game, 23, "./sprites/main/scroll/scroll10.png", false);
	load_png(game, 24, "./sprites/main/scroll/scroll11.png", false);
	load_png(game, 25, "./sprites/main/scroll/scroll12.png", false);
	load_png(game, 26, "./sprites/main/scroll/scroll13.png", false);
	load_png(game, 27, "./sprites/main/scroll/scroll14.png", false);
	load_png(game, 28, "./sprites/main/scroll/scroll15.png", false);
	load_png(game, 29, "./sprites/main/scroll/scroll16.png", false);
	load_png(game, 30, "./sprites/main/scroll/scroll17.png", false);
	load_png(game, 31, "./sprites/main/scroll/scroll18.png", false);
	load_png(game, 32, "./sprites/main/scroll/scroll19.png", false);
}

static void	init_text(t_game *game)
{
	load_png(game, 33, "./sprites/main/settings/sens.png", false);
	load_png(game, 34, "./sprites/main/settings/fov.png", false);
	load_png(game, 35, "./sprites/main/settings/graphics.png", false);
	load_png(game, 36, "./sprites/main/settings/crosshair.png", false);
	load_png(game, 37, "./sprites/main/settings/circle.png", false);
	load_png(game, 38, "./sprites/main/settings/circle_s.png", false);
	load_png(game, 39, "./sprites/main/settings/cross.png", false);
	load_png(game, 40, "./sprites/main/settings/cross_s.png", false);
	load_png(game, 41, "./sprites/main/settings/dot.png", false);
	load_png(game, 42, "./sprites/main/settings/dot_s.png", false);
}

void	init_settings(t_game *game)
{
	init_scroll(game);
	init_text(game);
	put_to_win(game);
}
