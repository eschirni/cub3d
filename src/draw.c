#include "cub3d.h"

static void	draw(t_ray *ray, int direction, float steps[2], mlx_image_t	*img)
{
	int		i;
	float	coords[2];

	i = 0;
	coords[0] = ray->start[0];
	coords[1] = ray->start[1];
	mlx_put_pixel(img, ray->start[0], ray->start[1], 0xFFFFFFFF);
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
		mlx_put_pixel(img, coords[0], coords[1], 0xFFFFFFFF);
	}
}

mlx_image_t	*draw_line(t_game *game, t_ray *ray)
{
	int			direction;
	float		steps[2];
	mlx_image_t	*img;

	direction = abs(ray->end[0] - ray->start[0]);
	if (abs(ray->end[0] - ray->start[0]) < abs(ray->end[1] - ray->start[1]))
		direction = abs(ray->end[1] - ray->start[1]);
	steps[0] = abs(ray->end[0] - ray->start[0]) / (float)direction;
	steps[1] = abs(ray->end[1] - ray->start[1]) / (float)direction;
	img = mlx_new_image(game->mlx, game->mlx->width, game->mlx->height);
	draw(ray, direction, steps, img);
	mlx_image_to_window(game->mlx, img, 0, 0);
	return (img);
}
