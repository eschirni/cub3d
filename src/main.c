/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschirni <eschirni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 12:05:26 by btenzlin          #+#    #+#             */
/*   Updated: 2022/06/12 23:02:04 by eschirni         ###   ########.fr       */
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
	mlx_delete_image(game->mlx, game->chars[0]->img); //iterate
	free(game->chars[0]);
	free(game->chars);
	free(game);
	free(map->map_arr);
	free(map);
}

static void	hook(mlx_key_data_t keydata, void *game)
{
	t_game	*tmp;

	tmp = game;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_RELEASE)
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
	mlx_texture_t	*zomb;

	zomb = mlx_load_png("./sprites/white_tile.png");
	if (zomb == NULL)
		ft_error("can't load image", NULL);
	game->chars[0]->img = mlx_texture_to_image(game->mlx, zomb);
	if (game->chars[0]->img == NULL)
		ft_error("char image allocation failed", NULL);
	mlx_delete_texture(zomb);
	mlx_image_to_window(game->mlx, game->chars[0]->img, 0, 0);
}

static t_game	*init_game(t_map *map)
{
	t_game			*game;

	game = malloc(sizeof(t_game));
	game->chars = malloc(sizeof(t_char *));
	game->chars[0] = malloc(sizeof(t_char)); //iterate and count chars
	game->chars[1] = NULL;
	game->mlx = mlx_init(map->x * TILE_WIDTH, map->y * TILE_HEIGHT, "CUB3D", true);
	if (!game->mlx)
		ft_error("mlx allocation failed", NULL);
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
	mlx_key_hook(game->mlx, &hook, game);
	mlx_loop(game->mlx);
	mlx_terminate(game->mlx);
	free_exit(map, game);
	system("leaks cub3d");
	return (EXIT_SUCCESS);
}
