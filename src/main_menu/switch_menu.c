#include "../includes/cub3d.h"

void	to_game(t_game *game)
{
	mlx_set_cursor_mode(game->mlx, MLX_MOUSE_HIDDEN);
	game->map->floor->enabled = true;
	game->map->out->enabled = true;
	game->map->wall->enabled = true;
	mlx_set_mouse_pos(game->mlx, WIDTH / 2, HEIGHT / 2);
	system("pkill afplay &");
	game->menu->in_menu = false;
}
