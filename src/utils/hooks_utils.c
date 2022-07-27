#include "../includes/cub3d.h"

static void	get_move(t_game *game, t_char *chr)
{
	chr->w[0] = roundf(cos(chr->pa) * game->ps);
	chr->w[1] = roundf(sin(chr->pa) * game->ps);
	chr->s[0] = chr->w[0] * -1;
	chr->s[1] = chr->w[1] * -1;
	chr->d[0] = roundf(cos(chr->pa + (float)M_PI_2) * game->ps);
	chr->d[1] = roundf(sin(chr->pa + (float)M_PI_2) * game->ps);
	chr->a[0] = chr->d[0] * -1;
	chr->a[1] = chr->d[1] * -1;
}

void	calc_rotate(t_game *game, float rotation, int n)
{
	float		x;
	float		y;

	x = game->map->player[0];
	y = game->map->player[1];
	game->chars[n]->pa += rotation;
	if (game->chars[n]->pa < 0)
		game->chars[n]->pa += (float)M_PI * 2;
	else if (game->chars[n]->pa >= (float)M_PI * 2)
		game->chars[n]->pa -= (float)M_PI * 2;
	get_move(game, game->chars[n]);
}
