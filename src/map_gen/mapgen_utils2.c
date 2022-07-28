/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapgen_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btenzlin <btenzlin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 10:06:38 by btenzlin          #+#    #+#             */
/*   Updated: 2022/07/28 10:06:59 by btenzlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	set_rnd_direction(t_mapgen *mapg)
{
	if ((mapg->rand_dir[0] == mapg->last_dir[0]
			&& mapg->rand_dir[1] == mapg->last_dir[1])
		|| (mapg->rand_dir[0] == -mapg->last_dir[0]
			&& mapg->rand_dir[1] == -mapg->last_dir[1]))
	{
		mapg->rand = get_random_num(0, 3);
		mapg->rand_dir[0] = mapg->dirs[mapg->rand][0];
		mapg->rand_dir[1] = mapg->dirs[mapg->rand][1];
		return (1);
	}
	else
		return (0);
}

void	checker(t_mapgen *mapg)
{
	int	i;
	int	j;
	int	exit;
	int	enemy;

	i = 0;
	mapg->loot = 0;
	exit = 0;
	enemy = 0;
	while (mapg->map[i])
	{
		j = 0;
		while (mapg->map[i][j])
		{
			if (mapg->map[i][j] == 'W')
				enemy++;
			else if (mapg->map[i][j] == 'X')
				exit++;
			else if (mapg->map[i][j] == 'L' || mapg->map[i][j] == 'l')
				mapg->loot++;
			j++;
		}
		i++;
	}
}

static void	set_doors(char **map)
{
	int	i;
	int	j;
	int	rand;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			rand = get_random_num(1, 100);
			if ((map[i][j] == 'V' || map[i][j] == 'H') && rand < 10)
			{
				if (map[i][j] == 'V')
					map[i][j] = '8';
				else
					map[i][j] = '9';
			}
			j++;
		}
		i++;
	}
}

static void	set_enemy(t_mapgen *mapg)
{
	int	i;
	int	j;

	while (true)
	{
		i = get_random_num(0, mapg->size);
		j = get_random_num(0, mapg->size);
		if (mapg->map[i][j] == '0')
		{
			mapg->map[i][j] = 'W';
			break ;
		}
	}
}

void	check_floors(t_mapgen *mapg)
{
	int	i;
	int	j;

	i = 0;
	while (mapg->map[i])
	{
		j = 0;
		while (mapg->map[i][j])
		{
			if (is_corridor(mapg->map, i, j) == 1)
				mapg->map[i][j] = 'H';
			else if (is_corridor(mapg->map, i, j) == 2)
				mapg->map[i][j] = 'V';
			j++;
		}
		i++;
	}
	set_entities(mapg->map, 'L', 10);
	set_enemy(mapg);
	set_doors(mapg->map);
}
