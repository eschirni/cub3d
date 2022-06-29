#include "cub3d.h"

static void	loop(void *tmp)
{
	t_menu	*menu;
	int		i;

	menu = tmp;
	i = 0;
	usleep(150000);
	while (i < 6)
	{
		menu->imgs[i]->enabled = false;
		i++;
	}
	menu->imgs[menu->i]->enabled = true;
	menu->i++;
	if (menu->i > 5)
		menu->i = 0;
}

void	main_menu(mlx_t	*mlx)
{
	int				i;
	int				pid;
	mlx_texture_t	*txt;
	t_menu			*menu;

	menu = malloc(sizeof(t_menu));
	menu->mlx = mlx;
	txt = mlx_load_png("./sprites/background.png");
	menu->imgs[0] = mlx_texture_to_image(mlx, txt);
	txt = mlx_load_png("./sprites/background1.png");
	menu->imgs[1] = mlx_texture_to_image(mlx, txt);
	txt = mlx_load_png("./sprites/background2.png");
	menu->imgs[2] = mlx_texture_to_image(mlx, txt);
	txt = mlx_load_png("./sprites/background3.png");
	menu->imgs[3] = mlx_texture_to_image(mlx, txt);
	txt = mlx_load_png("./sprites/background4.png");
	menu->imgs[4] = mlx_texture_to_image(mlx, txt);
	txt = mlx_load_png("./sprites/background5.png");
	menu->imgs[5] = mlx_texture_to_image(mlx, txt);
	i = 0;
	while (i < 6)
	{
		mlx_image_to_window(mlx, menu->imgs[i], 0, 0);
		menu->imgs[i]->enabled = false;
		i++;
	}
	menu->i = 0;
	mlx_loop_hook(menu->mlx, &loop, menu);
	mlx_loop(menu->mlx);
}
