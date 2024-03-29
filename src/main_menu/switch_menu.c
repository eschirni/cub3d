/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   switch_menu.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschirni <eschirni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 10:45:11 by eschirni          #+#    #+#             */
/*   Updated: 2022/07/28 10:45:12 by eschirni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	disable_game(t_game *game)
{
	int	i;

	game->menu->imgs[0]->enabled = true;
	game->map->floor->enabled = false;
	game->map->out->enabled = false;
	game->map->wall->enabled = false;
	game->chars[0]->ray->img->enabled = false;
	game->menu->imgs[6]->enabled = true;
	if (game->menu->started_game == true)
		game->menu->imgs[65]->enabled = true;
	else
		game->menu->imgs[7]->enabled = true;
	game->menu->imgs[9]->enabled = true;
	game->menu->imgs[11]->enabled = true;
	if (game->sounds->sound == true)
		game->menu->imgs[67]->enabled = true;
	else
		game->menu->imgs[68]->enabled = true;
	i = 0;
	while (i < game->map->n_chars)
	{
		game->chars[i]->img->enabled = false;
		i++;
	}
}

void	to_menu(t_game *game)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		ft_error("Error while reading the time", NULL);
	game->menu->back_seconds = time.tv_sec * 1000 + time.tv_usec / 1000;
	game->menu->scroll_seconds = game->menu->back_seconds;
	game->menu->music_start = time.tv_sec;
	system("pkill afplay &");
	if (game->sounds->sound == true)
		system("afplay ./music/main_menu.mp3 &");
	disable_game(game);
	game->menu->back_frame = 1;
	game->menu->scroll_frame = 13;
	game->menu->scroll_mode = 'N';
	mlx_set_cursor_mode(game->mlx, MLX_MOUSE_NORMAL);
	game->menu->in_menu = true;
}

static void	disable_animation(t_game *game)
{
	int	i;

	i = 0;
	while (i < 12)
	{
		game->menu->imgs[i]->enabled = false;
		i++;
	}
	i = 0;
	while (i < game->map->n_chars)
	{
		game->chars[i]->img->enabled = true;
		i++;
	}
	game->menu->imgs[65]->enabled = false;
	game->menu->imgs[66]->enabled = false;
	game->menu->imgs[67]->enabled = false;
	game->menu->imgs[68]->enabled = false;
}

void	to_game(t_game *game)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		ft_error("Error while reading the time", NULL);
	if (game->menu->scroll_mode != 'N')
	{
		game->menu->scroll_mode = 'C';
		return ;
	}
	mlx_set_cursor_mode(game->mlx, MLX_MOUSE_HIDDEN);
	game->map->floor->enabled = true;
	game->map->out->enabled = true;
	game->map->wall->enabled = true;
	game->chars[0]->ray->img->enabled = true;
	disable_animation(game);
	mlx_set_mouse_pos(game->mlx, WIDTH / 2, HEIGHT / 2);
	game->menu->started_game = true;
	system("pkill afplay &");
	game->sounds->music_start = time.tv_sec;
	game->sounds->step = time.tv_sec * 1000 + time.tv_usec / 1000;
	if (game->sounds->sound == true)
		system("afplay -v 0.5 ./music/background.mp3 &");
	game->menu->in_menu = false;
}
