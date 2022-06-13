/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschirni <eschirni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 19:17:02 by eschirni          #+#    #+#             */
/*   Updated: 2022/06/13 23:00:10 by eschirni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	draw_char(t_game *game, int x, int y, int chr)
{
	mlx_texture_t	*player;

	if (chr != 0)
		player = mlx_load_png("./sprites/tile_red.png");
	else
		player = mlx_load_png("./sprites/tile_green.png");
	if (player == NULL)
		ft_error("can't load image", NULL);
	game->chars[chr]->img = mlx_texture_to_image(game->mlx, player);
	if (!mlx_resize_image(game->chars[chr]->img, 10, 10))
		ft_error("can't resize image", NULL);
	if (game->chars[chr]->img == NULL)
		ft_error("char image allocation failed", NULL);
	mlx_delete_texture(player);
	mlx_image_to_window(game->mlx, game->chars[chr]->img, x, y);
}

static int	count_init_chars(t_game *game)
{
	int	n;

	game->chars = malloc(sizeof(t_char *) * game->n_chars); //let's count them and safe the count in game
	if (game->chars == NULL)
		ft_error("no char could be allocated", NULL);
	n = 0;
	while (n < game->n_chars)
	{
		game->chars[n] = malloc(sizeof(t_char));
		if (game->chars[n] == NULL)
			ft_error("allocation error", NULL);
		game->chars[n]->w[0] = 0;
		game->chars[n]->w[1] = -5;
		game->chars[n]->a[0] = -5;
		game->chars[n]->a[1] = 0;
		game->chars[n]->s[0] = 0;
		game->chars[n]->s[1] = 5;
		game->chars[n]->d[0] = 5;
		game->chars[n]->d[1] = 0;
		n++;
	}
	return (n);
}

static void	draw_chars(t_game *game, t_map *map)
{
	int	i;
	int	j;
	int	chrs;

	i = 0;
	chrs = count_init_chars(game);
	while (map->map_arr[i])
	{
		j = 0;
		while (map->map_arr[i][j])
		{
			if (is_char_obj(map->map_arr[i][j]))
				draw_char(game, j * 32, i * 32, --chrs);
			j++;
		}
		i++;
	}
}

static void	get_map_textures(t_game *game)
{
	mlx_texture_t	*floor;
	mlx_texture_t	*wall;

	floor = mlx_load_png("./sprites/tile_black.png");
	game->floor = mlx_texture_to_image(game->mlx, floor);
	mlx_delete_texture(floor);
	if (!mlx_resize_image(game->floor, 32, 32))
		ft_error("can't resize image", NULL);
	wall = mlx_load_png("./sprites/tile_blue.png");
	game->wall = mlx_texture_to_image(game->mlx, wall);
	mlx_delete_texture(wall);
	if (!mlx_resize_image(game->wall, 32, 32))
		ft_error("can't resize image", NULL);
}

void	draw_map(t_game *game, t_map *map)
{
	int				i;
	int				j;

	get_map_textures(game);
	i = 0;
	while (map->map_arr[i]) //If we want to do smth with the tiles afterwards, safe them in array
	{
		j = 0;
		while (map->map_arr[i][j])
		{
			if (map->map_arr[i][j] == '0')
				mlx_image_to_window(game->mlx, game->floor, j * 32, i * 32);
			else if (map->map_arr[i][j] == '1')
				mlx_image_to_window(game->mlx, game->wall, j * 32, i * 32);
			else if (is_char_obj(map->map_arr[i][j]) == true)
			{
				game->n_chars++;
				mlx_image_to_window(game->mlx, game->floor, j * 32, i * 32);
			}
			j++;
		}
		i++;
	}
	draw_chars(game, map);
}
