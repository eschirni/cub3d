/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschirni <eschirni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 16:05:59 by btenzlin          #+#    #+#             */
/*   Updated: 2022/06/10 20:22:05 by eschirni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// static void	print_2d_array(char **array)
// {
// 	int	i;

// 	if (!array)
// 		printf("Array empty.\n");
// 	i = 0;
// 	while (array[i])
// 	{
// 		printf("%s", array[i]);
// 		i++;
// 	}
// 	printf("\n");
// }

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

t_map	*init_map(char *mapfile)
{
	t_map	*map;
	int		fd;
	int		i;

	fd = open(mapfile, O_RDONLY);
	if (fd == -1)
		ft_error("invalid map: ", mapfile);
	map = malloc(sizeof(t_map *));
	map->y = get_size(mapfile);
	map->map_arr = malloc(sizeof(char *) * (map->y + 1));
	if (!map->map_arr)
		ft_error("malloc failed", NULL);
	i = 0;
	while (i <= map->y)
	{
		map->map_arr[i] = get_next_line(fd);
		i++;
	}
	close (fd);
	map->x = ft_strlen_sl(map->map_arr[0]);
	// print_2d_array(map->map_arr);
	return (map);
}
