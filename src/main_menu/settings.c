#include "main_menu.h"

void	animate_scroll(t_game *game)
{
	int	i;

	i = 13;
	while (i < 33)
	{
		usleep(150000);
		if (i > 13)
			game->menu->imgs[i - 1]->enabled = false;
		game->menu->imgs[i]->enabled = true;
		i++;
	}
}

static void	put_to_win(t_game *game)
{
	mlx_image_to_window(game->mlx, game->menu->imgs[13], WIDTH / 2, 40);
	mlx_image_to_window(game->mlx, game->menu->imgs[14], WIDTH / 2, 40);
	mlx_image_to_window(game->mlx, game->menu->imgs[15], WIDTH / 2, 40);
	mlx_image_to_window(game->mlx, game->menu->imgs[16], WIDTH / 2, 40);
	mlx_image_to_window(game->mlx, game->menu->imgs[17], WIDTH / 2, 40);
	mlx_image_to_window(game->mlx, game->menu->imgs[18], WIDTH / 2, 40);
	mlx_image_to_window(game->mlx, game->menu->imgs[19], WIDTH / 2, 40);
	mlx_image_to_window(game->mlx, game->menu->imgs[20], WIDTH / 2, 40);
	mlx_image_to_window(game->mlx, game->menu->imgs[21], WIDTH / 2, 40);
	mlx_image_to_window(game->mlx, game->menu->imgs[22], WIDTH / 2, 40);
	mlx_image_to_window(game->mlx, game->menu->imgs[23], WIDTH / 2, 40);
	mlx_image_to_window(game->mlx, game->menu->imgs[24], WIDTH / 2, 40);
	mlx_image_to_window(game->mlx, game->menu->imgs[25], WIDTH / 2, 40);
	mlx_image_to_window(game->mlx, game->menu->imgs[26], WIDTH / 2, 40);
	mlx_image_to_window(game->mlx, game->menu->imgs[27], WIDTH / 2, 40);
	mlx_image_to_window(game->mlx, game->menu->imgs[28], WIDTH / 2, 40);
	mlx_image_to_window(game->mlx, game->menu->imgs[29], WIDTH / 2, 40);
	mlx_image_to_window(game->mlx, game->menu->imgs[30], WIDTH / 2, 40);
	mlx_image_to_window(game->mlx, game->menu->imgs[31], WIDTH / 2, 40);
	mlx_image_to_window(game->mlx, game->menu->imgs[32], WIDTH / 2, 40);
}

void	init_settings(t_game *game)
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
	put_to_win(game);
}