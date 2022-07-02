#include "includes/cub3d.h"

static size_t	ft_strlen_sl(const char *str)
{
	size_t	len;

	len = 0;
	if (!str)
		return (0);
	while (str[len] != '\0' && str[len] != '\n')
		len++;
	return (len);
}

static int	get_size(char *mapfile)
{
	int		fd;
	char	*line;
	int		count;

	fd = open(mapfile, O_RDONLY);
	line = get_next_line(fd);
	count = 0;
	while (line)
	{
		count++;
		free(line);
		line = get_next_line(fd);
	}
	if (line)
		free(line);
	close(fd);
	if (count == 0)
		ft_error("empty map: ", mapfile);
	return (count);
}

static void	mark_player(t_map *map)
{
	int	i;
	int	j;

	i = map->y - 1;
	while (i >= 0)
	{
		j = map->x - 1;
		while (j >= 0)
		{
			if (is_char_obj(map->big_map[i][j]))
			{
				map->player[0] = j * 32 + 8;
				map->player[1] = i * 32 + 8;
				return ;
			}
			j--;
		}
		i--;
	}
}

t_map	*init_map(char *mapfile)
{
	t_map	*map;
	int		fd;
	int		i;

	fd = open(mapfile, O_RDONLY);
	if (fd == -1 || !check_file(mapfile))
		ft_error("invalid map: ", mapfile);
	map = malloc(sizeof(t_map));
	map->y = get_size(mapfile);
	map->big_map = malloc(sizeof(char *) * map->y + 1);
	if (!map->big_map)
		ft_error("malloc failed", NULL);
	i = 0;
	while (i <= map->y)
	{
		map->big_map[i] = get_next_line(fd);
		i++;
	}
	close (fd);
	map->x = ft_strlen_sl(map->big_map[0]);
	mark_player(map);
	return (map);
}
