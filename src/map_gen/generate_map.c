#include "../cub3d.h"

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

static t_mapgen	*init_mapg(int size)
{
	t_mapgen	*mapg;

	mapg = malloc(sizeof(t_mapgen));
	if (!mapg)
		ft_error("allocation failed", NULL);
	mapg->map = create_array(size);
	mapg->start[0] = get_random_num(0, size);
	mapg->start[1] = get_random_num(0, size);
	mapg->player_start[0] = mapg->start[0];
	mapg->player_start[1] = mapg->start[1];
	init_directions(mapg);
	mapg->rand = get_random_num(0, 3);
	mapg->rand_dir[0] = mapg->dirs[mapg->rand][0];
	mapg->rand_dir[1] = mapg->dirs[mapg->rand][1];
	mapg->size = size;
	return (mapg);
}

static int	carve_tunnel(t_mapgen *mapg, int size, int tunnel_len)
{
	int	i;
	int	len;

	i = 0;
	len = get_random_num(tunnel_len / 2, tunnel_len);
	while (i < len)
	{
		if ((mapg->start[0] + mapg->rand_dir[0]) >= 0
			&& (mapg->start[1] + mapg->rand_dir[1]) >= 0
			&& (mapg->start[0] + mapg->rand_dir[0]) < size
			&& (mapg->start[1] + mapg->rand_dir[1]) < size)
		{
			mapg->map[mapg->start[0]][mapg->start[1]] = '0';
			mapg->start[0] += mapg->rand_dir[0];
			mapg->start[1] += mapg->rand_dir[1];
			i++;
		}
		else
			break ;
	}
	mapg->last_dir[0] = mapg->rand_dir[0];
	mapg->last_dir[1] = mapg->rand_dir[1];
	return (i);
}

t_mapgen	*create_map(int size, int tunnels, int tunnel_len, int end_len)
{
	t_mapgen	*mapg;

	mapg = init_mapg(size);
	while (tunnels)
	{
		end_len = carve_tunnel(mapg, size, tunnel_len);
		while (true)
		{
			if ((mapg->rand_dir[0] == mapg->last_dir[0]
					&& mapg->rand_dir[1] == mapg->last_dir[1])
				|| (mapg->rand_dir[0] == -mapg->last_dir[0]
					&& mapg->rand_dir[1] == -mapg->last_dir[1]))
			{
				mapg->rand = get_random_num(0, 3);
				mapg->rand_dir[0] = mapg->dirs[mapg->rand][0];
				mapg->rand_dir[1] = mapg->dirs[mapg->rand][1];
			}
			else
				break ;
		}
		if (end_len)
			tunnels--;
	}
	refactor_map(mapg);
	return (mapg);
}
