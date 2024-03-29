/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btenzlin <btenzlin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 10:13:06 by btenzlin          #+#    #+#             */
/*   Updated: 2022/07/28 10:13:07 by btenzlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	free_screens(t_game *game)
{
	int	i;

	i = 0;
	while (i < 69)
	{
		mlx_delete_image(game->mlx, game->menu->imgs[i]);
		i++;
	}
	free(game->menu->settings);
	free(game->menu);
	i = 0;
	while (i < 8)
	{
		mlx_delete_image(game->mlx, game->end->back[i]);
		i++;
	}
	i = 0;
	while (i < 33)
	{
		mlx_delete_image(game->mlx, game->end->cat[i]);
		i++;
	}
	free(game->end);
}

static void	free_arrs(t_game *game)
{
	int	i;

	free_screens(game);
	i = 0;
	while (game->map->big_map[i] != NULL)
	{
		free(game->map->big_map[i]);
		i++;
	}
	i = 0;
	mlx_delete_image(game->mlx, game->chars[0]->ray->img);
	free(game->chars[0]->ray);
	while (i < game->map->n_chars)
	{
		mlx_delete_image(game->mlx, game->chars[i]->img);
		free(game->chars[i]);
		i++;
	}
	free(game->chars);
}

static void	free_float_array(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->loot)
	{
		free(map->chests[i]);
		i++;
	}
	free(map->chests);
}

static void	free_luci(t_game *game)
{
	free(game->textures->luci[0]);
	free(game->textures->luci[1]);
	free(game->textures->luci[2]);
	free(game->textures->luci[3]);
	free(game->textures->luci[4]);
	free(game->textures->luci[5]);
	free(game->textures->luci[6]);
	free(game->textures->luci[7]);
}

void	free_exit(t_map *map, t_game *game)
{
	free_arrs(game);
	mlx_delete_image(game->mlx, game->map->floor);
	mlx_delete_image(game->mlx, game->map->wall);
	mlx_delete_image(game->mlx, game->map->out);
	mlx_delete_image(game->mlx, game->map->doorv);
	mlx_delete_image(game->mlx, game->map->doorh);
	mlx_delete_image(game->mlx, game->map->exit);
	mlx_delete_image(game->mlx, game->game_img);
	mlx_delete_image(game->mlx, game->torch);
	mlx_terminate(game->mlx);
	free_float_array(map);
	free(game->textures->wall);
	free(game->textures->floor);
	free(game->textures->door);
	free(game->textures->door_o);
	free(game->textures->exit);
	free_luci(game);
	free(game->textures->chest);
	free(game->textures);
	free(game->sounds);
	free(game);
	free(map->big_map);
	free(map);
	system("pkill afplay &");
}
