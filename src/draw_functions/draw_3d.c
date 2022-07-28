/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_3d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschirni <eschirni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 10:42:46 by eschirni          #+#    #+#             */
/*   Updated: 2022/07/28 10:42:48 by eschirni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	get_color(t_game *game, t_ray *ray, u_int32_t *col, float dy)
{
	float	angle;
	float	dyangle;
	int		tx;
	int		ty;

	angle = cos(game->chars[0]->pa - ray->ra);
	dyangle = 540 * 32 / dy / angle;
	tx = game->map->player[0] + cos(ray->ra) * dyangle;
	ty = game->map->player[1] + sin(ray->ra) * dyangle;
	ray->color = col[(ty & 31) * 32 + (tx & 31)];
	if (dy * angle < 120)
		ray->color = 0x000000FF;
	else if (dy * angle < 240 && ray->color >= 0x0F0F0FFF)
		ray->color -= 0x0F0F0F00;
	else if (dy * angle < 480 && ray->color >= 0x0F0F0FFF)
		ray->color -= 0x0F0F0F00;
}

static void	draw_env(t_game *game, t_ray *ray)
{
	int		y;
	int		y_top;

	y = ray->end[1];
	while (y < HEIGHT)
	{
		get_color(game, ray, game->textures->floor, y - 540);
		if (!(ray->start[0] < MINIMAP && y < MINIMAP))
			mlx_put_pixel(game->game_img, ray->start[0], y, ray->color);
		if (!(ray->start[0] < MINIMAP && (HEIGHT - y) < MINIMAP))
		{
			y_top = HEIGHT - y - 1;
			mlx_put_pixel(game->game_img, ray->start[0], y_top, ray->color);
		}
		y++;
	}
}

static float	init_vars(t_game *game, t_ray *ray, float *lh, float *lw)
{
	float	angle_distance;
	float	out_of_bounds;

	angle_distance = game->chars[0]->pa - ray->ra;
	if (angle_distance < 0)
		angle_distance += (float)M_PI * 2;
	else if (angle_distance >= (float) M_PI * 2)
		angle_distance -= (float)M_PI * 2;
	ray->dist *= cos(angle_distance);
	*lh = 32 * HEIGHT / ray->dist;
	game->textures->offset = game->textures->wall_size[1] / *lh;
	out_of_bounds = 0;
	if (*lh > HEIGHT + 1)
	{
		out_of_bounds = (*lh - HEIGHT - 1) / 2;
		*lh = HEIGHT - 1;
	}
	*lw = WIDTH / game->menu->settings->fov;
	return (out_of_bounds);
}

static void	draw_tex(t_game *game, t_ray *ray, int count_x, int *line_x)
{
	float	line_height;
	float	line_width;
	float	pixel_pos;
	float	out_of_bounds;
	long	ray_end;

	out_of_bounds = init_vars(game, ray, &line_height, &line_width);
	ray_end = ray->end[1] / 32 * game->textures->wall_size[1];
	if (ray->dir == 'E')
		ray_end = ray->end[0] / 32 * game->textures->wall_size[0];
	while (count_x < line_width)
	{
		ray->start[0] = *line_x;
		ray->start[1] = HEIGHT / 2 - line_height / 2;
		ray->end[1] = ray->start[1] + line_height;
		pixel_pos = out_of_bounds * game->textures->offset;
		draw_tex_line(game, ray, pixel_pos, ray_end);
		draw_env(game, ray);
		*line_x += 1;
		count_x++;
	}
}

void	draw_3d(t_game *game, t_ray *ray, int count_x, int *line_x)
{
	int	x;
	int	y;

	x = (int)ray->end[0] / 32;
	y = (int)ray->end[1] / 32;
	if (game->map->big_map[y][x] == '1')
		game->textures->current = game->textures->wall;
	else if (game->map->big_map[y][x] == '8'
		|| game->map->big_map[y][x] == '9')
		game->textures->current = game->textures->door;
	else if (game->map->big_map[y][x] == '7')
		game->textures->current = game->textures->door_o;
	else if (game->map->big_map[y][x] == 'X')
		game->textures->current = game->textures->exit;
	draw_tex(game, ray, count_x, line_x);
}
