/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btenzlin <btenzlin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 10:05:51 by eschirni          #+#    #+#             */
/*   Updated: 2022/07/28 11:00:13 by btenzlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	free_arrs(t_game *game)
{
	int	i;

	i = 0;
	while (game->map->big_map[i] != NULL)
	{
		free(game->map->big_map[i]);
		i++;
	}
	i = 0;
	free(game->chr->ray);
	free(game->chr);
}

void	free_exit(t_map *map, t_game *game)
{
	free_arrs(game);
	mlx_delete_image(game->mlx, game->game_img);
	mlx_terminate(game->mlx);
	free(game->textures->north);
	free(game->textures->east);
	free(game->textures->south);
	free(game->textures->west);
	free(game->textures);
	free(game);
	free(map->big_map);
	free(map->no_tex);
	free(map->so_tex);
	free(map->we_tex);
	free(map->ea_tex);
	free(map);
}
