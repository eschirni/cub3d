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
	mlx_image_to_window(game->mlx, game->menu->imgs[43], 1400, 350);
	mlx_image_to_window(game->mlx, game->menu->imgs[44], 1400, 350);
	mlx_image_to_window(game->mlx, game->menu->imgs[45], 1400, 350);
	mlx_image_to_window(game->mlx, game->menu->imgs[46], 1400, 350);
	mlx_image_to_window(game->mlx, game->menu->imgs[47], 1400, 350);
	mlx_image_to_window(game->mlx, game->menu->imgs[48], 1400, 350);
	mlx_image_to_window(game->mlx, game->menu->imgs[49], 1400, 350);
	mlx_image_to_window(game->mlx, game->menu->imgs[50], 1400, 350);
	mlx_image_to_window(game->mlx, game->menu->imgs[51], 1400, 470);
	mlx_image_to_window(game->mlx, game->menu->imgs[52], 1400, 470);
	mlx_image_to_window(game->mlx, game->menu->imgs[53], 1400, 470);
	mlx_image_to_window(game->mlx, game->menu->imgs[54], 1400, 470);
	mlx_image_to_window(game->mlx, game->menu->imgs[55], 1400, 470);
	mlx_image_to_window(game->mlx, game->menu->imgs[56], 1400, 470);
	mlx_image_to_window(game->mlx, game->menu->imgs[57], 1400, 470);
	mlx_image_to_window(game->mlx, game->menu->imgs[58], 1400, 470);
	mlx_image_to_window(game->mlx, game->menu->imgs[59], 1400, 575);
	mlx_image_to_window(game->mlx, game->menu->imgs[60], 1400, 575);
	mlx_image_to_window(game->mlx, game->menu->imgs[61], 1400, 575);
	mlx_image_to_window(game->mlx, game->menu->imgs[62], 1400, 575);
	mlx_image_to_window(game->mlx, game->menu->imgs[63], 1400, 575);
	mlx_image_to_window(game->mlx, game->menu->imgs[64], 1400, 575);
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

static void	init_arrows(t_game *game)
{
	//rs
	load_png(game, 43, "./sprites/main/settings/slider.png", false);
	load_png(game, 44, "./sprites/main/settings/slider1.png", false);
	load_png(game, 45, "./sprites/main/settings/slider2.png", false);
	load_png(game, 46, "./sprites/main/settings/slider3.png", false);
	load_png(game, 47, "./sprites/main/settings/slider4.png", false);
	load_png(game, 48, "./sprites/main/settings/slider5.png", false);
	load_png(game, 49, "./sprites/main/settings/slider6.png", false);
	load_png(game, 50, "./sprites/main/settings/slider7.png", false);
	//fov
	load_png(game, 51, "./sprites/main/settings/slider.png", false);
	load_png(game, 52, "./sprites/main/settings/slider1.png", false);
	load_png(game, 53, "./sprites/main/settings/slider2.png", false);
	load_png(game, 54, "./sprites/main/settings/slider3.png", false);
	load_png(game, 55, "./sprites/main/settings/slider4.png", false);
	load_png(game, 56, "./sprites/main/settings/slider5.png", false);
	load_png(game, 57, "./sprites/main/settings/slider6.png", false);
	load_png(game, 58, "./sprites/main/settings/slider7.png", false);
	//graphics
	load_png(game, 59, "./sprites/main/settings/slider7.png", false);
	load_png(game, 60, "./sprites/main/settings/slider5.png", false);
	load_png(game, 61, "./sprites/main/settings/slider4.png", false);
	load_png(game, 62, "./sprites/main/settings/slider3.png", false);
	load_png(game, 63, "./sprites/main/settings/slider2.png", false);
	load_png(game, 64, "./sprites/main/settings/slider.png", false);
}

static void	init_text(t_game *game)
{
	load_png(game, 33, "./sprites/main/settings/sens.png", false);
	load_png(game, 34, "./sprites/main/settings/fov.png", false);
	load_png(game, 35, "./sprites/main/settings/graphics.png", false);
	load_png(game, 36, "./sprites/main/settings/crosshair.png", false);
	load_png(game, 37, "./sprites/main/settings/circle.png", false);
	load_png(game, 38, "./sprites/main/settings/circle_s.png", false);
	load_png(game, 39, "./sprites/main/settings/dot.png", false);
	load_png(game, 40, "./sprites/main/settings/dot_s.png", false);
	load_png(game, 41, "./sprites/main/settings/cross.png", false);
	load_png(game, 42, "./sprites/main/settings/cross_s.png", false);
}

void	init_settings(t_game *game) //grafics option sucks
{
	init_scroll(game);
	init_text(game);
	init_arrows(game);
	put_to_win(game);
}
