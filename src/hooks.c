#include "cub3d.h"

static void	draw_rays(t_ray *ray, t_game *game, int x, int y)
{
	float	ra;
	float	dist;
	float	line_height;
	float	line_width;
	float	angle_distance;
	int		i;
	int		count_x;
	int		line_x;

	ra = game->chars[0]->pa - 30 * ((float)M_PI / 180);
	if (ra < 0)
		ra += (float)M_PI * 2;
	ray->img = mlx_new_image(game->mlx, game->mlx->width, game->mlx->height);
	if (game->game_img)
		mlx_delete_image(game->mlx, game->game_img);
	game->game_img = mlx_new_image(game->mlx, WIDTH, HEIGHT);
	i = 0;
	line_x = 0;
	while (i < 60)
	{
		ra += (float)M_PI / 180;
		if (ra >= (float)M_PI * 2)
			ra -= (float)M_PI * 2;
		dist = calc_rays(ray, game->map, ra, x, y);
		draw_line(game, ray, ray->img, 0xbad129); //draw ray

		angle_distance = game->chars[0]->pa - ra;
		if (angle_distance < 0)
			angle_distance += (float)M_PI * 2;
		else if (angle_distance >= (float) M_PI * 2)
			angle_distance -= (float)M_PI * 2;
		dist *= cos(angle_distance);
		line_height = 32 * HEIGHT / dist;
		if (line_height > HEIGHT)
			line_height = HEIGHT;
		line_width = WIDTH / 60;
		count_x = 0;
		while (count_x < line_width)
		{
			ray->start[0] = line_x;
			ray->start[1] = HEIGHT / 2 - line_height / 2;
			ray->end[0] = line_x;
			ray->end[1] = ray->start[1] + line_height;
			draw_line(game, ray, game->game_img, ray->color);
			line_x++;
			count_x++;
		}
		i++;
	}
	mlx_image_to_window(game->mlx, game->game_img, 0, 0);
	mlx_image_to_window(game->mlx, ray->img, 0, 0);
}

void	calc_rotate(t_game *game, t_map *map, float rotation, int n)
{
	int		x;
	int		y;

	x = game->chars[n]->img->instances[0].x;
	y = game->chars[n]->img->instances[0].y;
	mlx_delete_image(game->mlx, game->chars[n]->ray->img);
	game->chars[n]->pa += rotation;
	if (game->chars[n]->pa < 0)
		game->chars[n]->pa = (float)(M_PI * 2);
	else if (game->chars[n]->pa > (float)M_PI * 2)
		game->chars[n]->pa = 0.1f;
	game->chars[n]->w[0] = cos(game->chars[n]->pa) * 5; //make w to float (idea)
	game->chars[n]->w[1] = sin(game->chars[n]->pa) * 5;
	game->chars[n]->s[0] = game->chars[n]->w[0] * -1;
	game->chars[n]->s[1] = game->chars[n]->w[1] * -1;
	game->chars[n]->d[0] = cos(game->chars[n]->pa + (float)M_PI_2) * 5;
	game->chars[n]->d[1] = sin(game->chars[n]->pa + (float)M_PI_2) * 5;
	game->chars[n]->a[0] = game->chars[n]->d[0] * -1;
	game->chars[n]->a[1] = game->chars[n]->d[1] * -1;
	draw_rays(game->chars[n]->ray, game, x + 8, y + 8);
}

static void	set_coords(t_game *game, int addX, int addY)
{
	game->chars[0]->img->instances[0].x += addX;
	game->chars[0]->img->instances[0].y += addY;
	calc_rotate(game, game->map, 0.0f, 0);
}

void	hook(void *tmp)
{
	t_game	*game;

	game = tmp;
	if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(game->mlx);
	if (mlx_is_key_down(game->mlx, MLX_KEY_W))
		set_coords(game, game->chars[0]->w[0], game->chars[0]->w[1]);
	if (mlx_is_key_down(game->mlx, MLX_KEY_A))
		set_coords(game, game->chars[0]->a[0], game->chars[0]->a[1]);
	if (mlx_is_key_down(game->mlx, MLX_KEY_S))
		set_coords(game, game->chars[0]->s[0], game->chars[0]->s[1]);
	if (mlx_is_key_down(game->mlx, MLX_KEY_D))
		set_coords(game, game->chars[0]->d[0], game->chars[0]->d[1]);
	if (mlx_is_key_down(game->mlx, MLX_KEY_LEFT))
		calc_rotate(game, game->map, -0.06f, 0);
	if (mlx_is_key_down(game->mlx, MLX_KEY_RIGHT))
		calc_rotate(game, game->map, 0.06f, 0);
}
