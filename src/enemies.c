#include "includes/cub3d.h"

static void	calc_pos(t_game *game, t_char *chr) //either check if there is already an enemie to avoid fusion or randomize movement
{
	int	x;
	int	y;
	static bool	spotted;

	if (chr->img->instances[0].y >= 0 && chr->img->instances[0].y < MINIMAP && chr->img->instances[0].x >= 0 && chr->img->instances[0].x < MINIMAP && game->ray_tiles[chr->img->instances[0].y + 8][chr->img->instances[0].x + 8] == true)
	{
		if (spotted == false && game->sounds->sound == true)
			system("afplay ./music/spotted.mp3 &");
		draw_sprite(game, game->map->enemy[0], game->map->enemy[1], 'l');
		spotted = true;
		return ;
	}
	x = game->chars[0]->img->instances[0].x - chr->img->instances[0].x;
	y = game->chars[0]->img->instances[0].y - chr->img->instances[0].y;
	if ((game->chars[0]->img->instances[0].y <= chr->img->instances[0].y + 8 && game->chars[0]->img->instances[0].y >= chr->img->instances[0].y - 8) && (game->chars[0]->img->instances[0].x <= chr->img->instances[0].x + 8 && game->chars[0]->img->instances[0].x >= chr->img->instances[0].x - 8))
	{
		game->loot = -0.42f;
		end_game(game);
		return ;
	}
	if (x < 0)
	{
		chr->img->instances[0].x -= 1 + (int)(game->loot / 8);
		game->map->enemy[0] -= 1 + (int)(game->loot / 8);;
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
