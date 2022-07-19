/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   torch.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschirni <eschirni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 20:17:30 by eschirni          #+#    #+#             */
/*   Updated: 2022/07/19 22:01:07 by eschirni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	draw_torch(t_game *game)
{
	mlx_texture_t	*txt;

	if (game->torch_frame == 0)
		txt = mlx_load_png("./sprites/torch/torch.png");
	else if (game->torch_frame == 1)
		txt = mlx_load_png("./sprites/torch/torch1.png");
	else if (game->torch_frame == 2)
		txt = mlx_load_png("./sprites/torch/torch2.png");
	else if (game->torch_frame == 3)
		txt = mlx_load_png("./sprites/torch/torch3.png");
	else if (game->torch_frame == 4)
		txt = mlx_load_png("./sprites/torch/torch4.png");
	else
		txt = mlx_load_png("./sprites/torch/torch5.png");
	if (game->torch != NULL)
		mlx_delete_image(game->mlx, game->torch);
	game->torch = mlx_texture_to_image(game->mlx, txt);
	mlx_delete_texture(txt);
	mlx_image_to_window(game->mlx, game->torch, 0, 450);
	game->torch->instances[0].z = 100;
	game->torch_frame++;
	if (game->torch_frame > 5)
		game->torch_frame = 0;
}
