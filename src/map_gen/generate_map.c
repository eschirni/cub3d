#include "../includes/cub3d.h"

// static void	print_2d_array(char **array)
// {
// 	int	i;
// 	int	j;

// 	if (!array)
// 		printf("Array empty.\n");
// 	i = 0;
// 	while (array[i])
// 	{
// 		j = 0;
// 		while (array[i][j])
// 		{
// 			if (array[i][j] == 'L' || array[i][j] == 'W' || array[i][j] == 'X')
// 			{
// 				printf("\033[0;31m");
// 				printf("%c", array[i][j]);
// 				printf("\033[0m");
// 			}
// 			else
// 				printf("%c", array[i][j]);
// 			j++;
// 		}
// 		printf("\n");
// 		i++;
// 	}
// 	printf("\n");
// }

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

static t_mapgen	*init_mapg(int size, int tunnel_len)
{
	t_mapgen	*mapg;

	if (size <= 4)
		ft_error("map too small", NULL);
	else if (tunnel_len == 0)
		ft_error("tunnel length should never be 0", NULL);
	mapg = malloc(sizeof(t_mapgen));
	if (!mapg)
		ft_error("allocation failed", NULL);
	mapg->map = create_array(size);
	mapg->start[0] = get_random_num(0, size - 1);
	mapg->start[1] = get_random_num(0, size - 1);
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
	len = get_random_num(0, tunnel_len);
	while (i < len)
	{
		if ((mapg->start[0] + mapg->rand_dir[0]) >= 0
			&& (mapg->start[1] + mapg->rand_dir[1]) >= 0
			&& (mapg->start[0] + mapg->rand_dir[0]) < size
			&& (mapg->start[1] + mapg->rand_dir[1]) < size)
		{
			mapg->map[mapg->start[1]][mapg->start[0]] = '0';
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

// static int	surroundings(char **map, int i, int j, char c)
// {
// 	int	x;
// 	int	y;

// 	y = i - 1;
// 	while (y <= i + 1)
// 	{
// 		x = j - 1;
// 		while (x <= j + 1)
// 		{
// 			if (map[y][x] != '0' && map[y][x] != c)
// 				return (0);
// 			x++;
// 		}
// 		y++;
// 	}
// 	return (1);
// }

static t_mapgen	*checker(t_mapgen *mapg)
{
	int	i;
	int	j;
	int	loot;
	int	exit;
	int	enemy;

	i = 0;
	loot = 0;
	exit = 0;
	enemy = 0;
	while (mapg->map[i])
	{
		j = 0;
		while (mapg->map[i][j])
		{
			if (mapg->map[i][j] == 'W')
				enemy++;
			else if (mapg->map[i][j] == 'X')
				exit++;
			else if (mapg->map[i][j] == 'L' || mapg->map[i][j] == 'l')
				loot++;
			j++;
		}
		i++;
	}
	if (!loot)
		printf("No loot.\n");
	else if (!enemy)
		printf("No enemies.\n");
	else if (!exit)
		printf("No exit.\n");
	printf("%d chests\n%d enemies\n", loot, enemy);
	return (mapg);
}

t_mapgen	*create_map(int size, int tunnels, int tunnel_len, int end_len)
{
	t_mapgen	*mapg;

	mapg = init_mapg(size, tunnel_len);
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
	refactor_map(mapg, 0, 0);
	// print_2d_array(mapg->map);
	mapg = checker(mapg);
	return (mapg);
}
