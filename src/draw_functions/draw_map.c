#include "../cub3d.h"

static void	get_map_textures(t_game *game)
{
	mlx_texture_t	*text;

	text = mlx_load_png("./sprites/tile_floor.png");
	game->floor = mlx_texture_to_image(game->mlx, text);
	mlx_delete_texture(text);
	if (!mlx_resize_image(game->floor, 32, 32))
		ft_error("can't resize image", NULL);
	text = mlx_load_png("./sprites/tile_wall.png");
	game->wall = mlx_texture_to_image(game->mlx, text);
	mlx_delete_texture(text);
	if (!mlx_resize_image(game->wall, 32, 32))
		ft_error("can't resize image", NULL);
	text = mlx_load_png("./sprites/tile_water.png");
	game->out = mlx_texture_to_image(game->mlx, text);
	mlx_delete_texture(text);
	if (!mlx_resize_image(game->out, 32, 32))
		ft_error("can't resize image", NULL);
}

static char	**create_array(void)
{
	int		i;
	char	**ret;

	ret = malloc(9 * sizeof(char *));
	if (ret == NULL)
		ft_error("malloc failed", NULL);
	i = 0;
	while (i < 9)
	{
		ret[i] = malloc(9 * sizeof(char));
		if (ret[i] == NULL)
			ft_error("malloc failed", NULL);
		i++;
	}
	ret[i] = NULL;
	return (ret);
}

static char	**surroundings(t_map *map, int px, int py)
{
	int		i;
	int		j;
	int		x;
	char	**ret;

	i = 0;
	ret = create_array();
	while (i < 9)
	{
		j = 0;
		x = px;
		while (j < 9)
		{
			ret[i][j] = '2';
			if (x < map->x && py < map->y && x >= 0 && py >= 0
				&& map->map_arr[py][x] != ' ')
				ret[i][j] = map->map_arr[py][x];
			x++;
			j++;
		}
		ret[i][j] = '\0';
		py++;
		i++;
	}
	return (ret);
}

static void	draw_tiles(t_game *game, char **arr)
{
	int		i;
	int		j;

	i = 0;
	while (arr[i] != NULL) //If we want to do smth with the tiles afterwards, safe them in array
	{
		j = 0;
		while (arr[i][j])
		{
			if (arr[i][j] == '0')
				mlx_image_to_window(game->mlx, game->floor, j * 32, i * 32);
			else if (arr[i][j] == '1')
				mlx_image_to_window(game->mlx, game->wall, j * 32, i * 32);
			else if (arr[i][j] == '2')
				mlx_image_to_window(game->mlx, game->out, j * 32, i * 32);
			else if (is_char_obj(arr[i][j]) == true)
			{
				game->n_chars++;
				mlx_image_to_window(game->mlx, game->floor, j * 32, i * 32);
			}
			j++;
		}
		i++;
	}
}

void	draw_map(t_game *game, t_map *map, float player[2])
{
	int		i;
	char	**arr;

	get_map_textures(game);
	arr = surroundings(map, player[0] / 32 - 4, player[1] / 32 - 4);
	draw_tiles(game, arr);
	draw_chars(game, arr);
	i = 0;
	while (arr[i] != NULL)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}
