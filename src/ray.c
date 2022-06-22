#include "cub3d.h"

static float	calc_horizontal(t_ray *ray, float pa, int x, int y)
{
	if (pa < M_PI && pa > 0)
	{
		ray->end[1] = y / 32 * 32 + 32;
		ray->end[0] = (y - ray->end[1]) * (-1 / tan(pa)) + x;
	}
	else if (pa > M_PI)
	{
		ray->end[1] = y / 32 * 32;
		ray->end[0] = (y - ray->end[1]) * (-1 / tan(pa)) + x;
	}
	else
	{
		ray->end[0] = x;
		ray->end[1] = y;
	}
	return (sqrtf(powf((ray->end[0] - x), 2) + powf((ray->end[1] - y), 2)));
}

static float	calc_vertical(t_ray *ray, float pa, int x, int y)
{
	if (pa < M_PI_2 || pa > (M_PI_2 * 3))
	{
		ray->end[0] = x / 32 * 32 + 32;
		ray->end[1] = (x - ray->end[0]) * (-tan(pa)) + y; //-tan?
	}
	else if (pa > M_PI_2 && pa < (M_PI_2 * 3))
	{
		ray->end[0] = x / 32 * 32;
		ray->end[1] = (x - ray->end[0]) * (-tan(pa)) + y;
	}
	else
	{
		ray->end[0] = x;
		ray->end[1] = y;
	}
	return (sqrtf(powf((ray->end[0] - x), 2) + powf((ray->end[1] - y), 2)));
}

void	calc_rays(t_ray *ray, float pa, int x, int y)
{
	float	dist_h;
	float	dist_v;
	int		end_h[2];

	ray->start[0] = x;
	ray->start[1] = y;
	dist_h = calc_horizontal(ray, pa, x, y);
	end_h[0] = ray->end[0];
	end_h[1] = ray->end[1];
	dist_v = calc_vertical(ray, pa, x, y);
	if (dist_h < dist_v)
	{
		ray->end[0] = end_h[0];
		ray->end[1] = end_h[1];
	}
}
