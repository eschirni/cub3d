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

// void	draw_sprite(t_game *game)
// {
	// float	s_pos[2];
	// float	s_vec[2];
	// float	screen_pos[2];
	// float	angle_x;
	// float	fov_left;

	// s_pos[0] = 48;
	// s_pos[1] = 48;
	// s_vec[0] = s_pos[0] - game->map->player[0];
	// s_vec[1] = s_pos[1] - game->map->player[1];
	// angle_x = atan2f(-s_vec[1], s_vec[0]);
	// if (angle_x < 0)
	// 	angle_x += (float)M_PI * 2;
	// else if (angle_x >= (float)M_PI * 2)
	// 	angle_x -= (float)M_PI * 2;
	// fov_left = game->chars[0]->pa + (game->menu->settings->graphics / 2) - angle_x;
	// if ((game->chars[0]->pa >= 0 && game->chars[0]->pa < ((float)M_PI * 2)) && fov_left >= (2 * (float)M_PI / 3))
	// 	fov_left += (float)M_PI * 2;
	// else if ((fov_left >= 0 && fov_left < ((float)M_PI * 2)) && game->chars[0]->pa >= (2 * (float)M_PI / 3))
	// 	fov_left -= (float)M_PI * 2;
	// screen_pos[0] = fov_left * (WIDTH / game->menu->settings->graphics);
	// screen_pos[1] = HEIGHT / 2;
	// // printf("%f, %f\n", screen_pos[0], screen_pos[1]);
	// int	i = 0;
	// int	j = 0;
	// while (i < 100)
	// {
	// 	j = 0;
	// 	while (j < 100)
	// 	{
	// 		if (screen_pos[0] - i < WIDTH && screen_pos[1] - j < HEIGHT && screen_pos[0] - i > 1 && screen_pos[1] - j > 1)
	// 			mlx_put_pixel(game->game_img, screen_pos[0] - i, screen_pos[1] - j, 0xFF0000FF);
	// 		j++;
	// 	}
	// 	i++;
	// }
// 	game->loot = game->loot;
// 	return ;
// }


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

// static int	get_color(t_game *game, u_int32_t *col, float dy)
// {
// 	float	angle;
// 	float	dyangle;
// 	int		tx;
// 	int		ty;

// 	angle = cos(game->chars[0]->pa);
// 	dyangle = 540 * 32 / dy / angle;
// 	tx = game->map->player[0] + cos(game->chars[0]->pa) * dyangle;
// 	ty = game->map->player[1] + sin(game->chars[0]->pa) * dyangle;
// 	return (col[(ty & 31) * 32 + (tx & 31)]);
// }

// void	draw_sprite(t_game *game)
// {
// 	float	screen_pos[3];
// 	float	sp_pos[3];
// 	float	tmp[2];

