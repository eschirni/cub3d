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
	// mapg = create_map(20, 60, 8, 0); //1. mapsize, 2. amount of tunnels, 3. max length of tunnels, 4. do not change >:(
	map = init_map(argv[1]);
	game = init_game(map);
	main_menu(game);
	mlx_loop(game->mlx);
	free_exit(map, game);
	system("leaks cub3D");
	return (EXIT_SUCCESS);
}
