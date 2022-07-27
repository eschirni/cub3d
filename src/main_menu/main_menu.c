#include "../includes/main_menu.h"

void	main_menu(t_game *game)
{
	game->menu = malloc(sizeof(t_menu));
	if (game->menu == NULL)
		ft_error("Malloc error!", NULL);
	init_textures(game);
	to_game(game);
	mlx_loop_hook(game->mlx, &fps, game);
}