// 	sp_pos[0] = 96 + 16;
// 	sp_pos[1] = 96 + 16;
// 	sp_pos[2] = HEIGHT / 4;
// 	screen_pos[0] = sp_pos[0] - game->map->player[0];
// 	screen_pos[1] = sp_pos[1] - game->map->player[1];
// 	screen_pos[2] = sp_pos[2];
// 	// printf("%f\n", game->chars[0]->pa);
// 	tmp[0] = screen_pos[1] * -cos(game->chars[0]->pa) + screen_pos[0] * sin(game->chars[0]->pa);
// 	tmp[1] = screen_pos[0] * cos(game->chars[0]->pa) + screen_pos[1] * sin(game->chars[0]->pa);
// 	screen_pos[0] = tmp[0];
// 	screen_pos[1] = tmp[1];
// 	screen_pos[0] = (screen_pos[0] * -WIDTH / screen_pos[1]) + (WIDTH / 2);
// 	screen_pos[1] = (screen_pos[2] * 60 / screen_pos[1]) + (HEIGHT / 2);
// 	// printf("%f, %f\n", game->map->player[0], game->map->player[1]);
// 	int	size[2];
// 	size[0] = game->textures->luci_size[0] * 100 / tmp[1];
// 	size[1] = game->textures->luci_size[1] * 100 / tmp[1];
// 	int		x = screen_pos[0] - size[0] / 2;;
// 	int		y = 0;
// 	float	t_x = 0;
// 	float	t_y = 0;
// 	float	x_off = game->textures->luci_size[0] / (float)size[0];
// 	float	y_off = game->textures->luci_size[1] / (float)size[1];
// 	while (x < screen_pos[0] + size[0] / 2)
// 	{
// 		t_y = 0;
// 		y = 0;
// 		while (y <size[1])
// 		{
// 			if (screen_pos[0] + x < WIDTH && screen_pos[1] + y < HEIGHT && screen_pos[0] + x > 1 && screen_pos[1] + y > HEIGHT / 2 && tmp[1] < game->rays[(int)screen_pos[0] + (int)x])
// 			{
// 				int	col = game->textures->luci[(int)t_y * game->textures->luci_size[0] + (int)t_x];
// 				mlx_put_pixel(game->game_img, screen_pos[0] + (int)x, screen_pos[1] + (int)y, col);
// 			}
// 			y++;
// 			t_y += y_off;
// 		}
// 		t_x += x_off;
// 		x++;
// 	} 
// }

void	draw_sprite(t_game *game)
{
	float	screen_pos[3];
	float	sp_pos[3];
	float	tmp[2];
	int		size;

	sp_pos[0] = 96 + 16;
	sp_pos[1] = 96 + 16;
	sp_pos[2] = HEIGHT / 4;
	screen_pos[0] = sp_pos[0] - game->map->player[0];
	screen_pos[1] = sp_pos[1] - game->map->player[1];
	screen_pos[2] = sp_pos[2];
	// printf("%f\n", game->chars[0]->pa);
	tmp[0] = screen_pos[1] * -cos(game->chars[0]->pa) + screen_pos[0] * sin(game->chars[0]->pa);
	tmp[1] = screen_pos[0] * cos(game->chars[0]->pa) + screen_pos[1] * sin(game->chars[0]->pa);
	screen_pos[0] = tmp[0];
	screen_pos[1] = tmp[1];
	screen_pos[0] = (screen_pos[0] * -WIDTH / screen_pos[1]) + (WIDTH / 2);
	screen_pos[1] = (screen_pos[2] * 60 / screen_pos[1]) + (HEIGHT / 2);
	size = 64 * 120 / tmp[1];
	int	i = 0;
	int	j = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (screen_pos[0] - i < WIDTH && screen_pos[1] - j < HEIGHT && screen_pos[0] - i > 1 && screen_pos[1] - j > HEIGHT / 2 && tmp[1] < game->rays[(int)screen_pos[0] - i])
				mlx_put_pixel(game->game_img, screen_pos[0] - i, screen_pos[1] - j, 0xFF0000FF);
			j++;
		}
		i++;
	}
}

// void	draw_sprite(t_game *game)
// {
// 	float	dx;
// 	float	dy;
// 	float	dist;
// 	float	sprite_angle;
// 	float	screen_pos[2];
// 	int		size;

// 	dx = 48 - game->map->player[0];
// 	dy = 48 - game->map->player[1];
// 	dist = sqrtf(dx * dx + dy * dy);
// 	sprite_angle = atan2f(dy, dx) - game->chars[0]->pa;
// 	size = dist / cos(sprite_angle);
// 	screen_pos[0] = tanf(sprite_angle) * dist - size;
// 	screen_pos[1] = HEIGHT / 2 - size;
// 	// printf("%f, %d\n", screen_pos[0], screen_pos[1]);
// 	int	i = 0;
// 	int	j = 0;
// 	while (i < size)
// 	{
// 		j = 0;
// 		while (j < size)
// 		{
// 			if (screen_pos[0] - i < WIDTH && screen_pos[1] - j < HEIGHT && screen_pos[0] - i > 1 && screen_pos[1] - j > 1)
// 				mlx_put_pixel(game->game_img, screen_pos[0] - i, screen_pos[1] - j, 0xFF0000FF);
// 			j++;
// 		}
// 		i++;
// 	} 
// 	game->loot = game->loot;
// }

