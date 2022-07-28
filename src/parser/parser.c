#include "../includes/cub3d.h"

static void	check_start_pos(char **map)
{
	int	i;
	int	j;
	int	players;

	i = 0;
	players = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (is_char_obj(map[i][j]))
				players++;
			j++;
		}
		i++;
	}
	if (!players)
		ft_error("please set a starting position", NULL);
}

static int	get_map_size(char **file)
{
	int	i;
	int	count;

	i = 0;
	while (file [i] && file[i][0] != '1')
	{
		i++;
	}
	count = 0;
	while (file[i])
	{
		i++;
		count++;
	}
	return (count);
}

static void	print_2d_array(char **array)
{
	int	i;

	if (!array)
		printf("Array empty.\n");
	i = 0;
	while (array[i])
	{
		printf("%s\n", array[i]);
		i++;
	}
	printf("\n");
}

static int	get_x(char **file, int start)
{
	int	len;
	int	tmp;

	len = 0;
	while (file[start])
	{
		tmp = ft_strlen(file[start]);
		if (tmp > len)
			len = tmp;
		start++;
	}
	return (len);
}

static int	fill_with_whitespace(char *line, int j, int end)
{
	while (j < end)
	{
		line[j] = ' ';
		j++;
	}
	line[end] = '\0';
	return (end);
}

static char	**get_map(t_map *map, char **file, int start)
{
	int		i;
	int		j;
	char	**new_map;
	int		size;

	size = get_map_size(file);
	if (!size)
		ft_error("map empty", NULL);
	new_map = malloc(sizeof(char *) * (size + 2));
	if (!new_map)
		ft_error("failed to allocate memory", NULL);
	map->x = get_x(file, start);
	i = 0;
	while (file[start])
	{
		new_map[i] = malloc(sizeof(char) * map->x + 1);
		if (!new_map[i])
			ft_error("failed to allocate memory", NULL);
		j = 0;
		while (j < map->x)
		{
			new_map[i][j] = file[start][j];
			j++;
			if (!file[start][j])
				j = fill_with_whitespace(new_map[i], j, map->x);
		}
		start++;
		i++;
	}
	map->y = i;
	new_map[i] = NULL;
	print_2d_array(new_map);
	return (new_map);
}

void	map_checker(t_map *map)
{
	int	start_map;

	map->file = cut_newlines(map->file);
	start_map = extract_infos(map, map->file, 0, 0);
	map->big_map = get_map(map, map->file, start_map);
	free_2d_array(map->file);
	check_start_pos(map->big_map);
}
