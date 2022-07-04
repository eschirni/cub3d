#include "includes/cub3d.h"

static t_game	*alloc_game(t_map *map)
{
	t_game			*game;
	mlx_texture_t	*curs_tex;
	void			*cursor;

	game = malloc(sizeof(t_game));
	if (game == NULL)
		ft_error("allocation error", NULL);
	game->mlx = mlx_init(WIDTH, HEIGHT, "CUB3D", false);
	if (!game->mlx)
		ft_error("mlx allocation failed", NULL);
	game->settings = malloc(sizeof(t_settings));
	if (game == NULL)
		ft_error("allocation error", NULL);
	game->settings->cross_type = 'E';
	game->settings->rs = 1.0f;
	game->settings->graphics = 16; //only * 2^x
	game->settings->fov = game->settings->graphics * 60 / 1; //only / 2^x
	game->map = map;
	curs_tex = mlx_load_png("./sprites/cursor.png");
	cursor = mlx_create_cursor(curs_tex);
	mlx_delete_texture(curs_tex);
	mlx_set_cursor(game->mlx, cursor);
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
	// t_mapgen	*mapg;

	if (argc != 2)
		ft_error("bad arguments", NULL);
	// mapg = create_map(20, 50, 8, 0);
	map = init_map(argv[1]);
	game = init_game(map);
	main_menu(game);
	mlx_loop(game->mlx);
	free_exit(map, game, NULL);
	system("leaks cub3d");
	return (EXIT_SUCCESS);
}
