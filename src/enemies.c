#include "includes/cub3d.h"

static void	move_enemy(t_game *game, t_char *chr)
{
	int			x;
	int			y;

	x = game->chars[0]->img->instances[0].x - chr->img->instances[0].x;
	y = game->chars[0]->img->instances[0].y - chr->img->instances[0].y;
	if (x < 0)
	{
		chr->img->instances[0].x -= 1 + (int)(game->loot / 8);
		game->map->enemy[0] -= 1 + (int)(game->loot / 8);
	}
	else if (x != 0)
	{
		chr->img->instances[0].x += 1 + (int)(game->loot / 8);
		game->map->enemy[0] += 1 + (int)(game->loot / 8);
	}
	if (y < 0)
	{
		chr->img->instances[0].y -= 1 + (int)(game->loot / 8);
		game->map->enemy[1] -= 1 + (int)(game->loot / 8);
	}
	else if (y != 0)
	{
		chr->img->instances[0].y += 1 + (int)(game->loot / 8);
		game->map->enemy[1] += 1 + (int)(game->loot / 8);
	}
}

static int	got_killed(int32_t px, int32_t py, int32_t x, int32_t y)
{
	if ((py <= y + 8 && py >= y - 8) && (px <= x + 8 && px >= x - 8))
		return (1);
	return (0);
}

static void	calc_pos(t_game *game, t_char *chr)
{
	static bool	spotted;
	int32_t		x;
	int32_t		y;

	x = chr->img->instances[0].x;
	y = chr->img->instances[0].y;
	if (y + 8 >= 0 && y + 8 < MINIMAP && x >= 0
		&& x < MINIMAP && game->ray_tiles[y + 8][x + 8] == true)
	{
		if (spotted == false && game->sounds->sound == true)
			system("afplay ./music/spotted.mp3 &");
		draw_sprite(game, game->map->enemy[0], game->map->enemy[1], 'l');
		spotted = true;
		return ;
	}
	if (got_killed(game->chars[0]->img->instances[0].x,
			game->chars[0]->img->instances[0].y, x, y))
	{
		game->loot = -0.42f;
		end_game(game);
		return ;
	}
	move_enemy(game, chr);
	spotted = false;
}

void	move_enemies(t_game *game)
{
	int	i;

	i = 1;
	while (i < game->map->n_chars)
	{
		calc_pos(game, game->chars[i]);
		i++;
	}
}
