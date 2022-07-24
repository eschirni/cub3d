#include "includes/cub3d.h"

static void	animate_cat(t_end *end)
{
	int	i;

	i = 0;
	while (i < 31)
	{
		end->cat[i]->enabled = false;
		i++;
	}
	end->cat[end->cat_frame]->enabled = true;
	end->cat_frame++;
	if (end->cat[0]->instances[0].x < end->end_pos || (end->cat_frame > 21 && end->cat_frame != 30))
	{
		if (end->cat_frame > 30)
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
	while (i < 31)
	{
		end->cat[i]->instances[0].x++;
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

static void	load_png(t_game *game, int pos, char *name, bool cat)
{
	mlx_texture_t	*txt;
	mlx_image_t		**arr;
	int				y;

	arr = game->end->cat;
	y = 700;
	if (cat == false)
	{
		y = 0;
		arr = game->end->back;
	}
	txt = mlx_load_png(name);
	arr[pos] = mlx_texture_to_image(game->mlx, txt);
	mlx_delete_texture(txt);
	mlx_image_to_window(game->mlx, arr[pos], 0, y);
}

static void	init_textures(t_game *game)
{
	char	*score;
	char	*tmp;

	load_png(game, 0, "./sprites/end/back.png", false);
	load_png(game, 1, "./sprites/end/back1.png", false);
	load_png(game, 2, "./sprites/end/back2.png", false);
	load_png(game, 3, "./sprites/end/back3.png", false);
	load_png(game, 4, "./sprites/end/back4.png", false);
	load_png(game, 5, "./sprites/end/back5.png", false);
	load_png(game, 6, "./sprites/end/back6.png", false);
	load_png(game, 7, "./sprites/end/back7.png", false);
	load_png(game, 0, "./sprites/end/cat/cat_sitting.png", true);
	load_png(game, 1, "./sprites/end/cat/cat_sitting1.png", true);
	load_png(game, 2, "./sprites/end/cat/cat_sitting2.png", true);
	load_png(game, 3, "./sprites/end/cat/cat_sitting3.png", true);
	load_png(game, 4, "./sprites/end/cat/cat_sitting4.png", true);
	load_png(game, 5, "./sprites/end/cat/cat_sitting5.png", true);
	load_png(game, 6, "./sprites/end/cat/cat_sitting6.png", true);
	load_png(game, 7, "./sprites/end/cat/cat_sitting7.png", true);
	load_png(game, 8, "./sprites/end/cat/cat_sitting8.png", true);
	load_png(game, 9, "./sprites/end/cat/cat_sitting9.png", true);
	load_png(game, 10, "./sprites/end/cat/cat_sitting10.png", true);
	load_png(game, 11, "./sprites/end/cat/cat_sitting11.png", true);
	load_png(game, 12, "./sprites/end/cat/cat_sitting12.png", true);
	load_png(game, 13, "./sprites/end/cat/cat_sitting13.png", true);
	load_png(game, 14, "./sprites/end/cat/cat_sitting14.png", true);
	load_png(game, 15, "./sprites/end/cat/cat_sitting15.png", true);
	load_png(game, 16, "./sprites/end/cat/cat_sitting16.png", true);
	load_png(game, 17, "./sprites/end/cat/cat_sitting17.png", true);
	load_png(game, 18, "./sprites/end/cat/cat_sitting18.png", true);
	load_png(game, 19, "./sprites/end/cat/cat_sitting19.png", true);
	load_png(game, 20, "./sprites/end/cat/cat_sitting20.png", true);
	load_png(game, 21, "./sprites/end/cat/cat_walk.png", true);
	load_png(game, 22, "./sprites/end/cat/cat_walk1.png", true);
	load_png(game, 23, "./sprites/end/cat/cat_walk2.png", true);
	load_png(game, 24, "./sprites/end/cat/cat_walk3.png", true);
	load_png(game, 25, "./sprites/end/cat/cat_walk4.png", true);
	load_png(game, 26, "./sprites/end/cat/cat_walk5.png", true);
	load_png(game, 27, "./sprites/end/cat/cat_walk6.png", true);
	load_png(game, 28, "./sprites/end/cat/cat_walk7.png", true);
	load_png(game, 29, "./sprites/end/cat/cat_walk8.png", true);
	load_png(game, 30, "./sprites/end/cat/cat_walk9.png", true);
	score = ft_strcdup("Score: ", '\0', 0);
	tmp = ft_itoa(game->loot * 100);
	score = ft_append(score, tmp);
	mlx_put_string(game->mlx, score, 900, 100);
	free(score);
	free(tmp);
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
	init_textures(game);
	mlx_set_cursor_mode(game->mlx, MLX_MOUSE_NORMAL);
	system("pkill afplay &");
	if (game->loot > 0)
		system("afplay music/end.mp3 &");
	else
		system("afplay music/sad_end.mp3 &");
	game->end->music_start = time.tv_sec;
	game->end->in_end = true;
}
