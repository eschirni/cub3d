#include "cub3d.h"
#include <sys/time.h>

static char	**create_array(int size)
{
	char	**map;
	int		i;
	int		j;

	i = 0;
	map = malloc(sizeof(char *) * size + 1);
	if (!map)
		ft_error("allocation failed", NULL);
	map[size] = NULL;
	while (i < size)
	{
		j = 0;
		map[i] = malloc(size + 1);
		while (j < size)
		{
			map[i][j] = '1';
			j++;
		}
		map[i][size] = 0;
		i++;
	}
	return (map);
}

static int	get_random_num(int from, int to)
{
	int	num;

	num = (time(0) * rand() % (to -from + 1)) + from;
	return (num);
}

static void	init_directions(t_mapgen *mapg)
{
	mapg->dirs[0][0] = -1;
	mapg->dirs[0][1] = 0;
	mapg->dirs[1][0] = 1;
	mapg->dirs[1][1] = 0;
	mapg->dirs[2][0] = 0;
	mapg->dirs[2][1] = -1;
	mapg->dirs[3][0] = 0;
	mapg->dirs[3][1] = 1;
}

t_mapgen	*create_map(int size, int tunnels, int tunnel_len)
{
	t_mapgen	*mapg;
	int			rand;
	int			i;
	int			len;
	bool		valid_path;

	mapg = malloc(sizeof(t_mapgen));
	if (!mapg)
		ft_error("allocation failed", NULL);
	mapg->map = create_array(size);
	mapg->start[0] = get_random_num(0, size);
	mapg->start[1] = get_random_num(0, size);
	init_directions(mapg);
	rand = get_random_num(0, 3);
	mapg->rand_dir[0] = mapg->dirs[rand][0];
	mapg->rand_dir[1] = mapg->dirs[rand][1];
	while (tunnels)
	{
		i = 0;
		len = get_random_num(tunnel_len / 2, tunnel_len);
		while (i < len)
		{
			if ((mapg->start[0] + mapg->rand_dir[0]) >= 0 && (mapg->start[1] + mapg->rand_dir[1]) >= 0
				&& (mapg->start[0] + mapg->rand_dir[0]) < size && (mapg->start[1] + mapg->rand_dir[1]) < size)
			{
				mapg->map[mapg->start[0]][mapg->start[1]] = '0';
				mapg->start[0] += mapg->rand_dir[0];
				mapg->start[1] += mapg->rand_dir[1];
				i++;
			}
			else
				break;
		}
		mapg->last_dir[0] = mapg->rand_dir[0];
		mapg->last_dir[1] = mapg->rand_dir[1];
		valid_path = false;
		while (!valid_path)
		{
			if ((mapg->rand_dir[0] == mapg->last_dir[0] && mapg->rand_dir[1] == mapg->last_dir[1])
				|| (mapg->rand_dir[0] == -mapg->last_dir[0] && mapg->rand_dir[1] == -mapg->last_dir[1]))
			{
				rand = get_random_num(0, 3);
				mapg->rand_dir[0] = mapg->dirs[rand][0];
				mapg->rand_dir[1] = mapg->dirs[rand][1];
			}
			else
				valid_path = true;
		}
		if (i)
			tunnels--;
	}
	return (mapg);
}
