#include "../includes/main_menu.h"

void	animate_scroll(t_menu *menu) //put in mlx loop for animation
{
	if (menu->scroll_frame > 13)
		menu->imgs[menu->scroll_frame - 1]->enabled = false;
	menu->imgs[menu->scroll_frame]->enabled = true;
	menu->scroll_frame++;
}

static void	put_to_win(t_game *game)
{
	int	i;

	i = 13;
	while (i < 33)
	{
		mlx_image_to_window(game->mlx, game->menu->imgs[i], WIDTH - 850, 60);
		i++;
	}
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
