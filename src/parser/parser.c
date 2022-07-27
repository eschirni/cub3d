#include "../includes/cub3d.h"

void	print_2d_array(char **array)
{
	int	i;
	int	j;

	if (!array)
		printf("Array empty.\n");
	i = 0;
	while (array[i])
	{
		j = 0;
		while (array[i][j])
		{
			if (array[i][j] == 'L' || array[i][j] == 'W' || array[i][j] == 'X')
			{
				printf("\033[0;31m");
				printf("%c", array[i][j]);
				printf("\033[0m");
			}
			else
				printf("%c", array[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
	printf("\n");
}

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

static char	**get_map(t_map *map, char **file, int start)
{
	int		i;
	char	**new_map;
	int		size;

	size = get_map_size(file);
	if (!size)
		ft_error("map empty", NULL);
	new_map = malloc(sizeof(char *) * (size + 1));
	if (!new_map)
		ft_error("failed to allocate memory", NULL);
	i = 0;
	while(file[start])
	{
		new_map[i] = ft_strdup(file[start]);
		start++;
		i++;
	}
	map->y = i;
	new_map[i] = NULL;
	return (new_map);
}

void	map_checker(t_map *map)
{
	int	start_map;

	map->file = cut_newlines(map->file);
	start_map = extract_infos(map, map->file, 0, 0);
	map->big_map = get_map(map, map->file, start_map);
	free_2d_array(map->file);
	// print_2d_array(map->big_map);
	check_start_pos(map->big_map);
	printf("%s\n", map->no_tex);
	printf("%s\n", map->so_tex);
	printf("%s\n", map->we_tex);
	printf("%s\n", map->ea_tex);
	// printf("%d, %d, %d\n", map->rgb_f[0], map->rgb_f[1], map->rgb_f[2]);
	// printf("%d, %d, %d\n", map->rgb_c[0], map->rgb_c[1], map->rgb_c[2]);
}
