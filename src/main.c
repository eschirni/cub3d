/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschirni <eschirni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 10:06:37 by eschirni          #+#    #+#             */
/*   Updated: 2022/07/28 10:06:40 by eschirni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

static t_game	*alloc_game(void)
{
	t_game			*game;

	game = malloc(sizeof(t_game));
	if (game == NULL)
		ft_error("allocation error", NULL);
	game->mlx = mlx_init(WIDTH, HEIGHT, "CUB3D", false);
	if (!game->mlx)
		ft_error("mlx allocation failed", NULL);
	game->game_img = mlx_new_image(game->mlx, WIDTH, HEIGHT);
	return (game);
}

int	main(int argc, char **argv)
{
	t_game		*game;

	if (argc != 2)
		ft_error("bad arguments", NULL);
	game = alloc_game();
	init_map(game, argv[1]);
	init_textures(game);
	mlx_set_cursor_mode(game->mlx, MLX_MOUSE_HIDDEN);
	mlx_set_mouse_pos(game->mlx, WIDTH / 2, HEIGHT / 2);
	mlx_loop_hook(game->mlx, &fps, game);
	mlx_loop(game->mlx);
	free_exit(game->map, game);
	system("leaks cub3D");
	return (EXIT_SUCCESS);
}
