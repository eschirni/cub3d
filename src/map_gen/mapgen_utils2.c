#include "../includes/cub3d.h"

static void	corner_check(t_mapgen *mapg)
{
	int	i;
	int	j;

	i = 0;
	while (mapg->map[i])
	{
		j = 0;
		while (mapg->map[i][j])
		{
			if (is_corner(mapg->map, i, j))
				mapg->map[i][j] = 'C';
			j++;
		}
		i++;
	}
}

static void	set_doors(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C' && (get_random_num(1, 100) % 30) == 0)
				map[i][j] = 'D';
			j++;
		}
		i++;
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
			if (is_corridor(mapg->map, i, j))
				mapg->map[i][j] = 'C';
			j++;
		}
		i++;
	}
	corner_check(mapg);
	set_entities(mapg->map, 'X');
	set_doors(mapg->map);
}
