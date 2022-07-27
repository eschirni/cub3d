#include "../includes/cub3d.h"

void	draw_chars(t_game *game, char **map)
{
	int	i;
	int	j;
	int	chrs;

	i = 0;
	chrs = game->map->n_chars - 1;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (is_char_obj(map[i][j]))
			{
				set_direction(game, map[i][j], chrs);
				chrs--;
			}
			j++;
		}
		i++;
	}
}
