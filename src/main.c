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
	mlx_image_to_window(game->mlx, game->game_img, 0, 0);
	return (game);
}

static t_game	*init_game(t_map *map)
{
	t_game	*game;

	game = alloc_game(map);
	game->end = malloc(sizeof(t_end));
	if (game->end == NULL)
		ft_error("allocation error", NULL);
	game->sounds->sound = true;
	game->end->in_end = false;
	game->loot = 0;
	game->torch_frame = 0;
	get_map_textures(game);
	draw_map(game, game->map);
	return (game);
}

int	main(void)
{
	t_map		*map;
	t_game		*game;
	t_mapgen	*mapg;

	mapg = create_map(30, 110, 15, 0);
	map = init_map(mapg);
	game = init_game(map);
	main_menu(game);
	mlx_loop(game->mlx);
	free_exit(map, game);
	system("leaks cub3d");
	return (EXIT_SUCCESS);
}
