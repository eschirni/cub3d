#include "cub3d.h"

static void	draw_char(t_game *game, int x, int y, int n)
{
	mlx_texture_t	*player;

	if (n != 0)
		player = mlx_load_png("./sprites/tile_red.png");
	else
		player = mlx_load_png("./sprites/tile_green.png");
	if (player == NULL)
		ft_error("can't load image", NULL);
	game->chars[n]->img = mlx_texture_to_image(game->mlx, player);
	if (!mlx_resize_image(game->chars[n]->img, 16, 16))
		ft_error("can't resize image", NULL);
	if (game->chars[n]->img == NULL)
		ft_error("char image allocation failed", NULL);
	mlx_delete_texture(player);
	mlx_image_to_window(game->mlx, game->chars[n]->img, x, y);
}

static int	count_init_chars(t_game *game)
{
	int	n;

	game->chars = malloc(sizeof(t_char) * game->n_chars);
	if (game->chars == NULL)
		ft_error("no char could be allocated", NULL);
	n = 0;
	while (n < game->n_chars)
	{
		game->chars[n] = malloc(sizeof(t_char));
		if (game->chars[n] == NULL)
			ft_error("allocation error", NULL);
		n++;
	}
	return (n);
}

static void	draw_chars(t_game *game, char **map)
{
	int	i;
	int	j;
	int	chrs;

	i = 0;
	chrs = count_init_chars(game);
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (is_char_obj(map[i][j]))
			{
				draw_char(game, j * 32, i * 32, --chrs);
				set_direction(game, map[i][j], chrs);
			}
			j++;
		}
		i++;
	}
}

static void	get_map_textures(t_game *game)
{
	mlx_texture_t	*text;

	text = mlx_load_png("./sprites/tile_black.png");
	game->floor = mlx_texture_to_image(game->mlx, text);
	mlx_delete_texture(text);
	if (!mlx_resize_image(game->floor, 32, 32))
		ft_error("can't resize image", NULL);
	text = mlx_load_png("./sprites/tile_blue.png");
	game->wall = mlx_texture_to_image(game->mlx, text);
	mlx_delete_texture(text);
	if (!mlx_resize_image(game->wall, 32, 32))
		ft_error("can't resize image", NULL);
	text = mlx_load_png("./sprites/tile_out.png");
	game->out = mlx_texture_to_image(game->mlx, text);
	mlx_delete_texture(text);
	if (!mlx_resize_image(game->out, 32, 32))
		ft_error("can't resize image", NULL);
}

static char	**surroundings(t_map *map, int px, int py)
{
	int		i;
	int		j;
	int		x;
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
	i = 0;
	while (i < 9)
	{
		j = 0;
		x = px;
		while (j < 9)
		{
			ret[i][j] = '2';
			if (x < map->x && py < map->y && map->map_arr[py][x] != ' ')
				ret[i][j] = map->map_arr[py][x];
			x++;
			j++;
		}
		ret[i][j] = '\0';
		py++;
		i++;
	}
	ret[i] = NULL;
	return (ret);
}

void	draw_map(t_game *game, t_map *map)
{
	int		i;
	int		j;
	char	**arr;

	get_map_textures(game);
	arr = surroundings(map, map->player[0] - 4, map->player[1] - 4);
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
	draw_chars(game, arr);
	i = 0;
	while (arr[i] != NULL)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}
