/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btenzlin <btenzlin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 20:38:41 by btenzlin          #+#    #+#             */
/*   Updated: 2022/07/28 21:10:40 by btenzlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
			else if (map[i][j] != '0' && map[i][j] != '1' && map[i][j] != ' ')
				ft_error("forbidden character in map", NULL);
			j++;
		}
		i++;
	}
	if (players != 1)
		ft_error("please set 1 starting position", NULL);
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

static char	*get_line(t_map *map, char **file, int start)
{
	int		j;
	char	*s;

	s = malloc(sizeof(char) * map->x + 1);
	if (!s)
		ft_error("failed to allocate memory", NULL);
	j = 0;
	while (j < map->x)
	{
		s[j] = file[start][j];
		j++;
		if (!file[start][j])
			j = fill_with_whitespace(s, j, map->x);
	}
	return (s);
}

static char	**get_map(t_map *map, char **file, int start)
{
	int		i;
	char	**new_map;
	int		size;

	size = get_map_size(file, start);
	if (!size)
		ft_error("map empty", NULL);
	new_map = malloc(sizeof(char *) * (size + 1));
	if (!new_map)
		ft_error("failed to allocate memory", NULL);
	map->x = get_x(file, start);
	i = 0;
	while (file[start])
	{
		new_map[i] = get_line(map, file, start);
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
	int	dirs[6];

	dirs[0] = 0;
	dirs[1] = 0;
	dirs[2] = 0;
	dirs[3] = 0;
	dirs[4] = 0;
	dirs[5] = 0;
	map->file = cut_newlines(map->file);
	start_map = extract_infos(map, map->file, dirs);
	map->big_map = get_map(map, map->file, start_map);
	free_2d_array(map->file);
	check_start_pos(map->big_map);
}
