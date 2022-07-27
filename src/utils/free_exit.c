#include "../includes/cub3d.h"

static void	free_arrs(t_game *game)
{
	int	i;

	i = 0;
	while (game->map->big_map[i] != NULL)
	{
		free(game->map->big_map[i]);
		i++;
	}
	i = 0;
	free(game->chars[0]->ray);
	while (i < game->map->n_chars)
	{
		free(game->chars[i]);
		i++;
	}
	free(game->chars);
}

void	free_exit(t_map *map, t_game *game)
{
	free_arrs(game);
	mlx_delete_image(game->mlx, game->map->floor);
	mlx_delete_image(game->mlx, game->map->wall);
	mlx_delete_image(game->mlx, game->map->out);
	mlx_delete_image(game->mlx, game->game_img);
	mlx_terminate(game->mlx);
	free(game->menu);
	free(game->textures->wall);
	free(game->textures->floor);
	free(game->textures);
	free(game);
	free(map->big_map);
	free(map->no_tex);
	free(map->so_tex);
	free(map->we_tex);
	free(map->ea_tex);
	free(map);
}
