#include "../includes/cub3d.h"

static void	calc_draw(t_game *game, float sp_x, float sp_y)
{
	float	screen_pos[3];
	float	tmp[2];

	// printf("%f, %f\n", sp_x, sp_y);
	screen_pos[0] = sp_x - game->map->player[0];
	screen_pos[1] = sp_y - game->map->player[1];
	screen_pos[2] = HEIGHT / 2;
	// printf("%f\n", game->chars[0]->pa);
	tmp[0] = screen_pos[1] * -cos(game->chars[0]->pa) + screen_pos[0] * sin(game->chars[0]->pa);
	tmp[1] = screen_pos[0] * cos(game->chars[0]->pa) + screen_pos[1] * sin(game->chars[0]->pa);
	screen_pos[0] = tmp[0];
	screen_pos[1] = tmp[1];
	screen_pos[0] = (screen_pos[0] * -2000 / screen_pos[1]) + (WIDTH / 2);
	screen_pos[1] = (screen_pos[2] * 30 / screen_pos[1]) + (HEIGHT / 2);
	// printf("%f, %f\n", game->map->player[0], game->map->player[1]);
	int	size[2];
	size[0] = game->textures->chuci_size[0] * 50 / tmp[1];
	size[1] = game->textures->chuci_size[1] * 50 / tmp[1];
	if (size[0] < 0)
		size[0] = 0;
	if (size[1] < 0)
		size[1] = 0;
	int		x = 0;//screen_pos[0] - size[0] / 2;
	int		y = 0;
	float	t_x = game->textures->chuci_size[0];
	float	t_y = game->textures->chuci_size[1];
	float	x_off = game->textures->chuci_size[0] / (float)size[0];
	float	y_off = game->textures->chuci_size[1] / (float)size[1];
	while (x < size[0])
	{
		t_y = game->textures->chuci_size[1];
		y = 0;
		while (y <size[1])
		{
			if (screen_pos[0] - x < WIDTH && screen_pos[1] - y < HEIGHT && screen_pos[0] - x > 1 && screen_pos[1] - y > 1 && game->map->big_map[(int)sp_y / 32][(int)sp_x / 32] != 'l')
			{
				int	col = game->textures->chuci[(int)t_y * game->textures->chuci_size[0] - (int)t_x];
				// printf("%x\n", col);
				if (col != 0x282c3c00 && col != 0x27243100 && col != 0x282c3c00 && col != 0x433d4900 && col != 0x2b2b2b00 && col != (int)0xe6ece000 && col != (int)0x433d4900 && col && tmp[1] < game->rays[(int)screen_pos[0] - (int)x])
					mlx_put_pixel(game->game_img, screen_pos[0] - x, screen_pos[1] - y, col);
			}
			y++;
			t_y -= y_off;
		}
		t_x -= x_off;
		x++;
	}
	// printf("%d, %d\n", x, y);
}

void	draw_sprite(t_game *game, float sp_x, float sp_y, char c)
{
	if (c == 'c')
	{
		game->textures->chuci = game->textures->chest;
		game->textures->chuci_size[0] = game->textures->chest_size[0];
		game->textures->chuci_size[1] = game->textures->chest_size[1];
	}
	else
	{
		game->textures->chuci = game->textures->luci;
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
