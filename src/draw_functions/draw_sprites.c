#include "../includes/cub3d.h"

static int	check_screen_pos(float screen_pos[2], int x, int y)
{
	if (screen_pos[0] - x < WIDTH && screen_pos[1] - y < HEIGHT
		&& screen_pos[0] - x > 1 && screen_pos[1] - y > 1)
		return (1);
	return (0);
}

static void	draw_pixels(t_game *game, int size[2], float screen_pos[3], float tmp[2], int sp_x, int sp_y)
{
	int		x;
	int		y;
	float	t_x;
	float	t_y;
	float	x_off;
	float	y_off;

	t_x = game->textures->chuci_size[0];
	t_y = game->textures->chuci_size[1];
	x_off = game->textures->chuci_size[0] / (float)size[0];
	y_off = game->textures->chuci_size[1] / (float)size[1];
	x = 0;
	while (x < size[0])
	{
		t_y = game->textures->chuci_size[1];
		y = 0;
		while (y <size[1] && ((int)t_y * game->textures->chuci_size[0] - (int)t_x) >= 0)
		{
			if (check_screen_pos(screen_pos, x, y) && game->map->big_map[(int)sp_y / 32][(int)sp_x / 32] != 'l')
			{
				int	col = game->textures->chuci[(int)t_y * game->textures->chuci_size[0] - (int)t_x]; //overflow (-fsanitize=address)
				if (col != 0x433d4900 && col && tmp[1] < game->rays[(int)screen_pos[0] - (int)x])
					mlx_put_pixel(game->game_img, screen_pos[0] - x, screen_pos[1] - y, col);
			}
			y++;
			t_y -= y_off;
		}
		t_x -= x_off;
		x++;
	}
}

static void	calc_draw(t_game *game, float sp_x, float sp_y)
{
	float	screen_pos[3];
	float	tmp[2];
	int	size[2];

	screen_pos[0] = sp_x - game->map->player[0];
	screen_pos[1] = sp_y - game->map->player[1];
	screen_pos[2] = HEIGHT / 2;
	tmp[0] = screen_pos[1] * -cos(game->chars[0]->pa) + screen_pos[0] * sin(game->chars[0]->pa);
	tmp[1] = screen_pos[0] * cos(game->chars[0]->pa) + screen_pos[1] * sin(game->chars[0]->pa);
	screen_pos[0] = tmp[0];
	screen_pos[1] = tmp[1];
	screen_pos[0] = (screen_pos[0] * -2000 / screen_pos[1]) + (WIDTH / 2);
	screen_pos[1] = (screen_pos[2] * 30 / screen_pos[1]) + (HEIGHT / 2);
	size[0] = game->textures->chuci_size[0] * 50 / tmp[1];
	size[1] = game->textures->chuci_size[1] * 50 / tmp[1];
	if (size[0] < 0)
		size[0] = 0;
	if (size[1] < 0)
		size[1] = 0;
	draw_pixels(game, size, screen_pos, tmp, sp_x, sp_y);
}

void	draw_sprite(t_game *game, float sp_x, float sp_y, char c) //segfault in here (lldb for reference)
{
	if (c == 'c')
	{
		game->textures->chuci = game->textures->chest;
		game->textures->chuci_size[0] = game->textures->chest_size[0];
		game->textures->chuci_size[1] = game->textures->chest_size[1];
	}
	else
	{
		game->textures->chuci = game->textures->luci[game->textures->luci_frame];
		game->textures->chuci_size[0] = game->textures->luci_size[0];
		game->textures->chuci_size[1] = game->textures->luci_size[1];
	}
	calc_draw(game, sp_x, sp_y);
}

// void	draw_sprite(t_game *game)
// {
// 	float	screen_pos[3];
// 	float	sp_pos[3];
// 	float	tmp[2];
// 	int		size;

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
// 	size = 64 * 120 / tmp[1];
// 	int	i = 0;
// 	int	j = 0;
// 	while (i < size)
// 	{
// 		j = 0;
// 		while (j < size)
// 		{
// 			if (screen_pos[0] - i < WIDTH && screen_pos[1] - j < HEIGHT && screen_pos[0] - i > 1 && screen_pos[1] - j > HEIGHT / 2 && tmp[1] < game->rays[(int)screen_pos[0] - i])
// 				mlx_put_pixel(game->game_img, screen_pos[0] - i, screen_pos[1] - j, 0xFF0000FF);
// 			j++;
// 		}
// 		i++;
// 	}
// }
