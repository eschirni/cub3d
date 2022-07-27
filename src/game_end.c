#include "includes/cub3d.h"

static void	animate_cat(t_end *end)
{
	int	i;

	i = 0;
	while (i < 33)
	{
		end->cat[i]->enabled = false;
		i++;
	}
	end->cat[end->cat_frame]->enabled = true;
	end->cat_frame++;
	if (end->cat[0]->instances[0].x < end->end_pos
		|| (end->cat_frame > 21 && end->cat_frame != 32))
	{
		if (end->cat_frame > 32)
			end->cat_frame = 21;
	}
	else
	{
		if (end->cat_frame == 21)
			end->cat_frame = 9;
		else if (end->cat_frame > 21)
			end->cat_frame = 0;
	}
}

static void	move_cat(t_end *end)
{
	int	i;

	if (end->cat[0]->instances[0].x >= end->end_pos)
		return ;
	i = 0;
	while (i < 33)
	{
		end->cat[i]->instances[0].x += 2;
		i++;
	}
}

void	animate_end(mlx_t *mlx, t_end *end)
{
	struct timeval	time;
	int				i;
	long			now;

	move_cat(end);
	if (gettimeofday(&time, NULL) == -1)
		ft_error("Error while reading the time", NULL);
	now = time.tv_sec * 1000 + time.tv_usec / 1000;
	if (now > end->back_seconds + 150)
	{
		animate_cat(end);
		end->back_seconds = now;
		i = 0;
		while (i < 8)
		{
			end->back[i]->enabled = false;
			i++;
		}
		end->back[end->back_frame]->enabled = true;
		end->back_frame++;
		if (end->back_frame > 7)
			end->back_frame = 0;
	}
	else if (time.tv_sec > end->music_start + 63)
		mlx_close_window(mlx);
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
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		ft_error("Error while reading the time", NULL);
	disable_game(game);
	game->end->back_seconds = 0;
	game->end->back_frame = 0;
	game->end->cat_frame = 21;
	game->end->end_pos = game->loot * 100 / game->map->loot;
	game->end->end_pos = WIDTH * game->end->end_pos / 100 - 400;
	if (game->end->end_pos < 0)
		game->end->end_pos = 0;
	init_end_textures(game);
	mlx_set_cursor_mode(game->mlx, MLX_MOUSE_NORMAL);
	system("pkill afplay &");
	if (game->loot > 0)
		system("afplay music/end.mp3 &");
	else
		system("afplay music/sad_end.mp3 &");
	game->end->music_start = time.tv_sec;
	game->end->in_end = true;
}
