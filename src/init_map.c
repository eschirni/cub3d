/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschirni <eschirni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 10:08:44 by btenzlin          #+#    #+#             */
/*   Updated: 2022/07/28 10:46:34 by eschirni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

static void	set_entity_pos(float entity[2], int i, int j)
{
	entity[0] = j * 32 + 16;
	entity[1] = i * 32 + 16;
}

static void	mark_enteties(t_map *map)
{
	int	i;
	int	j;

	i = map->y - 1;
	map->player[0] = -1;
	while (i >= 0)
	{
		j = map->x - 1;
		while (j >= 0)
		{
			if (is_char_obj(map->big_map[i][j]))
			{
				if (map->player[0] == -1)
					set_entity_pos(map->player, i, j);
				else
					set_entity_pos(map->enemy, i, j);
				map->n_chars++;
			}
			j--;
		}
		i--;
	}
}

static void	set_chest_pos(t_map *map, int count, int i, int j)
{
	map->chests[count] = malloc(sizeof(float) * 2);
	if (!map->chests[count])
		ft_error("allocation failed", NULL);
	map->chests[count][0] = j * 32 + 16;
	map->chests[count][1] = i * 32 + 16;
}

static void	mark_chests(t_map *map)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	map->chests = malloc(sizeof(float *) * map->loot);
	if (!map->chests)
		ft_error("allocation failed", NULL);
	while (map->big_map[i])
	{
		j = 0;
		while (map->big_map[i][j])
		{
			if (map->big_map[i][j] == 'L' || map->big_map[i][j] == 'l')
			{
				set_chest_pos(map, count, i, j);
				count++;
			}
			j++;
		}
		i++;
	}
}

t_map	*init_map(t_mg *mapg)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	if (!map)
		ft_error("allocation failed", NULL);
	map->x = mapg->size + 2;
	map->y = mapg->size + 2;
	map->big_map = mapg->map;
	map->loot = mapg->loot;
	free(mapg);
	map->n_chars = 0;
	mark_enteties(map);
	mark_chests(map);
	return (map);
}
