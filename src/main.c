/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschirni <eschirni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 12:05:26 by btenzlin          #+#    #+#             */
/*   Updated: 2022/06/13 22:58:48 by eschirni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	free_exit(t_map *map, t_game *game)
{
	int	i;

	i = 0;
	while (map->map_arr[i] != NULL)
	{
		free(map->map_arr[i]);
		i++;
	}
	i = 0;
	while (i < game->n_chars)
	{
		mlx_delete_image(game->mlx, game->chars[i]->img);
		free(game->chars[i]);
		i++;
	}
	free(game->chars);
	mlx_delete_image(game->mlx, game->floor);
	mlx_delete_image(game->mlx, game->wall);
	mlx_terminate(game->mlx);
	free(game);
	free(map->map_arr);
	free(map);
}

static void	hook(void *game) //we need pixels for characters to rotate it, there is no rotation for images
{
	t_game	*tmp;

	tmp = game;
	if (mlx_is_key_down(tmp->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(tmp->mlx);
	if (mlx_is_key_down(tmp->mlx, MLX_KEY_W))
	{
		tmp->chars[0]->img->instances[0].x += tmp->chars[0]->w[0];
		tmp->chars[0]->img->instances[0].y += tmp->chars[0]->w[1];
	}
	if (mlx_is_key_down(tmp->mlx, MLX_KEY_A))
	{
		tmp->chars[0]->img->instances[0].x += tmp->chars[0]->a[0];
		tmp->chars[0]->img->instances[0].y += tmp->chars[0]->a[1];
	}
	if (mlx_is_key_down(tmp->mlx, MLX_KEY_S))
	{
		tmp->chars[0]->img->instances[0].x += tmp->chars[0]->s[0];
		tmp->chars[0]->img->instances[0].y += tmp->chars[0]->s[1];
	}
	if (mlx_is_key_down(tmp->mlx, MLX_KEY_D))
	{
		tmp->chars[0]->img->instances[0].x += tmp->chars[0]->d[0];
		tmp->chars[0]->img->instances[0].y += tmp->chars[0]->d[1];
	}
}

static t_game	*init_game(t_map *map)
{
	t_game			*game;

	game = malloc(sizeof(t_game));
	if (game == NULL)
		ft_error("allocation error", NULL);
	game->mlx = mlx_init(map->x * TILE_WIDTH, map->y * TILE_HEIGHT, "CUB3D", true);
	if (!game->mlx)
		ft_error("mlx allocation failed", NULL);
	game->n_chars = 0;
	draw_map(game, map);
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
