/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschirni <eschirni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 19:17:02 by eschirni          #+#    #+#             */
/*   Updated: 2022/06/13 20:07:00 by eschirni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	draw_chars(t_game *game)
{
	mlx_texture_t	*player;
	int				i;

	game->chars = malloc(sizeof(t_char *) * 1); //let's count them and safe the count in game
	if (game->chars == NULL)
		ft_error("allocation error", NULL);
	i = 0;
	while (i < 1)
	{
		game->chars[i] = malloc(sizeof(t_char));
		if (game->chars[i] == NULL)
			ft_error("allocation error", NULL);
		i++;
	}
	player = mlx_load_png("./sprites/tile_green.png");
	if (player == NULL)
		ft_error("can't load image", NULL);
	game->chars[0]->img = mlx_texture_to_image(game->mlx, player);
	if (!mlx_resize_image(game->chars[0]->img, 10, 10))
		ft_error("can't resize image", NULL);
	if (game->chars[0]->img == NULL)
		ft_error("char image allocation failed", NULL);
	mlx_delete_texture(player);
	mlx_image_to_window(game->mlx, game->chars[0]->img, 5, 5);
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
			if (map->map_arr[i][j] == '0' || map->map_arr[i][j] == 'N'
				|| map->map_arr[i][j] == 'E' || map->map_arr[i][j] == 'S'
				|| map->map_arr[i][j] == 'W')
				mlx_image_to_window(game->mlx, game->floor, j * 32, i * 32);
			else if (map->map_arr[i][j] == '1')
				mlx_image_to_window(game->mlx, game->wall, j * 32, i * 32);
			j++;
		}
		i++;
	}
	draw_chars(game);
}
