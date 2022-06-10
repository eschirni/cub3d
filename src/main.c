/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btenzlin <btenzlin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 12:05:26 by btenzlin          #+#    #+#             */
/*   Updated: 2022/06/10 18:08:17 by btenzlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_error(char *msg, char *arg)
{
	int	i;

	write(2, "error: ", 7);
	i = 0;
	while (*msg)
		write(2, msg++, 1);
	if (arg)
		while (*arg)
			write(2, arg++, 1);
	write(2, "\n", 1);
	exit(EXIT_FAILURE);
}

static void	free_2d_array(char **arr)
{
	int	i;

	if (arr)
	{
		i = 0;
		while (arr[i])
		{
			free(arr[i]);
			i++;
		}
		free(arr);
	}
}

static void	hook(mlx_key_data_t keydata, void *data) //add vertical movement
{
	t_data	*tmp;

	tmp = data;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_RELEASE)
		mlx_close_window(tmp->mlx);
	if (mlx_is_key_down(tmp->mlx, MLX_KEY_W))
		tmp->img->instances[0].y -= 5;
	if (mlx_is_key_down(tmp->mlx, MLX_KEY_S))
		tmp->img->instances[0].y += 5;
	if (mlx_is_key_down(tmp->mlx, MLX_KEY_A))
		tmp->img->instances[0].x -= 5;
	if (mlx_is_key_down(tmp->mlx, MLX_KEY_D))
		tmp->img->instances[0].x += 5;
}

int	main(int argc, char **argv)
{
	t_data	*data;
	t_map	*map;
	// mlx_texture_t	*zomb;

	if (argc != 2)
		ft_error("bad arguments", NULL);
	map = init_map(argv[1]);
	data = malloc(sizeof(t_data *));
	data->mlx = mlx_init(map->x * TILE_WIDTH, map->y * TILE_HEIGHT, "CUB3D", true);
	if (!data->mlx)
		exit(EXIT_FAILURE);
	data->img = mlx_new_image(data->mlx, 128, 128);    // Creates a new image.
	// zomb = mlx_load_png("/sprites/zombie.png");
	// mlx_texture_to_image(data->mlx, zomb);
	mlx_image_to_window(data->mlx, data->img, 0, 0);   // Adds an image to the render queue.
	mlx_put_pixel(data->img, 64, 64, 0x4287f5ff); // Single white pixel in the middle.
	mlx_key_hook(data->mlx, &hook, data);
	mlx_loop(data->mlx);
	mlx_delete_image(data->mlx, data->img); // Once the application request an exit, cleanup.
	mlx_terminate(data->mlx);
	free_2d_array(map->map_arr);
	return (EXIT_SUCCESS);
}
