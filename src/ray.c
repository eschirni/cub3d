#include "cub3d.h"

static void	add_until_wall(t_ray *ray, t_map *map, float ray_offset[2])
{
	while (true)
	{
		if ((int)ray->end[0] / 32 < 0 || (int)ray->end[1] / 32 < 0
			|| (int)ray->end[0] / 32 >= map->x || (int)ray->end[1] / 32 >= map->y
			|| map->map_arr[(int)ray->end[1] / 32][(int)ray->end[0] / 32] == '1')
			break ;
		ray->end[0] += ray_offset[0];
		ray->end[1] += ray_offset[1];
	}
}

static float	calc_horizontal(t_ray *ray, t_map *map, float pa, int x, int y)
{
	float	tan_v;
	float	ray_offset[2];

	tan_v = -1 / tan(pa);
	if (pa < (float)M_PI && pa > 0) //looking down
	{
		ray->end[1] = y / 32 * 32 + 32;
		ray->end[0] = (y - ray->end[1]) * tan_v + x;
		ray_offset[1] = 32;
	}
	else if (pa > (float)M_PI && pa != (float)M_PI * 2) //looking up
	{
		ray->end[1] = y / 32 * 32 - 0.0001f;
		ray->end[0] = (y - ray->end[1]) * tan_v + x;
		ray_offset[1] = -32;
	}
	if (pa == 0 || pa == (float)M_PI)
	{
		ray->end[0] = x;
		ray->end[1] = y;
		return (MAXFLOAT);
	}
	ray_offset[0] = -ray_offset[1] * tan_v;
	add_until_wall(ray, map, ray_offset);
	return (sqrtf(powf((ray->end[0] - x), 2) + powf((ray->end[1] - y), 2)));
}

static float	calc_vertical(t_ray *ray, t_map *map, float pa, int x, int y)
{
	float	tan_v;
	float	ray_offset[2];

	tan_v = -tan(pa);
	if (pa > (float)M_PI_2 && pa < (3 * (float)M_PI_2)) //looking left
	{
		ray->end[0] = x / 32 * 32 - 0.0001f;
		ray_offset[0] = -32;
	}
	else if (pa < (float)M_PI_2 || pa > (3 * (float)M_PI_2)) //looking right
	{
		ray->end[0] = x / 32 * 32 + 32;
		ray_offset[0] = 32;
	}
	ray->end[1] = (x - ray->end[0]) * tan_v + y;
	if (pa == (float)M_PI_2 || pa == (3 * (float)M_PI_2))
	{
		ray->end[0] = x;
		ray->end[1] = y;
		return (MAXFLOAT);
	}
	ray_offset[1] = -ray_offset[0] * tan_v;
	add_until_wall(ray, map, ray_offset);
	return (sqrtf(powf((ray->end[0] - x), 2) + powf((ray->end[1] - y), 2)));
}

float	calc_rays(t_ray *ray, t_map *map, float pa, int x, int y)
{
	float	dist_h;
	float	dist_v;
	int		end_h[2];
	int		dof;

	ray->start[0] = x;
	ray->start[1] = y;
	dof = 20;
	dist_h = calc_horizontal(ray, map, pa, x, y);
	end_h[0] = ray->end[0];
	end_h[1] = ray->end[1];
	ray->color = 0xbad129;
	dist_v = calc_vertical(ray, map, pa, x, y);
	if (dist_h < dist_v)
	{
		ray->end[0] = end_h[0];
		ray->end[1] = end_h[1];
		ray->color = 0x9caf1f;
		return (dist_h);
	}
	return (dist_v);
}