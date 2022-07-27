#include "../includes/main_menu.h"

static uint32_t	*get_color(mlx_texture_t *texture)
{
	int				i;
	unsigned int	pos;
	uint8_t			rgb[4];
	uint32_t		*colors;

	i = 0;
	colors = malloc(sizeof(uint32_t) * (texture->width + 1) * (texture->height + 1));
	if (colors == NULL)
		ft_error("Allocation error!\n", NULL);
	pos = 0;
	while (pos < texture->width * texture->height * texture->bytes_per_pixel)
	{
		rgb[0] = texture->pixels[pos];
		rgb[1] = texture->pixels[pos + 1];
		rgb[2] = texture->pixels[pos + 2];
		rgb[3] = texture->pixels[pos + 3];
		colors[i] = (rgb[0] << 24) + (rgb[1] << 16) + (rgb[2] << 8) + rgb[3];
		pos += texture->bytes_per_pixel;
		i++;
	}
	return (colors);
}

static void	init_luci(t_game *game, mlx_texture_t *txt)
{
	txt = mlx_load_png("./sprites/luci/luci1.png");
	game->textures->luci[1] = get_color(txt);
	mlx_delete_texture(txt);
	txt = mlx_load_png("./sprites/luci/luci2.png");
	game->textures->luci[2] = get_color(txt);
	mlx_delete_texture(txt);
	txt = mlx_load_png("./sprites/luci/luci3.png");
	game->textures->luci[3] = get_color(txt);
	mlx_delete_texture(txt);
	txt = mlx_load_png("./sprites/luci/luci4.png");
	game->textures->luci[4] = get_color(txt);
	mlx_delete_texture(txt);
	txt = mlx_load_png("./sprites/luci/luci5.png");
	game->textures->luci[5] = get_color(txt);
	mlx_delete_texture(txt);
	txt = mlx_load_png("./sprites/luci/luci6.png");
	game->textures->luci[6] = get_color(txt);
	mlx_delete_texture(txt);
	txt = mlx_load_png("./sprites/luci/luci7.png");
	game->textures->luci[7] = get_color(txt);
	mlx_delete_texture(txt);
}

static void	init_extras(t_game *game, mlx_texture_t *txt)
{
	txt = mlx_load_png("./sprites/door_dirty64.png");
	game->textures->door = get_color(txt);
	mlx_delete_texture(txt);
	txt = mlx_load_png("./sprites/door_opened64.png");
	game->textures->door_o = get_color(txt);
	mlx_delete_texture(txt);
	txt = mlx_load_png("./sprites/exit64.png");
	game->textures->exit = get_color(txt);
	mlx_delete_texture(txt);
	txt = mlx_load_png("./sprites/chest_3d.png");
	game->textures->chest = get_color(txt);
	game->textures->chest_size[0] = txt->width;
	game->textures->chest_size[1] = txt->height;
	mlx_delete_texture(txt);
	txt = mlx_load_png("./sprites/luci/luci.png");
	game->textures->luci[0] = get_color(txt);
	game->textures->luci_size[0] = txt->width;
	game->textures->luci_size[1] = txt->height;
	mlx_delete_texture(txt);
	init_luci(game, txt);
}

void	init_textures(t_game *game)
{
	mlx_texture_t	*txt;

	game->textures = malloc(sizeof(t_textures));
	txt = mlx_load_png("./sprites/wall64.png");
	game->textures->wall = get_color(txt);
	game->textures->wall_size[0] = txt->width;
	game->textures->wall_size[1] = txt->height;
	mlx_delete_texture(txt);
	txt = mlx_load_png("./sprites/floor.png");
	game->textures->floor = get_color(txt);
	mlx_delete_texture(txt);
	init_extras(game, txt);
	game->textures->luci_frame = 0;
}
