#include "../includes/cub3d.h"

void	refactor_map(t_mapgen *mapg, int i, int j)
{
	char	**new;

	mapg->map[mapg->player_start[1]][mapg->player_start[0]] = 'N';
	new = malloc(sizeof(char *) * (mapg->size + 3));
	if (!new)
		ft_error("allocation failed", NULL);
	new[mapg->size + 2] = NULL;
	while (i < mapg->size + 2)
	{
		j = 0;
		new[i] = malloc(mapg->size + 3);
		if (!new[i])
			ft_error("allocation failed", NULL);
		while (j < mapg->size + 2)
		{
			if (i == 0 || i == mapg->size + 1 || j == 0 || j == mapg->size + 1)
				new[i][j] = '1';
			else
				new[i][j] = mapg->map[i - 1][j - 1];
			j++;
		}
		new[i++][mapg->size + 2] = 0;
	}
	free_2d_array(mapg->map);
	mapg->map = new;
}

int	get_random_num(int from, int to)
{
	int	num;

	num = (time(0) * rand() % (to - from + 1)) + from;
	return (num);
}
