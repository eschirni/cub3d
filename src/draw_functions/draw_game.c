/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschirni <eschirni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 10:43:09 by eschirni          #+#    #+#             */
/*   Updated: 2022/07/28 10:43:11 by eschirni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	reset_img(t_game *game, mlx_image_t *img, int width, int height)
{
	int	x;
	int	y;

	x = 0;
	while (x < width)
	{
		y = 0;
		while (y < height)
		{
			game->ray_tiles[y][x] = false;
			mlx_put_pixel(img, x, y, 0x000000);
			y++;
		}
		x++;
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
	game->rays = malloc(sizeof(float) * 1920);
	if (!game->rays)
		ft_error("failed to allocate memory", NULL);
	while (++i < game->menu->settings->fov)
	{
		ray->ra += (float)M_PI / 180 / game->menu->settings->graphics;
		if (ray->ra >= (float)M_PI * 2)
			ray->ra -= (float)M_PI * 2;
		ray->dist = calc_rays(ray, game->map, coords[0], coords[1]);
		mini->start[0] = ray->start[0] - (game->map->player[0] - 144);
		mini->start[1] = ray->start[1] - (game->map->player[1] - 144);
		mini->end[0] = ray->end[0] - (game->map->player[0] - 144);
		mini->end[1] = ray->end[1] - (game->map->player[1] - 144);
		draw_line(game, mini, ray->img);
		draw_3d(game, ray, 0, &line_x);
		game->rays[i] = ray->dist;
	}
	free(mini);
}

static void	draw_chests(t_game *game)
{
	int		i;
	float	chests[2];

	i = 0;
	sort_chests(game);
	while (i < game->map->loot)
	{
		chests[0] = game->map->chests[i][0];
		chests[1] = game->map->chests[i][1];
		if (calc_dist(game->map->player, game->map->chests[i]) < 130)
			draw_sprite(game, chests[0], chests[1], 'c');
		i++;
	}
}

void	draw_game(t_game *game, t_ray *ray)
{
	int	i;
	int	line_x;
	int	rounded[2];

	ray->ra = game->chars[0]->pa - 30 * ((float)M_PI / 180);
	if (ray->ra < 0)
		ray->ra += (float)M_PI * 2;
	mlx_delete_image(game->mlx, game->game_img);
	game->game_img = mlx_new_image(game->mlx, WIDTH, HEIGHT);
	i = 0;
	line_x = 0;
	rounded[0] = (int)game->map->player[0];
	rounded[1] = (int)game->map->player[1];
	reset_img(game, ray->img, MINIMAP, MINIMAP);
	iterate_game(game, ray, -1, rounded);
	draw_chests(game);
	mlx_image_to_window(game->mlx, game->game_img, 0, 0);
	game->game_img->instances[0].z = -100;
}
