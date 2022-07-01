#include "../includes/cub3d.h"

static void	draw(t_ray *ray, int direction, mlx_image_t *img, int color)
{
	int		i;
	float	coords[2];
	float	steps[2];

	i = 0;
	coords[0] = ray->start[0];
	coords[1] = ray->start[1];
	steps[0] = fabs(ray->end[0] - ray->start[0]) / (float)direction;
	steps[1] = fabs(ray->end[1] - ray->start[1]) / (float)direction;
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

void	draw_line(t_ray *ray, mlx_image_t *img, int color) //idk if only allowing ray here makes sense
{
	int	direction;

	direction = fabs(ray->end[0] - ray->start[0]);
	if (fabs(ray->end[0] - ray->start[0]) < fabs(ray->end[1] - ray->start[1]))
		direction = fabs(ray->end[1] - ray->start[1]);
	draw(ray, direction, img, color);
}
