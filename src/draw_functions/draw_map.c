#include "../includes/cub3d.h"

void	get_map_textures(t_game *game)
{
	mlx_texture_t	*text;

	text = mlx_load_png("./sprites/tile_floor.png");
	game->map->floor = mlx_texture_to_image(game->mlx, text);
	mlx_delete_texture(text);
	if (!mlx_resize_image(game->map->floor, 32, 32))
		ft_error("can't resize image", NULL);
	text = mlx_load_png("./sprites/tile_wall.png");
	game->map->wall = mlx_texture_to_image(game->mlx, text);
	mlx_delete_texture(text);
	if (!mlx_resize_image(game->map->wall, 32, 32))
		ft_error("can't resize image", NULL);
	text = mlx_load_png("./sprites/tile_water.png");
	game->map->out = mlx_texture_to_image(game->mlx, text);
	mlx_delete_texture(text);
	if (!mlx_resize_image(game->map->out, 32, 32))
		ft_error("can't resize image", NULL);
}

static void	draw_tiles(t_game *game, char **arr)
{
	int	i;
	int	j;
	int	x;
	int	y;

	i = -4;
	y = -128;
	while (i < game->map->y + 4)
	{
		j = -4;
		x = -128;
		while (j < game->map->x + 4)
		{
			if (i < 0 || j < 0 || i >= game->map->y || j >= game->map->x)
				mlx_image_to_window(game->mlx, game->map->out, x, y);
			else if (arr[i][j] == '0')
				mlx_image_to_window(game->mlx, game->map->floor, x, y);
			else if (arr[i][j] == '1')
				mlx_image_to_window(game->mlx, game->map->wall, x, y);
			else if (is_char_obj(arr[i][j]) == true)
			{
				game->n_chars++;
				mlx_image_to_window(game->mlx, game->map->floor, x, y);
			}
			j++;
			x += 32;
		}
		i++;
		y += 32;
	}
}

void	draw_map(t_game *game, t_map *map) //draw the map with lower z value than the 3d instead of every frame
{
	draw_tiles(game, map->big_map);
	draw_chars(game, map->big_map);
}
