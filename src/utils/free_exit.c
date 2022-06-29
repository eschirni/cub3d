#include "../cub3d.h"

static void	free_arrs(t_game *game)
{
	int	i;

	i = 0;
	while (game->map->map_arr[i] != NULL)
	{
		free(game->map->map_arr[i]);
		i++;
	}
	i = 0;
	while (i < 9)
	{
		mlx_delete_image(game->mlx, game->menu->imgs[i]);
		i++;
	}
	if (game->menu->in_menu == true)
		return ;
	i = 1;
	while (i < game->n_chars)
	{
		mlx_delete_image(game->mlx, game->chars[i]->img);
		free(game->chars[i]);
		i++;
	}
}

void	free_exit(t_map *map, t_game *game)
{
	free_arrs(game);
	if (game->menu->in_menu == false)
	{
		mlx_delete_image(game->mlx, game->chars[0]->img);
		mlx_delete_image(game->mlx, game->chars[0]->ray->img);
		free(game->chars[0]->ray);
		free(game->chars[0]);
		free(game->chars);
		mlx_delete_image(game->mlx, game->floor);
		mlx_delete_image(game->mlx, game->wall);
		mlx_delete_image(game->mlx, game->out);
		mlx_delete_image(game->mlx, game->game_img);
	}
	mlx_terminate(game->mlx);
	free(game->menu);
	free(game);
	free(map->map_arr);
	free(map);
}
