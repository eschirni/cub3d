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
	game->sounds = malloc(sizeof(t_sounds));
	if (game->sounds == NULL)
		ft_error("allocation error", NULL);
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
	game->loot = 0;
	get_map_textures(game);
	draw_map(game, game->map);
	game->sounds->sound = true;
	return (game);
}

int	main(void)
{
	t_map		*map;
	t_game		*game;
	t_mapgen	*mapg;

	mapg = create_map(30, 90, 10, 0); //1. mapsize, 2. amount of tunnels, 3. max length of tunnels, 4. do not change >:(
	map = init_map(mapg);
	game = init_game(map);
	main_menu(game);
	mlx_loop(game->mlx);
	free_exit(map, game);
	system("leaks cub3d");
	return (EXIT_SUCCESS);
}
