#include "includes/cub3d.h"

static void	calc_pos(t_game *game, t_char *chr) //either check if there is already an enemie to avoid fusion or randomize movement
{
	int	x;
	int	y;

	if (chr->img->instances[0].y >= 0 && chr->img->instances[0].y < MINIMAP && chr->img->instances[0].x >= 0 && chr->img->instances[0].x < MINIMAP && game->ray_tiles[chr->img->instances[0].y + 8][chr->img->instances[0].x + 8] == true)
		return ;
	x = game->chars[0]->img->instances[0].x - chr->img->instances[0].x;
	y = game->chars[0]->img->instances[0].y - chr->img->instances[0].y;
	if ((game->chars[0]->img->instances[0].y <= chr->img->instances[0].y + 8 && game->chars[0]->img->instances[0].y >= chr->img->instances[0].y - 8) && (game->chars[0]->img->instances[0].x <= chr->img->instances[0].x + 8 && game->chars[0]->img->instances[0].x >= chr->img->instances[0].x - 8))
	{
		game->loot = -0.42f;
		end_game(game);
		return ;
	}
	if (x < 0)
		chr->img->instances[0].x -= 1 + game->loot / 8;
	else if (x != 0)
		chr->img->instances[0].x += 1 + game->loot / 8;
	if (y < 0)
		chr->img->instances[0].y -= 1 + game->loot / 8;
	else if (y != 0)
		chr->img->instances[0].y += 1 + game->loot / 8;
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
