#include "includes/cub3d.h"

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
				{
					map->player[0] = j * 32 + 16;
					map->player[1] = i * 32 + 16;
				}
				else
				{
					map->enemy[0] = j * 32 + 16;
					map->enemy[1] = i * 32 + 16;
				}
				map->n_chars++;
			}
			j--;
		}
		i--;
	}
}

t_map	*init_map(t_mapgen *mapg)
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
	return (map);
}
