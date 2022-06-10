/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btenzlin <btenzlin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 12:05:26 by btenzlin          #+#    #+#             */
/*   Updated: 2022/06/10 15:09:28 by btenzlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//TO COMPILE:
//gcc main.c MLX42/libmlx42.a -lglfw -L /Users/btenzlin/.brew/Cellar/glfw/3.3.7/lib

void	hook(mlx_key_data_t keydata, void *data) //add vertical movement
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

int32_t	main(void)
{
	t_data	*data;

	data = malloc(sizeof(t_data *));
	data->mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true);
	if (!data->mlx)
		exit(EXIT_FAILURE);
	data->img = mlx_new_image(data->mlx, 128, 128);    // Creates a new image.
	mlx_image_to_window(data->mlx, data->img, 0, 0);   // Adds an image to the render queue.
	mlx_put_pixel(data->img, 64, 64, 0x4287f5ff); // Single white pixel in the middle.
	mlx_key_hook(data->mlx, &hook, data);
	mlx_loop(data->mlx);
	mlx_delete_image(data->mlx, data->img); // Once the application request an exit, cleanup.
	mlx_terminate(data->mlx);
	return (EXIT_SUCCESS);
}
