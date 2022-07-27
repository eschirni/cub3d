#include "includes/cub3d.h"

static t_game	*alloc_game(t_map *map)
{
	t_game			*game;

	game = malloc(sizeof(t_game));
	if (game == NULL)
		ft_error("allocation error", NULL);
	game->mlx = mlx_init(WIDTH, HEIGHT, "CUB3D", false);
	if (!game->mlx)
		ft_error("mlx allocation failed", NULL);
	game->map = map;
	game->game_img = mlx_new_image(game->mlx, WIDTH, HEIGHT);
	return (game);
}

static t_game	*init_game(t_map *map)
{
	t_game	*game;

	game = alloc_game(map);
	get_map_textures(game);
	draw_map(game, game->map);
	return (game);
}

int	main(int argc, char **argv)
{
	t_map		*map;
	t_game		*game;

	if (argc != 2)
		ft_error("bad arguments", NULL);
	map = init_map(argv[1]);
	game = init_game(map);
	init_textures(game);
	mlx_set_cursor_mode(game->mlx, MLX_MOUSE_HIDDEN);
	mlx_set_mouse_pos(game->mlx, WIDTH / 2, HEIGHT / 2);
	mlx_loop_hook(game->mlx, &fps, game);
	mlx_loop(game->mlx);
	free_exit(map, game);
	system("leaks cub3D");
	return (EXIT_SUCCESS);
}
