/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btenzlin <btenzlin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 12:05:26 by btenzlin          #+#    #+#             */
/*   Updated: 2022/06/28 19:14:35 by btenzlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static t_game	*init_game(t_map *map)
{
	t_game			*game;

	game = malloc(sizeof(t_game));
	if (game == NULL)
		ft_error("allocation error", NULL);
	game->mlx = mlx_init(WIDTH, HEIGHT, "CUB3D", false);
	if (!game->mlx)
		ft_error("mlx allocation failed", NULL);
	game->n_chars = 0;
	game->map = map;
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
	draw_crosshair(game->mlx, 0xFFFFFFAA);
	mlx_loop_hook(game->mlx, &hook, game);
	mlx_loop(game->mlx);
	free_exit(map, game);
	system("leaks cub3d");
	return (EXIT_SUCCESS);
}