// void	draw_sprite(t_game *game)
// {
// 	float	sprite_vector[2];
// 	float	screen_pos[2];
// 	float	sprite_angle;

// 	sprite_vector[0] = 48 - game->map->player[0];
// 	sprite_vector[1] = 48 - game->map->player[1];
// 	sprite_angle = atan2f(sprite_vector[1], sprite_vector[0]);
// 	if (sprite_angle < 0)
// 		sprite_angle = (float)M_PI * 2;
// 	screen_pos[1] = game->chars[0]->pa + (game->menu->settings->graphics / 2) - sprite_angle;
// 	if (sprite_angle > ((float)M_PI * 3 / 2) && game->chars[0]->pa < ((float)M_PI / 2))
// 		screen_pos[1] += (float)M_PI * 2;
// 	else if (game->chars[0]->pa > ((float)M_PI * 3 / 2) && sprite_angle < ((float)M_PI / 2))
// 		screen_pos[1] -= (float)M_PI * 2;
// 	screen_pos[0] = screen_pos[1] * WIDTH / game->menu->settings->graphics;
// 	// printf("%f, %f\n", screen_pos[0], screen_pos[1]);
// 	screen_pos[1] = HEIGHT / 2;
// 	int	i = 0;
// 	int	j = 0;
// 	while (i < 100)
// 	{
// 		j = 0;
// 		while (j < 100)
// 		{
// 			if (screen_pos[0] - i < WIDTH && screen_pos[1] - j < HEIGHT && screen_pos[0] - i > 1 && screen_pos[1] - j > 1)
// 				mlx_put_pixel(game->game_img, screen_pos[0] - i, screen_pos[1] - j, 0xFF0000FF);
// 			j++;
// 		}
// 		i++;
// 	} 
// 	game->loot = game->loot;
// }

// void	draw_sprite(t_game *game)
// {
// 	float	delta[2];
// 	float	dist;
// 	float	screen_pos[2];
// 	float	sp_angle;

// 	delta[0] = 48 - game->map->player[0];
// 	delta[1] = 48 - game->map->player[1];
// 	dist = sqrtf(delta[0] * delta[0] + delta[1] * delta[1]);
// 	sp_angle = atan2f(delta[1], delta[0]) - game->chars[0]->pa;
// 	if (sp_angle < 0)
// 		sp_angle += (float)M_PI * 2;
// 	printf("pa: %f, sp: %f\n", game->chars[0]->pa, sp_angle);
// 	screen_pos[0] = WIDTH / 2 + sp_angle * cos(sp_angle);// - dist * sin(sp_angle);
// 	screen_pos[1] = HEIGHT - dist * 4.23f;
// 	if (screen_pos[1] < HEIGHT / 2+ 160)
// 		screen_pos[1] = HEIGHT / 2 + 160;
// 	// printf("%f, %f\n", screen_pos[0], screen_pos[1]);
// 	int	i = 0;
// 	int	j = 0;
// 	while (i < 100)
// 	{
// 		j = 0;
// 		while (j < 100)
// 		{
// 			if (screen_pos[0] - i < WIDTH && screen_pos[1] - j < HEIGHT && screen_pos[0] - i > 1 && screen_pos[1] - j > 1)
// 				mlx_put_pixel(game->game_img, screen_pos[0] - i, screen_pos[1] - j, 0xFF0000FF);
// 			j++;
// 		}
// 		i++;
// 	} 
// 	game->loot = game->loot;
// }
