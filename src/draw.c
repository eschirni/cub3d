#include "cub3d.h"

static void	draw(t_ray *ray, int direction, float steps[2], mlx_image_t *img, int color)
{
	int		i;
	float	coords[2];

	i = 0;
	coords[0] = ray->start[0];
	coords[1] = ray->start[1];
	mlx_put_pixel(img, ray->start[0], ray->start[1], color);
	while (i < direction)
	{
		if (ray->start[0] <= ray->end[0])
			coords[0] += steps[0];
		else
			coords[0] -= steps[0];
		if (ray->start[1] <= ray->end[1])
			coords[1] += steps[1]; 
		else
			coords[1] -= steps[1];
		i++;
		mlx_put_pixel(img, coords[0], coords[1], color);
	}
}

void	draw_cross(mlx_t *mlx, int color)
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
		if (angle >= (float)M_PI_4 - (float)M_PI / 180 * 20 && angle <= (float)M_PI_4 + (float)M_PI / 180 * 20)
			continue ;
		else if (angle >= (float)M_PI_4 * 3 - (float)M_PI / 180 * 20 && angle <= (float)M_PI_4 * 3 + (float)M_PI / 180 * 20)
			continue ;
		else if (angle >= (float)M_PI_4 * 5 - (float)M_PI / 180 * 20 && angle <= (float)M_PI_4 * 5 + (float)M_PI / 180 * 20)
			continue ;
		else if (angle >= (float)M_PI_4 * 7 - (float)M_PI / 180 * 20 && angle <= (float)M_PI_4 * 7 + (float)M_PI / 180 * 20)
			continue ;
		x = 15 + 15 * cos(angle);
		y = 15 + 15 * sin(angle);
		mlx_put_pixel(img, x, y, color);
		x = 15 + 9 * cos(angle);
		y = 15 + 9 * sin(angle);
		mlx_put_pixel(img, x, y, color); 
	}
	x = 0;
	y = 0;
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
	mlx_image_to_window(mlx, img, WIDTH / 2 - 15, HEIGHT / 2 - 15); //free img
}

void	draw_line(t_ray *ray, mlx_image_t *img, int color) //idk if only allowing ray here makes sense
{
	int			direction;
	float		steps[2];

	direction = fabs(ray->end[0] - ray->start[0]);
	if (fabs(ray->end[0] - ray->start[0]) < fabs(ray->end[1] - ray->start[1]))
		direction = fabs(ray->end[1] - ray->start[1]);
	steps[0] = fabs(ray->end[0] - ray->start[0]) / (float)direction;
	steps[1] = fabs(ray->end[1] - ray->start[1]) / (float)direction;
	draw(ray, direction, steps, img, color);
}
