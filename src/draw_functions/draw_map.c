#include "../includes/cub3d.h"

void	get_map_textures(t_game *game)
{
	mlx_texture_t	*text;

	text = mlx_load_png("./sprites/floor.png");
	game->map->floor = mlx_texture_to_image(game->mlx, text);
	mlx_delete_texture(text);
	text = mlx_load_png("./sprites/wall.png");
	game->map->wall = mlx_texture_to_image(game->mlx, text);
	mlx_delete_texture(text);
	text = mlx_load_png("./sprites/tile_water.png");
	game->map->out = mlx_texture_to_image(game->mlx, text);
	mlx_delete_texture(text);
	text = mlx_load_png("./sprites/door_ver.png");
	game->map->doorv = mlx_texture_to_image(game->mlx, text);
	mlx_delete_texture(text);
	text = mlx_load_png("./sprites/door_hor.png");
	game->map->doorh = mlx_texture_to_image(game->mlx, text);
	mlx_delete_texture(text);
	text = mlx_load_png("./sprites/floor_chest.png");
	game->map->chest = mlx_texture_to_image(game->mlx, text);
	mlx_delete_texture(text);
	text = mlx_load_png("./sprites/exit_map.png");
	game->map->exit = mlx_texture_to_image(game->mlx, text);
	mlx_delete_texture(text);
}

static void	create_char(t_game *game, int x, int y)
{
	static int	chrs;

	chrs--;
	if (chrs == -1)
		chrs = game->map->n_chars - 1;
	mlx_image_to_window(game->mlx, game->map->floor, x, y);
	game->chars[chrs] = malloc(sizeof(t_char));
	if (game->chars[chrs] == NULL)
		ft_error("allocation error", NULL);
	game->chars[chrs]->x = x + 8;
	game->chars[chrs]->y = y + 8;
}

static void	draw_tile(t_game *game, char **arr, int iterator[2], int coords[2])
{
	if (iterator[0] < 0 || iterator[1] < 0 || iterator[0] >= game->map->y
		|| iterator[1] >= game->map->x || arr[iterator[0]][iterator[1]] == ' ')
		mlx_image_to_window(game->mlx, game->map->out, coords[0], coords[1]);
	else if (arr[iterator[0]][iterator[1]] == '0'
		|| arr[iterator[0]][iterator[1]] == 'H'
		|| arr[iterator[0]][iterator[1]] == 'V')
		mlx_image_to_window(game->mlx, game->map->floor, coords[0], coords[1]);
	else if (arr[iterator[0]][iterator[1]] == '1')
		mlx_image_to_window(game->mlx, game->map->wall, coords[0], coords[1]);
	else if (arr[iterator[0]][iterator[1]] == '8')
		mlx_image_to_window(game->mlx, game->map->doorv, coords[0], coords[1]);
	else if (arr[iterator[0]][iterator[1]] == '9')
		mlx_image_to_window(game->mlx, game->map->doorh, coords[0], coords[1]);
	else if (arr[iterator[0]][iterator[1]] == 'L')
	{
		mlx_image_to_window(game->mlx, game->map->floor, coords[0], coords[1]);
		mlx_image_to_window(game->mlx, game->map->chest, coords[0], coords[1]);
	}
	else if (arr[iterator[0]][iterator[1]] == 'X')
		mlx_image_to_window(game->mlx, game->map->exit, coords[0], coords[1]);
	else if (is_char_obj(arr[iterator[0]][iterator[1]]) == true)
		create_char(game, coords[0], coords[1]);
}

static void	draw_tiles(t_game *game, char **arr)
{
	int	iterator[2];
	int	coords[2];

	game->chars = malloc(sizeof(t_char) * game->map->n_chars);
	if (game->chars == NULL)
		ft_error("no char could be allocated", NULL);
	iterator[0] = -4;
	coords[1] = abs((int)game->map->player[1] / 32 * 32) * -1; //it works without calculating offset bec the mapsize centers at 5 so 4 and 4 = 0. -1 because always start drawing up left
	while (iterator[0] < game->map->y + 4)
	{
		iterator[1] = -4;
		coords[0] = abs((int)game->map->player[0] / 32 * 32) * -1;
		while (iterator[1] < game->map->x + 4)
		{
			draw_tile(game, arr, iterator, coords);
			iterator[1]++;
			coords[0] += 32;
		}
		iterator[0]++;
		coords[1] += 32;
	}
}

static void	set_z(mlx_image_t *img, int z)
{
	int	i;

	i = 0;
	while (i < img->count)
	{
		img->instances[i].z = z;
		i++;
	}
}

void	draw_map(t_game *game, t_map *map) //draw the map with lower z value than the 3d instead of every frame
{
	int	i;

	draw_tiles(game, map->big_map);
	draw_chars(game, map->big_map);
	set_z(game->map->floor, -200);
	set_z(game->map->wall, -200);
	set_z(game->map->out, -200);
	set_z(game->map->doorv, -200);
	set_z(game->map->doorh, -200);
	set_z(game->map->chest, -150);
	set_z(game->map->exit, -200);
	i = 0;
	while (i < game->map->n_chars)
	{
		game->chars[i]->img->instances[0].z = -150;
		i++;
	}
}
