/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapgen_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btenzlin <btenzlin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 10:06:26 by btenzlin          #+#    #+#             */
/*   Updated: 2022/07/28 10:06:27 by btenzlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	set_positions(t_mapgen *mapg)
{
	mapg->exit[0] = mapg->start[0];
	mapg->exit[1] = mapg->start[1];
	mapg->map[mapg->exit[1]][mapg->exit[0]] = 'X';
	mapg->map[mapg->player_start[1]][mapg->player_start[0]] = 'N';
}

void	refactor_map(t_mapgen *mapg, int i, int j)
{
	char	**new;

	set_positions(mapg);
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
		while (++j < mapg->size + 2)
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

void	set_entities(char **map, char c, int chance)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '0' && (get_random_num(1, 100) < chance))
					map[i][j] = c;
			j++;
		}
		i++;
	}
}

int	get_random_num(int from, int to)
{
	int	fd;
	int	num;

	fd = open("/dev/urandom", O_RDONLY);
	if (!fd)
		ft_error("failed to open file", NULL);
	if (read(fd, &num, sizeof(num)) == -1)
		ft_error("failed to read from file", NULL);
	num = abs((num * rand() % (to - from + 1)) + from);
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
