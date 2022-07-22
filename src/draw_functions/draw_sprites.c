#include "../includes/cub3d.h"

// void	draw_sprite(t_game *game)
// {
// 	float	sprite_x;
// 	float	sprite_y;

// 	sprite_x = game->map->chest->instances[0].x * 32 - game->map->player[0];
// 	sprite_y = game->map->chest->instances[0].y * 32 - game->map->player[1];
// 	// sprite_x = WIDTH / 2 + sprite_x - game->map->player[0] * cos(game->chars[0]->pa);
// 	// sprite_y = HEIGHT / 2 + sprite_y - game->map->player[1] * sin(game->chars[0]->pa);
// 	float a = sprite_y * cos(game->chars[0]->pa) + sprite_x * sin(game->chars[0]->pa);
// 	float b = sprite_x * cos(game->chars[0]->pa) - sprite_y * -sin(game->chars[0]->pa);
// 	sprite_x = a;
// 	sprite_y = b;
// 	sprite_x = sprite_x * 108.0f / sprite_y + WIDTH / 2;
// 	sprite_y = HEIGHT / 2;
// 	// printf("%f, %f\n", sprite_x, sprite_y);
// 	if (sprite_x < WIDTH && sprite_y < HEIGHT && sprite_x > 1 && sprite_y > 1)
// 	{
// 		mlx_put_pixel(game->game_img, sprite_x, sprite_y, 0xFF0000FF);
// 		mlx_put_pixel(game->game_img, sprite_x - 1, sprite_y - 1, 0xFF0000FF);
// 		mlx_put_pixel(game->game_img, sprite_x - 1, sprite_y, 0xFF0000FF);
// 		mlx_put_pixel(game->game_img, sprite_x, sprite_y + 1, 0xFF0000FF);
// 		mlx_put_pixel(game->game_img, sprite_x + 1, sprite_y + 1, 0xFF0000FF);
// 		mlx_put_pixel(game->game_img, sprite_x + 1, sprite_y, 0xFF0000FF);
// 		mlx_put_pixel(game->game_img, sprite_x, sprite_y + 1, 0xFF0000FF);
// 	}
// }

// void	draw_sprite(t_game *game)
// {
// 	float	sp[2];
// 	float	sp_dir;
// 	float	sp_dist;

// 	sp[0] = 128 - game->map->player[0];
// 	sp[1] = 128 - game->map->player[1];
// 	sp_dir = atan2f(sp[1], sp[0]);
// 	sp_dist = sqrtf(powf(sp[0], 2) + powf(sp[1], 2));
// 	if (sp_dir < (float)M_PI * -1)
// 		sp_dir += (float)M_PI * 2;
// 	else if (sp_dir >= (float)M_PI)
// 		sp_dir -= (float)M_PI * 2;
// 	float	pos = tanf(sp_dir) / tanf(game->chars[0]->pa / 2);
// 	int	x = WIDTH * pos;
// 	float	sprite_x = x;
// 	float	sprite_y = HEIGHT / 2;
// 	if (sprite_x < WIDTH && sprite_y < HEIGHT && sprite_x > 1 && sprite_y > 1)
// 	{
// 		mlx_put_pixel(game->game_img, sprite_x, sprite_y, 0xFF0000FF);
// 		mlx_put_pixel(game->game_img, sprite_x - 1, sprite_y - 1, 0xFF0000FF);
// 		mlx_put_pixel(game->game_img, sprite_x - 1, sprite_y, 0xFF0000FF);
// 		mlx_put_pixel(game->game_img, sprite_x, sprite_y + 1, 0xFF0000FF);
// 		mlx_put_pixel(game->game_img, sprite_x + 1, sprite_y + 1, 0xFF0000FF);
// 		mlx_put_pixel(game->game_img, sprite_x + 1, sprite_y, 0xFF0000FF);
// 		mlx_put_pixel(game->game_img, sprite_x, sprite_y + 1, 0xFF0000FF);
// 	}
// }

