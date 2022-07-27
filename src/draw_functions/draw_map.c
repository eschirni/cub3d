#include "../includes/cub3d.h"

static void	create_char(t_game *game, int x, int y)
{
	static int	chrs;

	chrs--;
	if (chrs == -1)
		chrs = game->map->n_chars - 1;
	game->chars[chrs] = malloc(sizeof(t_char));
	if (game->chars[chrs] == NULL)
		ft_error("allocation error", NULL);
	game->chars[chrs]->x = x + 8;
	game->chars[chrs]->y = y + 8;
}

static void	draw_tile(t_game *game, char **arr, int iterator[2], int coords[2])
{
	if (iterator[0] < 0 || iterator[1] < 0 || iterator[0] >= game->map->y || iterator[1] >= game->map->x)
		return ;
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

void	draw_map(t_game *game, t_map *map) //draw the map with lower z value than the 3d instead of every frame
{
	draw_tiles(game, map->big_map);
	draw_chars(game, map->big_map);
}
