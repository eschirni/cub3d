#include "../includes/cub3d.h"

static void	free_screens(t_game *game)
{
	int	i;

	i = 0;
	while (i < 69)
	{
		mlx_delete_image(game->mlx, game->menu->imgs[i]);
		i++;
	}
	free(game->menu->settings);
	free(game->menu);
	i = 0;
	while (i < 8)
	{
		mlx_delete_image(game->mlx, game->end->back[i]);
		i++;
	}
	free(game->end);
}

static void	free_arrs(t_game *game)
{
	int	i;

	free_screens(game);
	i = 0;
	while (game->map->big_map[i] != NULL)
	{
		free(game->map->big_map[i]);
		i++;
	}
	i = 0;
	mlx_delete_image(game->mlx, game->chars[0]->ray->img);
	free(game->chars[0]->ray);
	while (i < game->map->n_chars)
	{
		mlx_delete_image(game->mlx, game->chars[i]->img);
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
	mlx_delete_image(game->mlx, game->map->doorv);
	mlx_delete_image(game->mlx, game->map->doorh);
	mlx_delete_image(game->mlx, game->map->exit);
	mlx_delete_image(game->mlx, game->game_img);
	mlx_delete_image(game->mlx, game->torch);
	mlx_terminate(game->mlx);
	free(game->textures->wall);
	free(game->textures->floor);
	free(game->textures->door);
	free(game->textures->door_o);
	free(game->textures->exit);
	free(game->textures);
	free(game->sounds);
	free(game);
	free(map->big_map);
	free(map);
	system("pkill afplay &");
}
