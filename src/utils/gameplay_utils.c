/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameplay_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btenzlin <btenzlin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 10:07:49 by btenzlin          #+#    #+#             */
/*   Updated: 2022/07/28 10:11:10 by btenzlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	open_door(t_game *game, int addX, int addY)
{
	float	x;
	float	y;
	int		next_x;
	int		next_y;

	x = game->map->player[0];
	y = game->map->player[1];
	next_x = (x + addX * 16) / 32;
	next_y = (y + addY * 16) / 32;
	if (game->map->big_map[next_y][next_x] == '8'
		|| game->map->big_map[next_y][next_x] == '9')
	{
		if (game->sounds->sound == true)
			system("afplay music/wind.mp3 &");
		game->map->big_map[next_y][next_x] = '7';
	}
	else if (game->map->big_map[next_y][next_x] == '7')
	{
		if (game->sounds->sound == true)
			system("afplay music/wind.mp3 &");
		game->map->big_map[next_y][next_x] = '8';
	}
}

int	find_instance(t_game *game, int x, int y)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (i < game->map->y)
	{
		j = 0;
		while (j < game->map->x)
		{
			if (i == y && j == x)
				return (count);
			if (game->map->big_map[i][j] == 'L'
				|| game->map->big_map[i][j] == 'l')
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

void	check_pos(t_game *game)
{
	int	x;
	int	y;

	x = game->map->player[0] / 32;
	y = game->map->player[1] / 32;
	if (game->map->big_map[y][x] == 'X')
		end_game(game);
	else if (game->map->big_map[y][x] == 'L')
	{
		game->loot++;
		game->map->chest->instances[find_instance(game, x, y)].enabled = false;
		game->map->big_map[y][x] = 'l';
	}
}
