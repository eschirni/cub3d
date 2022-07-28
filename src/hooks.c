/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschirni <eschirni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 10:06:17 by eschirni          #+#    #+#             */
/*   Updated: 2022/07/28 10:06:19 by eschirni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

static void	set_coords(t_game *game, int addX, int addY)
{
	int		pos_x;
	int		pos_y;
	int		circle_x;
	int		circle_y;
	float	angle;

	pos_x = game->map->player[0] + addX;
	pos_y = game->map->player[1] + addY;
	angle = 0;
	while (angle <= (float)M_PI * 2)
	{
		circle_x = (pos_x + 4 * cos(angle));
		circle_y = (pos_y + 4 * sin(angle));
		if (game->map->big_map[circle_y / 32][circle_x / 32] == '1')
			return ;
		angle += (float)M_PI / 18;
	}
	game->map->player[0] += addX;
	game->map->player[1] += addY;
}

static void	mouse_rotate(t_game *game)
{
	int	x;
	int	y;

	mlx_get_mouse_pos(game->mlx, &x, &y);
	x -= WIDTH / 2;
	game->chr->pa += (float)x / 4000;
	mlx_set_mouse_pos(game->mlx, WIDTH / 2, HEIGHT / 2);
}

static void	check_keys(t_game *game)
{
	if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(game->mlx);
	if (mlx_is_key_down(game->mlx, MLX_KEY_W))
		set_coords(game, game->chr->w[0], game->chr->w[1]);
	if (mlx_is_key_down(game->mlx, MLX_KEY_A))
		set_coords(game, game->chr->a[0], game->chr->a[1]);
	if (mlx_is_key_down(game->mlx, MLX_KEY_S))
		set_coords(game, game->chr->s[0], game->chr->s[1]);
	if (mlx_is_key_down(game->mlx, MLX_KEY_D))
		set_coords(game, game->chr->d[0], game->chr->d[1]);
	if (mlx_is_key_down(game->mlx, MLX_KEY_LEFT))
		game->chr->pa -= 0.03f;
	if (mlx_is_key_down(game->mlx, MLX_KEY_RIGHT))
		game->chr->pa += 0.03f;
	if (mlx_is_key_down(game->mlx, MLX_KEY_LEFT_SHIFT))
		game->ps = 4;
	else
		game->ps = 2;
}

void	fps(void *tmp)
{
	t_game	*game;

	game = tmp;
	mouse_rotate(game);
	check_keys(game);
	calc_rotate(game, 0.0f);
	draw_game(game->chr->ray, game, game->map->player);
}
