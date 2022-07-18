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
		j = -1;
		new[i] = malloc(mapg->size + 3);
		if (!new[i])
			ft_error("allocation failed", NULL);
		while (j++ < mapg->size + 2)
		{
			if (i == 0 || i == mapg->size + 1 || j == 0 || j == mapg->size + 1)
				new[i][j] = '1';
			else
				new[i][j] = mapg->map[i - 1][j - 1];
		}
		new[i++][mapg->size + 2] = 0;
	}
	free_2d_array(mapg->map);
	mapg->map = new;
	check_floors(mapg);
}

void	set_entities(char **map, char c)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '0' && (get_random_num(1, 100) & 9) == 0)
				// if (surroundings(map, i, j, c))
					map[i][j] = c;
			j++;
		}
		i++;
	}
}

// int	get_random_num(int from, int to)
// {
// 	int	num;

// 	num = (time(0) * rand() % (to - from + 1)) + from;
// 	return (num);
// }

int	get_random_num(int from, int to)
{
	int	fd;
	int	num;

	fd = open("/dev/random", O_RDONLY);
	if (!fd)
		printf("failed to open file");
	if (read(fd, &num, sizeof(num)) == -1)
		printf("failed to read from file");
	num = abs((num * rand() % (to -from + 1)) + from);
	close(fd);
	return (num);
}

int	is_corridor(char **map, int i, int j)
{
	if (map[i][j] == '0')
	{
		if (map[i][j + 1] == '1' && map[i][j - 1] == '1')
			return (1);
		else if (map[i + 1][j] == '1' && map[i - 1][j] == '1')
			return (2);
	}
	return (0);
}

int	is_corner(char **map, int i, int j)
{
	int	x;
	int	y;
	int	corridor_tiles;

	if (map[i][j] == '0')
	{
		y = i - 1;
		corridor_tiles = 0;
		while (y <= i + 1)
		{
			x = j - 1;
			while (x <= j + 1)
			{
				if (map[x][y] == 'H' || map[x][y] == 'V')
					corridor_tiles++;
				x++;
			}
			y++;
		}
		if (corridor_tiles <= 2)
			return (1);
	}
	return (0);
}
