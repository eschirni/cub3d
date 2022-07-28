/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschirni <eschirni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 10:45:16 by eschirni          #+#    #+#             */
/*   Updated: 2022/07/28 10:45:17 by eschirni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	load_png_end(t_game *game, int pos, char *name, bool cat)
{
	mlx_texture_t	*txt;
	mlx_image_t		**arr;
	int				y;

	arr = game->end->cat;
	y = 700;
	if (cat == false)
	{
		y = 0;
		arr = game->end->back;
	}
	txt = mlx_load_png(name);
	arr[pos] = mlx_texture_to_image(game->mlx, txt);
	mlx_delete_texture(txt);
	mlx_image_to_window(game->mlx, arr[pos], 0, y);
}

static void	init_end_back(t_game *game)
{
	load_png_end(game, 0, "./sprites/end/back.png", false);
	load_png_end(game, 1, "./sprites/end/back1.png", false);
	load_png_end(game, 2, "./sprites/end/back2.png", false);
	load_png_end(game, 3, "./sprites/end/back3.png", false);
	load_png_end(game, 4, "./sprites/end/back4.png", false);
	load_png_end(game, 5, "./sprites/end/back5.png", false);
	load_png_end(game, 6, "./sprites/end/back6.png", false);
	load_png_end(game, 7, "./sprites/end/back7.png", false);
}

static void	init_cat_sitting(t_game *game)
{
	load_png_end(game, 0, "./sprites/end/cat/cat_sitting.png", true);
	load_png_end(game, 1, "./sprites/end/cat/cat_sitting1.png", true);
	load_png_end(game, 2, "./sprites/end/cat/cat_sitting2.png", true);
	load_png_end(game, 3, "./sprites/end/cat/cat_sitting3.png", true);
	load_png_end(game, 4, "./sprites/end/cat/cat_sitting4.png", true);
	load_png_end(game, 5, "./sprites/end/cat/cat_sitting5.png", true);
	load_png_end(game, 6, "./sprites/end/cat/cat_sitting6.png", true);
	load_png_end(game, 7, "./sprites/end/cat/cat_sitting7.png", true);
	load_png_end(game, 8, "./sprites/end/cat/cat_sitting8.png", true);
	load_png_end(game, 9, "./sprites/end/cat/cat_sitting9.png", true);
	load_png_end(game, 10, "./sprites/end/cat/cat_sitting10.png", true);
	load_png_end(game, 11, "./sprites/end/cat/cat_sitting11.png", true);
	load_png_end(game, 12, "./sprites/end/cat/cat_sitting12.png", true);
	load_png_end(game, 13, "./sprites/end/cat/cat_sitting13.png", true);
	load_png_end(game, 14, "./sprites/end/cat/cat_sitting14.png", true);
	load_png_end(game, 15, "./sprites/end/cat/cat_sitting15.png", true);
	load_png_end(game, 16, "./sprites/end/cat/cat_sitting16.png", true);
	load_png_end(game, 17, "./sprites/end/cat/cat_sitting17.png", true);
	load_png_end(game, 18, "./sprites/end/cat/cat_sitting18.png", true);
	load_png_end(game, 19, "./sprites/end/cat/cat_sitting19.png", true);
	load_png_end(game, 20, "./sprites/end/cat/cat_sitting20.png", true);
}

void	init_end_textures(t_game *game)
{
	char	*score;
	char	*tmp;

	init_end_back(game);
	init_cat_sitting(game);
	load_png_end(game, 21, "./sprites/end/cat/cat_walk.png", true);
	load_png_end(game, 22, "./sprites/end/cat/cat_walk1.png", true);
	load_png_end(game, 23, "./sprites/end/cat/cat_walk2.png", true);
	load_png_end(game, 24, "./sprites/end/cat/cat_walk3.png", true);
	load_png_end(game, 25, "./sprites/end/cat/cat_walk4.png", true);
	load_png_end(game, 26, "./sprites/end/cat/cat_walk5.png", true);
	load_png_end(game, 27, "./sprites/end/cat/cat_walk6.png", true);
	load_png_end(game, 28, "./sprites/end/cat/cat_walk7.png", true);
	load_png_end(game, 29, "./sprites/end/cat/cat_walk8.png", true);
	load_png_end(game, 30, "./sprites/end/cat/cat_walk9.png", true);
	load_png_end(game, 31, "./sprites/end/cat/cat_walk10.png", true);
	load_png_end(game, 32, "./sprites/end/cat/cat_walk11.png", true);
	score = ft_strcdup("Score: ", '\0', 0);
	tmp = ft_itoa(game->loot * 100);
	score = ft_append(score, tmp);
	mlx_put_string(game->mlx, score, 900, 100);
	free(score);
	free(tmp);
}
