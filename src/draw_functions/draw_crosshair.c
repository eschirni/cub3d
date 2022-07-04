#include "../includes/cub3d.h"

static bool	check_angle(float angle)
{
	float	c_space;
	float	pi_4;

	c_space = (float)M_PI / 180 * 20;
	pi_4 = (float)M_PI_4;
	if (angle >= pi_4 - c_space && angle <= pi_4 + c_space)
		return (false);
	else if (angle >= pi_4 * 3 - c_space && angle <= pi_4 * 3 + c_space)
		return (false);
	else if (angle >= pi_4 * 5 - c_space && angle <= pi_4 * 5 + c_space)
		return (false);
	else if (angle >= pi_4 * 7 - c_space && angle <= pi_4 * 7 + c_space)
		return (false);
	return (true);
}

static void	draw_circles(t_game *game, int color)
{
	int			x;
	int			y;
	float		angle;

	angle = (float)M_PI / 180 * -1;
	while (angle <= (float)M_PI * 2)
	{
		angle += (float)M_PI / 180;
		if (check_angle(angle) == false)
			continue ;
		x = WIDTH / 2 + 15 * cos(angle);
		y = HEIGHT / 2 + 15 * sin(angle);
		mlx_put_pixel(game->game_img, x, y, color);
		x = WIDTH / 2 + 9 * cos(angle);
		y = HEIGHT / 2 + 9 * sin(angle);
		mlx_put_pixel(game->game_img, x, y, color);
	}
}

static void	draw_star(t_game *game, int color)
{
	int			x;
	int			y;
	float		angle;

	angle = (float)M_PI / 180 * -1;
	while (angle <= (float)M_PI * 2)
	{
		angle += (float)M_PI / 180;
		x = WIDTH / 2 + 1 * roundf(cos(angle));
		y = HEIGHT / 2 + 1 * roundf(sin(angle));
		mlx_put_pixel(game->game_img, x, y, color);
		x = WIDTH / 2 + 2 * roundf(cos(angle));
		y = HEIGHT / 2 + 2 * roundf(sin(angle));
		mlx_put_pixel(game->game_img, x, y, color);
		x = WIDTH / 2 + 3 * roundf(cos(angle));
		y = HEIGHT / 2 + 3 * roundf(sin(angle));
		mlx_put_pixel(game->game_img, x, y, color);
	}
}

static void	draw_dot(t_game *game, int color)
{
	int			x;
	int			y;
	float		angle;

	angle = (float)M_PI / 180 * -1;
	mlx_put_pixel(game->game_img, WIDTH / 2, HEIGHT / 2, color);
	while (angle <= (float)M_PI * 2)
	{
		angle += (float)M_PI / 180;
		x = WIDTH / 2 + roundf(3 * cos(angle));
		y = HEIGHT / 2 + roundf(3 * sin(angle));
		mlx_put_pixel(game->game_img, x, y, color);
		x = WIDTH / 2 + roundf(2 * cos(angle));
		y = HEIGHT / 2 + roundf(2 * sin(angle));
		mlx_put_pixel(game->game_img, x, y, color);
		x = WIDTH / 2 + roundf(cos(angle));
		y = HEIGHT / 2 + roundf(sin(angle));
		mlx_put_pixel(game->game_img, x, y, color);
	}
}

void	draw_crosshair(t_game *game, int color, char type)
{
	if (type == 'C')
		draw_circles(game, color);
	else if (type == 'D')
		draw_dot(game, color);
	else
		draw_star(game, color);
}
