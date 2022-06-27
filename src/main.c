/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschirni <eschirni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 12:05:26 by btenzlin          #+#    #+#             */
/*   Updated: 2022/06/27 16:49:55 by eschirni         ###   ########.fr       */
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
	i = 1;
	while (i < game->n_chars)
	{
		mlx_delete_image(game->mlx, game->chars[i]->img);
		free(game->chars[i]);
		i++;
	}
	mlx_delete_image(game->mlx, game->chars[0]->img);
	mlx_delete_image(game->mlx, game->chars[0]->ray->img);
	free(game->chars[0]->ray);
	free(game->chars[0]);
	free(game->chars);
	mlx_delete_image(game->mlx, game->floor);
	mlx_delete_image(game->mlx, game->wall);
	mlx_delete_image(game->mlx, game->out);
	mlx_delete_image(game->mlx, game->game_img);
	mlx_terminate(game->mlx);
	free(game);
	free(map->map_arr);
	free(map);
}

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
	mlx_loop_hook(game->mlx, &hook, game);
	mlx_loop(game->mlx);
	free_exit(map, game);
	system("leaks cub3d");
	return (EXIT_SUCCESS);
}
