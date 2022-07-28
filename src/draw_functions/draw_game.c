/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschirni <eschirni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 10:05:11 by eschirni          #+#    #+#             */
/*   Updated: 2022/07/28 20:43:17 by eschirni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	check_direction(t_game *game, t_ray *ray)
{
	if (ray->dir == 'E' && ray->ra > 0 && ray->ra < (float)M_PI)
	{
		game->textures->wall = game->textures->south;
		game->textures->wall_size[0] = game->textures->south_size[0];
		game->textures->wall_size[1] = game->textures->south_size[1];
	}
	else if (ray->dir == 'E')
	{
		game->textures->wall = game->textures->north;
		game->textures->wall_size[0] = game->textures->north_size[0];
		game->textures->wall_size[1] = game->textures->north_size[1];
	}
	else if (ray->dir == 'N' && ray->ra > ((float)M_PI / 2)
		&& ray->ra < (3 * (float)M_PI / 2))
	{
		game->textures->wall = game->textures->west;
		game->textures->wall_size[0] = game->textures->west_size[0];
		game->textures->wall_size[1] = game->textures->west_size[1];
	}
	else
	{
		game->textures->wall = game->textures->east;
		game->textures->wall_size[0] = game->textures->east_size[0];
		game->textures->wall_size[1] = game->textures->east_size[1];
	}
}

static void	iterate_game(t_game *game, t_ray *ray, int i, int coords[2])
{
	int		line_x;
	t_ray	*mini;

	line_x = 0;
	mini = malloc(sizeof(t_ray));
	if (mini == NULL)
		ft_error("Allocation error!\n", NULL);
	while (i < 1920)
	{
		ray->ra += (float)M_PI / 180 / 32;
		if (ray->ra >= (float)M_PI * 2)
			ray->ra -= (float)M_PI * 2;
		check_direction(game, ray);
		ray->dist = calc_rays(ray, game->map, coords[0], coords[1]);
		mini->start[0] = ray->start[0] - (game->map->player[0] - 144);
		mini->start[1] = ray->start[1] - (game->map->player[1] - 144);
		mini->end[0] = ray->end[0] - (game->map->player[0] - 144);
		mini->end[1] = ray->end[1] - (game->map->player[1] - 144);
		draw_3d(game, ray, 0, &line_x);
		i++;
	}
	free(mini);
}

void	draw_game(t_ray *ray, t_game *game, float coords[2])
{
	int	i;
	int	line_x;
	int	rounded[2];

	ray->ra = game->chr->pa - 30 * ((float)M_PI / 180);
	if (ray->ra < 0)
		ray->ra += (float)M_PI * 2;
	if (game->game_img)
		mlx_delete_image(game->mlx, game->game_img);
	game->game_img = mlx_new_image(game->mlx, WIDTH, HEIGHT);
	i = 0;
	line_x = 0;
	rounded[0] = (int)coords[0];
	rounded[1] = (int)coords[1];
	iterate_game(game, ray, 0, rounded);
	mlx_image_to_window(game->mlx, game->game_img, 0, 0);
}
