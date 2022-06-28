#include "../cub3d.h"

static void	draw_char(t_game *game, int x, int y, int n)
{
	mlx_texture_t	*player;

	if (n != 0)
		player = mlx_load_png("./sprites/tile_red.png");
	else
		player = mlx_load_png("./sprites/tile_green.png");
	if (player == NULL)
		ft_error("can't load image", NULL);
	game->chars[n]->img = mlx_texture_to_image(game->mlx, player);
	if (!mlx_resize_image(game->chars[n]->img, 16, 16))
		ft_error("can't resize image", NULL);
	if (game->chars[n]->img == NULL)
		ft_error("char image allocation failed", NULL);
	mlx_delete_texture(player);
	mlx_image_to_window(game->mlx, game->chars[n]->img, x, y);
}

static int	count_init_chars(t_game *game)
{
	int	n;

	game->chars = malloc(sizeof(t_char) * game->n_chars);
	if (game->chars == NULL)
		ft_error("no char could be allocated", NULL);
	n = 0;
	while (n < game->n_chars)
	{
		game->chars[n] = malloc(sizeof(t_char));
		if (game->chars[n] == NULL)
			ft_error("allocation error", NULL);
		n++;
	}
	return (n);
}

void	draw_chars(t_game *game, char **map)
{
	int	i;
	int	j;
	int	chrs;

	i = 0;
	chrs = count_init_chars(game);
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (is_char_obj(map[i][j]))
			{
				draw_char(game, j * 32 + 8, i * 32 + 8, --chrs);
				set_direction(game, map[i][j], chrs);
			}
			j++;
		}
		i++;
	}
}
