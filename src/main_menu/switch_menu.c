#include "../includes/cub3d.h"

void	to_game(t_game *game)
{
	mlx_set_cursor_mode(game->mlx, MLX_MOUSE_HIDDEN);
	game->map->floor->enabled = true;
	game->map->out->enabled = true;
	game->map->wall->enabled = true;
	game->chars[0]->ray->img->enabled = true;
	mlx_set_mouse_pos(game->mlx, WIDTH / 2, HEIGHT / 2);
	game->menu->started_game = true;
	system("pkill afplay &");
	game->menu->in_menu = false;
}
