#include "includes/cub3d.h"

static void	animate_cat(t_end *end)
{
	int	i;

	i = 0;
	while (i < 21)
	{
		end->cat[i]->enabled = false;
		i++;
	}
	end->cat[end->cat_frame]->enabled = true;
	end->cat_frame++;
	if (end->cat_frame > 20)
		end->cat_frame = 8;
}

void	animate_end(mlx_t *mlx, t_end *end)
{
	struct timeval	time;
	int				i;
	long			now;

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

static void	load_png(mlx_t *mlx, mlx_image_t **arr, int pos, char *name)
{
	mlx_texture_t	*txt;

	txt = mlx_load_png(name);
	arr[pos] = mlx_texture_to_image(mlx, txt);
	mlx_delete_texture(txt);
	mlx_image_to_window(mlx, arr[pos], 0, 0);
}

static void	init_textures(t_game *game)
{
	char	*score;
	char	*tmp;

	load_png(game->mlx, game->end->back, 0, "./sprites/end/back.png");
	load_png(game->mlx, game->end->back, 1, "./sprites/end/back1.png");
	load_png(game->mlx, game->end->back, 2, "./sprites/end/back2.png");
	load_png(game->mlx, game->end->back, 3, "./sprites/end/back3.png");
	load_png(game->mlx, game->end->back, 4, "./sprites/end/back4.png");
	load_png(game->mlx, game->end->back, 5, "./sprites/end/back5.png");
	load_png(game->mlx, game->end->back, 6, "./sprites/end/back6.png");
	load_png(game->mlx, game->end->back, 7, "./sprites/end/back7.png");
	load_png(game->mlx, game->end->cat, 0, "./sprites/end/cat/cat_sitting.png");
	load_png(game->mlx, game->end->cat, 1, "./sprites/end/cat/cat_sitting1.png");
	load_png(game->mlx, game->end->cat, 2, "./sprites/end/cat/cat_sitting2.png");
	load_png(game->mlx, game->end->cat, 3, "./sprites/end/cat/cat_sitting3.png");
	load_png(game->mlx, game->end->cat, 4, "./sprites/end/cat/cat_sitting4.png");
	load_png(game->mlx, game->end->cat, 5, "./sprites/end/cat/cat_sitting5.png");
	load_png(game->mlx, game->end->cat, 6, "./sprites/end/cat/cat_sitting6.png");
	load_png(game->mlx, game->end->cat, 7, "./sprites/end/cat/cat_sitting7.png");
	load_png(game->mlx, game->end->cat, 8, "./sprites/end/cat/cat_sitting8.png");
	load_png(game->mlx, game->end->cat, 9, "./sprites/end/cat/cat_sitting9.png");
	load_png(game->mlx, game->end->cat, 10, "./sprites/end/cat/cat_sitting10.png");
	load_png(game->mlx, game->end->cat, 11, "./sprites/end/cat/cat_sitting11.png");
	load_png(game->mlx, game->end->cat, 12, "./sprites/end/cat/cat_sitting12.png");
	load_png(game->mlx, game->end->cat, 13, "./sprites/end/cat/cat_sitting13.png");
	load_png(game->mlx, game->end->cat, 14, "./sprites/end/cat/cat_sitting14.png");
	load_png(game->mlx, game->end->cat, 15, "./sprites/end/cat/cat_sitting15.png");
	load_png(game->mlx, game->end->cat, 16, "./sprites/end/cat/cat_sitting16.png");
	load_png(game->mlx, game->end->cat, 17, "./sprites/end/cat/cat_sitting17.png");
	load_png(game->mlx, game->end->cat, 18, "./sprites/end/cat/cat_sitting18.png");
	load_png(game->mlx, game->end->cat, 19, "./sprites/end/cat/cat_sitting19.png");
	load_png(game->mlx, game->end->cat, 20, "./sprites/end/cat/cat_sitting20.png");
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
	game->end->cat_frame = 0;
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
