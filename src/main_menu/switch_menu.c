#include "../includes/cub3d.h"

void	to_menu(t_game *game)
{
	int	i;

	game->crosshair->enabled = false;
	game->map->floor->enabled = false;
	game->map->out->enabled = false;
	game->map->wall->enabled = false;
	game->chars[0]->ray->img->enabled = false;
	game->menu->imgs[6]->enabled = true;
	game->menu->imgs[7]->enabled = true;
	game->menu->imgs[9]->enabled = true;
	game->menu->imgs[11]->enabled = true;
	while (i < game->n_chars)
	{
		game->chars[i]->img->enabled = false;
		i++;
	}
	game->menu->back_frame = 0;
	game->menu->scroll_frame = 13;
	mlx_set_cursor_mode(game->mlx, MLX_MOUSE_NORMAL);
	game->menu->in_menu = true;
}

void	to_game(t_game *game)
{
	int	i;

	if (game->menu->scroll_mode != 'N')
	{
		game->menu->scroll_mode = 'C';
		return ;
	}
	mlx_set_cursor_mode(game->mlx, MLX_MOUSE_HIDDEN);
	game->crosshair->enabled = true;
	game->map->floor->enabled = true;
	game->map->out->enabled = true;
	game->map->wall->enabled = true;
	game->chars[0]->ray->img->enabled = true;
	i = 0;
	while (i < 12)
	{
		game->menu->imgs[i]->enabled = false;
		i++;
	}
	i = 0;
	while (i < game->n_chars)
	{
		game->chars[i]->img->enabled = true;
		i++;
	}
	mlx_set_mouse_pos(game->mlx, WIDTH / 2, HEIGHT / 2);
	game->menu->in_menu = false;
}