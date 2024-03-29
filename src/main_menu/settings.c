/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschirni <eschirni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 10:45:07 by eschirni          #+#    #+#             */
/*   Updated: 2022/07/28 10:45:08 by eschirni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/main_menu.h"

static void	put_to_win(t_game *game, int end, int x, int y)
{
	static int	i;

	if (i == 0)
		i = 13;
	while (i < end)
	{
		mlx_image_to_window(game->mlx, game->menu->imgs[i], x, y);
		i++;
	}
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
	put_to_win(game, 33, WIDTH - 850, 60);
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
	put_to_win(game, 34, 1334, 288);
	put_to_win(game, 35, 1372, 405);
	put_to_win(game, 36, 1418, 519);
	put_to_win(game, 37, 1408, 633);
	put_to_win(game, 39, 1425, 666);
	put_to_win(game, 41, 1475, 666);
	put_to_win(game, 43, 1525, 666);
}

static void	init_sliders(t_game *game)
{
	load_png(game, 43, "./sprites/main/settings/slider.png", false);
	load_png(game, 44, "./sprites/main/settings/slider1.png", false);
	load_png(game, 45, "./sprites/main/settings/slider2.png", false);
	load_png(game, 46, "./sprites/main/settings/slider3.png", false);
	load_png(game, 47, "./sprites/main/settings/slider4.png", false);
	load_png(game, 48, "./sprites/main/settings/slider5.png", false);
	load_png(game, 49, "./sprites/main/settings/slider6.png", false);
	load_png(game, 50, "./sprites/main/settings/slider7.png", false);
	load_png(game, 51, "./sprites/main/settings/slider7.png", false);
	load_png(game, 52, "./sprites/main/settings/slider6.png", false);
	load_png(game, 53, "./sprites/main/settings/slider5.png", false);
	load_png(game, 54, "./sprites/main/settings/slider4.png", false);
	load_png(game, 55, "./sprites/main/settings/slider3.png", false);
	load_png(game, 56, "./sprites/main/settings/slider2.png", false);
	load_png(game, 57, "./sprites/main/settings/slider1.png", false);
	load_png(game, 58, "./sprites/main/settings/slider.png", false);
	load_png(game, 59, "./sprites/main/settings/slider7.png", false);
	load_png(game, 60, "./sprites/main/settings/slider5.png", false);
	load_png(game, 61, "./sprites/main/settings/slider4.png", false);
	load_png(game, 62, "./sprites/main/settings/slider3.png", false);
	load_png(game, 63, "./sprites/main/settings/slider2.png", false);
	load_png(game, 64, "./sprites/main/settings/slider.png", false);
}

void	init_settings(t_game *game)
{
	init_scroll(game);
	init_text(game);
	init_sliders(game);
	put_to_win(game, 51, 1400, 350);
	put_to_win(game, 59, 1400, 470);
	put_to_win(game, 65, 1400, 575);
}
