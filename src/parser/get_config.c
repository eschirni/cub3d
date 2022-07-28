/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_config.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btenzlin <btenzlin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 20:38:26 by btenzlin          #+#    #+#             */
/*   Updated: 2022/07/28 21:09:19 by btenzlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static char	*get_texture(char *line)
{
	char	**split_tex;
	char	*tex;

	split_tex = ft_split(line, ' ');
	if (size_2d(split_tex) != 2)
		ft_error("usage error", NULL);
	tex = ft_strdup(split_tex[1]);
	if (!tex)
		ft_error("empty texture-string", NULL);
	free_2d_array(split_tex);
	return (tex);
}

static void	set_tex_colors(t_map *map, char *line, char c)
{
	char	**split_rgb;
	char	*rgb_line;
	int		i;

	rgb_line = get_texture(line);
	count_del(rgb_line);
	split_rgb = ft_split(rgb_line, ',');
	if (size_2d(split_rgb) != 3)
		ft_error("usage error", NULL);
	i = 0;
	while (i < 3)
	{
		if (c == 'f')
			map->rgb_f[i] = cub_atoi(split_rgb[i]);
		else
			map->rgb_c[i] = cub_atoi(split_rgb[i]);
		i++;
	}
	free(rgb_line);
	free_2d_array(split_rgb);
}

static int	set_texture(t_map *map, char *line, char c)
{
	if (c == 'n')
		map->no_tex = get_texture(line);
	else if (c == 's')
		map->so_tex = get_texture(line);
	else if (c == 'w')
		map->we_tex = get_texture(line);
	else if (c == 'e')
		map->ea_tex = get_texture(line);
	else if (c == 'f')
		set_tex_colors(map, line, 'f');
	else if (c == 'c')
		set_tex_colors(map, line, 'c');
	return (1);
}

static void	get_colors(t_map *map, int dirs[6])
{
	if (!dirs[0] || !dirs[1] || !dirs[2] || !dirs[3] || !dirs[3] || !dirs[3])
		ft_error("missing texture", NULL);
	map->color_f = (map->rgb_f[0] << 24)
		+ (map->rgb_f[1] << 16) + (map->rgb_f[2] << 8) + 255;
	map->color_c = (map->rgb_c[0] << 24)
		+ (map->rgb_c[1] << 16) + (map->rgb_c[2] << 8) + 255;
}

int	extract_infos(t_map *map, char **file, int dirs[6])
{
	int			i;

	i = 0;
	while (file[i] && !is_map(file[i]))
	{
		if (!ft_strncmp(file[i], "NO ", 3) && !dirs[0])
			dirs[0] = set_texture(map, file[i], 'n');
		else if (!ft_strncmp(file[i], "SO ", 3) && !dirs[1])
			dirs[1] = set_texture(map, file[i], 's');
		else if (!ft_strncmp(file[i], "WE ", 3) && !dirs[2])
			dirs[2] = set_texture(map, file[i], 'w');
		else if (!ft_strncmp(file[i], "EA ", 3) && !dirs[3])
			dirs[3] = set_texture(map, file[i], 'e');
		else if (!ft_strncmp(file[i], "F ", 2) && !dirs[4])
			dirs[4] = set_texture(map, file[i], 'f');
		else if (!ft_strncmp(file[i], "C ", 2) && !dirs[5])
			dirs[5] = set_texture(map, file[i], 'c');
		else
			check_line(file[i]);
		i++;
	}
	get_colors(map, dirs);
	return (i);
}
