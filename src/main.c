/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschirni <eschirni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 12:05:26 by btenzlin          #+#    #+#             */
/*   Updated: 2022/06/13 19:15:03 by eschirni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	free_exit(t_map *map, t_game *game)
{
	int	i;

	i = 0;
	while (map->map_arr[i])
	{
		free(map->map_arr[i]);
		i++;
	}
	i = 0;
	while (i < 3)
	{
		mlx_delete_image(game->mlx, game->chars[i]->img);
		free(game->chars[i]);
		i++;
	}
	free(game->chars);
	mlx_terminate(game->mlx);
	free(game);
	free(map->map_arr);
	free(map);
}

static void	hook(void *game)
{
	t_game	*tmp;

	tmp = game;
	if (mlx_is_key_down(tmp->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(tmp->mlx);
	if (mlx_is_key_down(tmp->mlx, MLX_KEY_W))
		tmp->chars[0]->img->instances[0].y -= 5;
	if (mlx_is_key_down(tmp->mlx, MLX_KEY_S))
		tmp->chars[0]->img->instances[0].y += 5;
	if (mlx_is_key_down(tmp->mlx, MLX_KEY_A))
		tmp->chars[0]->img->instances[0].x -= 5;
	if (mlx_is_key_down(tmp->mlx, MLX_KEY_D))
		tmp->chars[0]->img->instances[0].x += 5;
}

static void	draw_textures(t_game *game) //also draw walls
{
	mlx_texture_t	*player;

	player = mlx_load_png("./sprites/white_tile.png");
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

static t_game	*init_game(t_map *map)
{
	t_game			*game;
	int				i;

	game = malloc(sizeof(t_game));
	game->chars = malloc(sizeof(t_char *) * 3); //let's count them and safe the count in game
	i = 0;
	while (i < 3)
	{
		game->chars[i] = malloc(sizeof(t_char));
		i++;
	}
	game->mlx = mlx_init(map->x * TILE_WIDTH, map->y * TILE_HEIGHT, "CUB3D", true);
	if (!game->mlx)
		ft_error("mlx allocation failed", NULL);
	draw_map(game, map);
	draw_textures(game);
	return (game);
}

int	main(int argc, char **argv)
{
	t_map	*map;
	t_game	*game;

	if (argc != 2)
		ft_error("bad arguments", NULL);
	map = init_map(argv[1]);
	game = init_game(map);
	mlx_loop_hook(game->mlx, &hook, game);
	mlx_loop(game->mlx);
	free_exit(map, game);
	system("leaks cub3d");
	return (EXIT_SUCCESS);
}
