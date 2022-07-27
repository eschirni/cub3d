#include "../includes/main_menu.h"

void	load_png(t_game *game, int pos, char *name, bool enabled)
{
	mlx_texture_t	*txt;

	txt = mlx_load_png(name);
	game->menu->imgs[pos] = mlx_texture_to_image(game->mlx, txt);
	mlx_delete_texture(txt);
	game->menu->imgs[pos]->enabled = enabled;
}

void	main_menu(t_game *game)
{
	game->menu = malloc(sizeof(t_menu));
	if (game->menu == NULL)
		ft_error("Malloc error!", NULL);
	init_settings(game);
	init_textures(game);
	to_game(game);
	mlx_loop_hook(game->mlx, &fps, game);
}
