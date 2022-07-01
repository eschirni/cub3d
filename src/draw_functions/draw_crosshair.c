#include "../includes/cub3d.h"

static void	draw_cross(mlx_image_t *img, int color, int x, int y)
{
	while (x < 7)
	{
		mlx_put_pixel(img, x, 15, color);
		x++;
	}
	x = 24;
	while (x < 30)
	{
		mlx_put_pixel(img, x, 15, color);
		x++;
	}
	while (y < 7)
	{
		mlx_put_pixel(img, 15, y, color);
		y++;
	}
	y = 24;
	while (y < 30)
	{
		mlx_put_pixel(img, 15, y, color);
		y++;
	}
}

static int	check_angle(float angle)
{
	float	c_space;
	float	pi_4;

	c_space = (float)M_PI / 180 * 20;
	pi_4 = (float)M_PI_4;
	if (angle >= pi_4 - c_space && angle <= pi_4 + c_space)
		return (0);
	else if (angle >= pi_4 * 3 - c_space && angle <= pi_4 * 3 + c_space)
		return (0);
	else if (angle >= pi_4 * 5 - c_space && angle <= pi_4 * 5 + c_space)
		return (0);
	else if (angle >= pi_4 * 7 - c_space && angle <= pi_4 * 7 + c_space)
		return (0);
	return (1);
}

void	draw_crosshair(mlx_t *mlx, int color)
{
	int			x;
	int			y;
	float		angle;
	mlx_image_t	*img;

	angle = (float)M_PI / 180 * -1;
	img = mlx_new_image(mlx, 30, 30);
	while (angle <= (float)M_PI * 2)
	{
		angle += (float)M_PI / 180;
		if (!check_angle(angle))
			continue ;
		x = 15 + 15 * cos(angle);
		y = 15 + 15 * sin(angle);
		mlx_put_pixel(img, x, y, color);
		x = 15 + 9 * cos(angle);
		y = 15 + 9 * sin(angle);
		mlx_put_pixel(img, x, y, color);
	}
	draw_cross(img, color, 0, 0);
	mlx_image_to_window(mlx, img, WIDTH / 2 - 15, HEIGHT / 2 - 15); //free img
}
