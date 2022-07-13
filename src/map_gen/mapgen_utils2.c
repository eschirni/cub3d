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
				mapg->map[i][j] = ' ';
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
				mapg->map[i][j] = ' ';
			j++;
		}
		i++;
	}
	corner_check(mapg);
}