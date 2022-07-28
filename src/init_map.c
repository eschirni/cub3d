/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschirni <eschirni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 10:06:24 by eschirni          #+#    #+#             */
/*   Updated: 2022/07/28 12:42:10 by eschirni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

static void	mark_player(t_game *game, t_map *map)
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
				map->player[0] = j * 32 + 16;
				map->player[1] = i * 32 + 16;
				game->chr = malloc(sizeof(t_char));
				if (game->chr == NULL)
					ft_error("allocation error", NULL);
				set_direction(game, map->big_map[i][j]);
			}
			j--;
		}
		i--;
	}
}

void	init_map(t_game *game, char *mapfile)
{
	t_map	*map;
	int		fd;
	int		i;

	fd = open(mapfile, O_RDONLY);
	if (fd == -1 || !check_file(mapfile))
		ft_error("invalid map: ", mapfile);
	map = malloc(sizeof(t_map));
	map->y = get_size(mapfile);
	map->file = malloc(sizeof(char *) * (map->y + 1));
	if (!map->file)
		ft_error("malloc failed", NULL);
	map->file[0] = get_next_line(fd);
	i = 0;
	while (map->file[i] != NULL)
	{
		i++;
		map->file[i] = get_next_line(fd);
	}
	close(fd);
	map_checker(map);
	map->x = ft_strlen_sl(map->big_map[0]);
	mark_player(game, map);
	check_map_closed(map);
	game->map = map;
}
