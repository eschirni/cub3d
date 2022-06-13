#include "cub3d.h"

void	draw_map(t_game *game, t_map *map)
{
	int				i;
	int				j;
	mlx_texture_t	*floor;
	mlx_texture_t	*wall;

	floor = mlx_load_png("./sprites/blue_tile.png");
	game->chars[1]->img = mlx_texture_to_image(game->mlx, floor);
	mlx_delete_texture(floor);
	if (!mlx_resize_image(game->chars[1]->img, 31, 31))
		ft_error("can't resize image", NULL);
	wall = mlx_load_png("./sprites/yellow_tile.png");
	game->chars[2]->img = mlx_texture_to_image(game->mlx, wall);
	mlx_delete_texture(wall);
	if (!mlx_resize_image(game->chars[2]->img, 31, 31))
		ft_error("can't resize image", NULL);
	i = 0;
	while (map->map_arr[i])
	{
		j = 0;
		while (map->map_arr[i][j])
		{
			if (map->map_arr[i][j] == '0')
				mlx_image_to_window(game->mlx, game->chars[1]->img, j * 32, i * 32);
			else if (map->map_arr[i][j] == '1')
				mlx_image_to_window(game->mlx, game->chars[2]->img, j * 32, i * 32);
			j++;
		}
		i++;
	}
}