void	draw_sprite(t_game *game)
{
	float	s_pos[2];
	float	s_vec[2];
	float	screen_pos[2];
	float	angle_x;
	float	fov_left;

	s_pos[0] = 48;
	s_pos[1] = 48;
	s_vec[0] = s_pos[0] - game->map->player[0];
	s_vec[1] = s_pos[1] - game->map->player[1];
	angle_x = atan2f(-s_vec[1], s_vec[0]);
	if (angle_x < 0)
		angle_x += (float)M_PI * 2;
	else if (angle_x >= (float)M_PI * 2)
		angle_x -= (float)M_PI * 2;
	fov_left = game->chars[0]->pa + (game->menu->settings->graphics / 2) - angle_x;
	if ((game->chars[0]->pa >= 0 && game->chars[0]->pa < ((float)M_PI * 2)) && fov_left >= (2 * (float)M_PI / 3))
		fov_left += (float)M_PI * 2;
	else if ((fov_left >= 0 && fov_left < ((float)M_PI * 2)) && game->chars[0]->pa >= (2 * (float)M_PI / 3))
		fov_left -= (float)M_PI * 2;
	screen_pos[0] = fov_left * (WIDTH / game->menu->settings->graphics);
	screen_pos[1] = HEIGHT / 2;
	// printf("%f, %f\n", screen_pos[0], screen_pos[1]);
	int	i = 0;
	int	j = 0;
	while (i < 100)
	{
		j = 0;
		while (j < 100)
		{
			if (screen_pos[0] - i < WIDTH && screen_pos[1] - j < HEIGHT && screen_pos[0] - i > 1 && screen_pos[1] - j > 1)
				mlx_put_pixel(game->game_img, screen_pos[0] - i, screen_pos[1] - j, 0xFF0000FF);
			j++;
		}
		i++;
	} 
}


// void	draw_sprite(t_game *game)
// {
// 	float	s_pos[2];
// 	float	s_vec[2];
// 	float	screen_pos[2];
// 	int		angle_x;

// 	s_pos[0] = 32 + 16;
// 	s_pos[1] = 32 + 16;
// 	s_vec[0] = s_pos[0] - game->map->player[0];
// 	s_vec[1] = s_pos[1] - game->map->player[1];
// 	angle_x = (int)atan2f(s_vec[1], s_vec[0]);
// 	if (angle_x < 0)
// 		angle_x += (float)M_PI * 2;
// 	screen_pos[1] = game->chars[0]->pa + (game->menu->settings->graphics / 2) - angle_x;
// 	if (angle_x > ((float)M_PI * 2 / 3) && game->chars[0]->pa < (float)(M_PI / 2))
// 		screen_pos[1] = game->chars[0]->pa + (game->menu->settings->graphics / 2) - angle_x + ((float)M_PI * 2);
// 	else if (game->chars[0]->pa > ((float)M_PI * 2 / 3) && angle_x < (float)(M_PI / 2))
// 		screen_pos[1] = game->chars[0]->pa + (game->menu->settings->graphics / 2) - angle_x - ((float)M_PI * 2);
// 	screen_pos[0] = screen_pos[1] * WIDTH / game->menu->settings->graphics;
// 	printf("%f, %f\n", screen_pos[0], screen_pos[1]);
// 	int	i = 0;
// 	int	j = 0;
// 	while (i < 100)
// 	{
// 		j = 0;
// 		while (j < 100)
// 		{
// 			if (screen_pos[0] - i < WIDTH && screen_pos[1] - j < HEIGHT && screen_pos[0] - i > 1 && screen_pos[1] - j > 1)
// 				mlx_put_pixel(game->game_img, screen_pos[0] - i, HEIGHT / 2 - j, 0xFF0000FF);
// 			j++;
// 		}
// 		i++;
// 	} 
// }

// void	draw_sprite(t_game *game)
// {
// 	float	screen_pos[3];
// 	float	sp_pos[3];

// 	sp_pos[0] = 32 + 16;
// 	sp_pos[1] = 32 + 16;
// 	sp_pos[2] = HEIGHT / 4;
// 	screen_pos[0] = sp_pos[0] - game->map->player[0];
// 	screen_pos[1] = sp_pos[1] - game->map->player[1];
// 	screen_pos[2] = sp_pos[2];
// 	printf("%f\n", game->chars[0]->pa);
// 	float	a = screen_pos[1] * cos(game->chars[0]->pa) + screen_pos[0] * sin(game->chars[0]->pa);
// 	float	b = screen_pos[0] * cos(game->chars[0]->pa) + screen_pos[1] * sin(game->chars[0]->pa);
// 	screen_pos[0] = a;
// 	screen_pos[1] = b;
// 	screen_pos[0] = (screen_pos[0] / screen_pos[1]) + (WIDTH / 2);
// 	screen_pos[1] = (screen_pos[2] * 60 / screen_pos[1]) + (HEIGHT / 2);
// 	// printf("%f, %f\n", game->map->player[0], game->map->player[1]);
// 	int	i = 0;
// 	int	j = 0;
// 	while (i < 100)
// 	{
// 		j = 0;
// 		while (j < 100)
// 		{
// 			if (screen_pos[0] - i < WIDTH && screen_pos[1] - j < HEIGHT && screen_pos[0] - i > 1 && screen_pos[1] - j > 1 && b < game->rays[(int)screen_pos[0] - i])
// 				mlx_put_pixel(game->game_img, screen_pos[0] - i, screen_pos[1] - j, 0xFF0000FF);
// 			j++;
// 		}
// 		i++;
// 	} 
// }

//x behaves like an asshole + block hiding behind wall calc is off (maybe because of out inefficient direction calculation)
