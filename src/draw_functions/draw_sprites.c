#include "../includes/cub3d.h"

static int	check_s_pos(float s_pos[2], int x, int y)
{
	if (s_pos[0] - x < WIDTH && s_pos[1] - y < HEIGHT
		&& s_pos[0] - x > 1 && s_pos[1] - y > 1)
		return (1);
	return (0);
}

static void	draw_tex_pixel(t_game *game, t_sprite_vars *sp, int sp_x, int sp_y)
{
	int			col;
	int			t_size;
	u_int32_t	*tex;
	mlx_image_t	*img;

	tex = game->textures->chuci;
	t_size = game->textures->chuci_size[0];
	img = game->game_img;
	if (check_s_pos(sp->s_pos, sp->x, sp->y)
		&& game->map->big_map[(int)sp_y / 32][(int)sp_x / 32] != 'l')
	{
		col = tex[(int)sp->t_pos[1] * t_size - (int)sp->t_pos[0]]; //overflow (-fsanitize=address)
		if (col != 0x433d4900 && col
			&& sp->tmp[1] < game->rays[(int)sp->s_pos[0] - sp->x])
			mlx_put_pixel(img, sp->s_pos[0] - sp->x, sp->s_pos[1] - sp->y, col);
	}
}

static void	draw_pixels(t_game *game, int sp_x, int sp_y, t_sprite_vars *sp)
{
	sp->t_pos[0] = game->textures->chuci_size[0];
	sp->offset[0] = game->textures->chuci_size[0] / (float)sp->size[0];
	sp->offset[1] = game->textures->chuci_size[1] / (float)sp->size[1];
	sp->x = 0;
	while (sp->x < sp->size[0])
	{
		sp->t_pos[1] = game->textures->chuci_size[1];
		sp->y = 0;
		while (sp->y < sp->size[1] && ((int)sp->t_pos[1]
				* game->textures->chuci_size[0] - (int)sp->t_pos[0]) >= 0)
		{
			draw_tex_pixel(game, sp, sp_x, sp_y);
			sp->y++;
			sp->t_pos[1] -= sp->offset[1];
		}
		sp->t_pos[0] -= sp->offset[0];
		sp->x++;
	}
}

static void	calc_draw(t_game *game, float sp_x, float sp_y)
{
	t_sprite_vars	*sp;
	float			pa;

	sp = malloc(sizeof(t_sprite_vars));
	sp->s_pos[0] = sp_x - game->map->player[0];
	sp->s_pos[1] = sp_y - game->map->player[1];
	sp->s_pos[2] = HEIGHT / 2;
	pa = game->chars[0]->pa;
	sp->tmp[0] = sp->s_pos[1] * -cos(pa) + sp->s_pos[0] * sin(pa);
	sp->tmp[1] = sp->s_pos[0] * cos(pa) + sp->s_pos[1] * sin(pa);
	sp->s_pos[0] = sp->tmp[0];
	sp->s_pos[1] = sp->tmp[1];
	sp->s_pos[0] = (sp->s_pos[0] * -2000 / sp->s_pos[1]) + (WIDTH / 2);
	sp->s_pos[1] = (sp->s_pos[2] * 30 / sp->s_pos[1]) + (HEIGHT / 2);
	sp->size[0] = game->textures->chuci_size[0] * 50 / sp->tmp[1];
	sp->size[1] = game->textures->chuci_size[1] * 50 / sp->tmp[1];
	if (sp->size[0] < 0)
		sp->size[0] = 0;
	if (sp->size[1] < 0)
		sp->size[1] = 0;
	draw_pixels(game, sp_x, sp_y, sp);
}

void	draw_sprite(t_game *game, float sp_x, float sp_y, char c) //segfault in here (lldb for reference)
{
	game->textures->chuci = game->textures->luci[game->textures->luci_frame];
	game->textures->chuci_size[0] = game->textures->luci_size[0];
	game->textures->chuci_size[1] = game->textures->luci_size[1];
	if (c == 'c')
	{
		game->textures->chuci = game->textures->chest;
		game->textures->chuci_size[0] = game->textures->chest_size[0];
		game->textures->chuci_size[1] = game->textures->chest_size[1];
	}
	calc_draw(game, sp_x, sp_y);
}
