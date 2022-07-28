/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_closed.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschirni <eschirni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 11:59:19 by eschirni          #+#    #+#             */
/*   Updated: 2022/07/28 18:55:51 by eschirni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static bool	zero(t_map *map, int x, int y)
{
	if (map->big_map[y + 1][x] == ' ' || map->big_map[y - 1][x] == ' ')
		return (false);
	else if (map->big_map[y][x - 1] == ' ' || map->big_map[y][x + 1] == ' ')
		return (false);
	else if (map->big_map[y - 1][x - 1] == ' '
		|| map->big_map[y + 1][x - 1] == ' ')
		return (false);
	else if (map->big_map[y - 1][x + 1] == ' '
		|| map->big_map[y + 1][x + 1] == ' ')
		return (false);
	return (true);
}

static bool	check_border(t_map *map, int x, int y)
{
	if (map->big_map[y][x] == '1' || map->big_map[y][x] == ' ')
		return (true);
	return (false);
}

void	check_map_closed(t_map *map)
{
	int		x;
	int		y;
	bool	closed;

	y = 0;
	while (y < map->y)
	{
		x = 0;
		while (x < map->x)
		{
			if (x == 0 || x == map->x -1 || y == 0 || y == map->y - 1)
				closed = check_border(map, x, y);
			else if (map->big_map[y][x] == '0' ||
				is_char_obj(map->big_map[y][x]))
				closed = zero(map, x, y);
			if (closed == false)
				ft_error("map not closed!", NULL);
			x++;
		}
		y++;
	}
}
