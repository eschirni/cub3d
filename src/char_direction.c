#include "includes/cub3d.h"

static void	init_dir(t_game *game, int n, float pi)
{
	if (n != 0)
		return ;
	game->chars[n]->ray = malloc(sizeof(t_ray));
	game->chars[n]->ray->img = mlx_new_image(game->mlx, MINIMAP, MINIMAP);
	mlx_image_to_window(game->mlx, game->chars[n]->ray->img, 0, 0);
	game->chars[n]->pa = pi;
}

void	set_direction(t_game *game, char direction, int n)
{
	if (direction == 'N')
		init_dir(game, n, (float)M_PI_2 + (float)M_PI);
	else if (direction == 'E')
		init_dir(game, n, (float)M_PI * 2);
	else if (direction == 'S')
		init_dir(game, n, (float)M_PI_2);
	else if (direction == 'W')
		init_dir(game, n, (float)M_PI);
}
