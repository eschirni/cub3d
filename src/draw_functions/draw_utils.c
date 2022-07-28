/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btenzlin <btenzlin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 10:04:13 by btenzlin          #+#    #+#             */
/*   Updated: 2022/07/28 10:04:14 by btenzlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	set_z(mlx_image_t *img, int z)
{
	int	i;

	i = 0;
	while (i < img->count)
	{
		img->instances[i].z = z;
		i++;
	}
}

void	draw_tex_line(t_game *game, t_ray *ray, float pos, long ray_end)
{
	int		texture_x;
	int		texture_y;
	int		ray_start;

	ray_start = ray->start[1];
	while (ray_start <= ray->end[1])
	{
		texture_x = (int)pos * game->textures->wall_size[1];
		texture_y = ray_end & (game->textures->wall_size[0] - 1);
		ray->color = game->textures->current[texture_x + texture_y];
		if (!(ray->start[0] < MINIMAP && ray_start < MINIMAP))
		{
			if (ray->dist > 144)
				ray->color = 0x000000FF;
			else if (ray->dist > 30 && ray->color >= 0x0F0F0FFF)
				ray->color -= 0x0F0F0F00;
			else if (ray->dist > 70 && ray->color >= 0x0F0F0FFF)
				ray->color -= 0x0F0F0F00;
			if (ray->start[0] < 1920 && ray_start < 1080)
				mlx_put_pixel(game->game_img, ray->start[0],
					ray_start, ray->color);
		}
		ray_start += 1;
		pos += game->textures->offset;
	}
}

float	calc_dist(float player[2], float chest[2])
{
	float	dist;
	float	vec[2];

	vec[0] = chest[0] - player[0];
	vec[1] = chest[1] - player[1];
	dist = sqrtf(vec[0] * vec[0] + vec[1] * vec[1]);
	return (dist);
}

static void	switch_contents(t_game *game, int i, int j)
{
	float	tmp[2];

	tmp[0] = game->map->chests[i][0];
	tmp[1] = game->map->chests[i][1];
	game->map->chests[i][0] = game->map->chests[j][0];
	game->map->chests[i][1] = game->map->chests[j][1];
	game->map->chests[j][0] = tmp[0];
	game->map->chests[j][1] = tmp[1];
}

void	sort_chests(t_game *game)
{
	int		i;
	int		j;
	float	pl[2];
	float	dist[2];

	i = 0;
	pl[0] = game->map->player[0];
	pl[1] = game->map->player[1];
	while (i < game->map->loot)
	{
		j = i;
		while (j < game->map->loot)
		{
			dist[0] = calc_dist(pl, game->map->chests[i]);
			dist[1] = calc_dist(pl, game->map->chests[j]);
			if (dist[0] < dist[1])
				switch_contents(game, i, j);
			j++;
		}
		i++;
	}
}
