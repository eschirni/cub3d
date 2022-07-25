#include "../includes/cub3d.h"

// static void	corner_check(t_mapgen *mapg)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	while (mapg->map[i])
// 	{
// 		j = 0;
// 		while (mapg->map[i][j])
// 		{
// 			if (is_corner(mapg->map, i, j))
// 				mapg->map[i][j] = 'C';
// 			j++;
// 		}
// 		i++;
// 	}
// }

// int	is_corner(char **map, int i, int j)
// {
// 	int	x;
// 	int	y;
// 	int	corridor_tiles;

// 	if (map[i][j] == '0')
// 	{
// 		y = i - 1;
// 		corridor_tiles = 0;
// 		while (y <= i + 1)
// 		{
// 			x = j - 1;
// 			while (x <= j + 1)
// 			{
// 				if (map[x][y] == 'H' || map[x][y] == 'V')
// 					corridor_tiles++;
// 				x++;
// 			}
// 			y++;
// 		}
// 		if (corridor_tiles <= 2)
// 			return (1);
// 	}
// 	return (0);
// }

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
	// corner_check(mapg);
	set_entities(mapg->map, 'L', 10);
	// set_entities(mapg->map, 'W', 5);
	set_doors(mapg->map);
}
