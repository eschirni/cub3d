#include "../includes/cub3d.h"

int	ft_strncmp(const char *str1, const char *str2, size_t size)
{
	unsigned char	*s1;
	unsigned char	*s2;

	s1 = (unsigned char *)str1;
	s2 = (unsigned char *)str2;
	while (*s1 == ' ')
		s1++;
	while (size > 0 && (*s1 != '\0' || *s2 != '\0'))
	{
		if (*s1 == *s2)
		{
			s1++;
			s2++;
			size--;
		}
		else
		{
			return (*s1 - *s2);
		}
	}
	return (0);
}

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

int	extract_infos(t_map *map, char **file, int f, int c)
{
	int	i;
	int	no;
	int	so;
	int	we;
	int	ea;

	i = 0;
	no = 0;
	so = 0;
	we = 0;
	ea = 0;
	while (file[i] && file[i][0] != '1')
	{
		if (!ft_strncmp(file[i], "NO ", 3) && !no)
		{
			map->no_tex = get_texture(file[i]);
			no = 1;
		}
		else if (!ft_strncmp(file[i], "SO ", 3) && !so)
		{
			map->so_tex = get_texture(file[i]);
			so = 1;
		}
		else if (!ft_strncmp(file[i], "WE ", 3) && !we)
		{
			map->we_tex = get_texture(file[i]);
			we = 1;
		}
		else if (!ft_strncmp(file[i], "EA ", 3) && !ea)
		{
			map->ea_tex = get_texture(file[i]);
			ea = 1;
		}
		else if (!ft_strncmp(file[i], "F ", 2) && !f)
		{
			set_tex_colors(map, file[i], 'f');
			f = 1;
		}
		else if (!ft_strncmp(file[i], "C ", 2) && !c)
		{
			set_tex_colors(map, file[i], 'c');
			c = 1;
		}
		else
		{
			if (file[i][0] && file[i][0] != ' ')
				ft_error("config syntax error", NULL);
		}
		i++;
	}
	map->color_f = (map->rgb_f[0] << 24) + (map->rgb_f[1] << 16) + (map->rgb_f[2] << 8) + 255;
	map->color_c = (map->rgb_c[0] << 24) + (map->rgb_c[1] << 16) + (map->rgb_c[2] << 8) + 255;
	return (i);
}
