#include "includes/cub3d.h"

static void	init_dir(t_game *game, float pi)
{
	game->chr->ray = malloc(sizeof(t_ray));
	game->chr->pa = pi;
}

void	set_direction(t_game *game, char direction)
{
	if (direction == 'N')
		init_dir(game, (float)M_PI_2 + (float)M_PI);
	else if (direction == 'E')
		init_dir(game, (float)M_PI * 2);
	else if (direction == 'S')
		init_dir(game, (float)M_PI_2);
	else if (direction == 'W')
		init_dir(game, (float)M_PI);
}
