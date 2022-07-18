#include "../includes/cub3d.h"

// static void	print_2d_array(char **array)
// {
// 	int	i;

// 	if (!array)
// 		printf("Array empty.\n");
// 	i = 0;
// 	while (array[i])
// 	{
// 		printf("%s\n", array[i]);
// 		i++;
// 	}
// 	printf("\n");
// }

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
			if ((map[i][j] == 'V' || map[i][j] == 'H') && (rand & 29) == 0)
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
	set_entities(mapg->map, 'L');
	set_entities(mapg->map, 'W');
	set_doors(mapg->map);
}
