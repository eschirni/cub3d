#include "includes/cub3d.h"

void	animate_end(t_end *end)
{
	struct timeval	time;
	int				i;
	long			now;

	if (gettimeofday(&time, NULL) == -1)
		ft_error("Error while reading the time", NULL);
	now = time.tv_sec * 1000 + time.tv_usec / 1000;
	if (now > end->back_seconds + 150)
	{
		end->back_seconds = now;
		i = 0;
		while (i < 8)
		{
			end->imgs[i]->enabled = false;
			i++;
		}
		end->imgs[end->back_frame]->enabled = true;
		end->back_frame++;
		if (end->back_frame > 7)
			end->back_frame = 0;
	}
}

static void	load_png(t_game *game, int pos, char *name, bool enabled)
{
	mlx_texture_t	*txt;

	txt = mlx_load_png(name);
	game->end->imgs[pos] = mlx_texture_to_image(game->mlx, txt);
	mlx_delete_texture(txt);
	game->end->imgs[pos]->enabled = enabled;
	mlx_image_to_window(game->mlx, game->end->imgs[pos], 0, 0);
}

static void	init_textures(t_game *game)
{
	load_png(game, 0, "./sprites/end/end.png", true);
	load_png(game, 1, "./sprites/end/end1.png", false);
	load_png(game, 2, "./sprites/end/end2.png", false);
	load_png(game, 3, "./sprites/end/end3.png", false);
	load_png(game, 4, "./sprites/end/end4.png", false);
	load_png(game, 5, "./sprites/end/end5.png", false);
	load_png(game, 6, "./sprites/end/end6.png", false);
	load_png(game, 7, "./sprites/end/end7.png", false);
}

static void	disable_game(t_game *game)
{
	int	i;

	game->map->floor->enabled = false;
	game->map->out->enabled = false;
	game->map->wall->enabled = false;
	game->map->chest->enabled = false;
	game->map->exit->enabled = false;
	game->map->doorh->enabled = false;
	game->map->doorv->enabled = false;
	game->chars[0]->ray->img->enabled = false;
	i = 0;
	while (i < game->map->n_chars)
	{
		game->chars[i]->img->enabled = false;
		i++;
	}
}

void	end_game(t_game *game)
{
	disable_game(game);
	game->end->back_seconds = 0;
	game->end->back_frame = 0;
	init_textures(game);
	mlx_set_cursor_mode(game->mlx, MLX_MOUSE_NORMAL);
	system("pkill afplay &");
	game->end->in_end = true;
	//mlx_close_window(game->mlx);
}
