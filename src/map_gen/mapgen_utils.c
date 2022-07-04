#include "../includes/cub3d.h"

void	refactor_map(t_mapgen *mapg)
{
	int	i;
	int	j;

	i = 0;
	while (mapg->map[i])
	{
		j = 0;
		while (mapg->map[i][j])
		{
			if (i == 0 || i == mapg->size - 1 || j == 0 || !mapg->map[j + 1])
				mapg->map[i][j] = '1';
			j++;
		}
		i++;
	}
	mapg->map[mapg->player_start[1]][mapg->player_start[0]] = 'N';
}

int	get_random_num(int from, int to)
{
	int	num;

	num = (time(0) * rand() % (to - from + 1)) + from;
	return (num);
}
