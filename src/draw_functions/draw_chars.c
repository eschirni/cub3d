/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_chars.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschirni <eschirni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 10:42:53 by eschirni          #+#    #+#             */
/*   Updated: 2022/07/28 10:42:55 by eschirni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	draw_char(mlx_t *mlx, t_char *c, int n)
{
	mlx_texture_t	*player;

	if (n != 0)
		player = mlx_load_png("./sprites/luci/luci_map.png");
	else
		player = mlx_load_png("./sprites/player.png");
	if (player == NULL)
		ft_error("can't load image", NULL);
	c->img = mlx_texture_to_image(mlx, player);
	if (c->img == NULL)
		ft_error("char image allocation failed", NULL);
	mlx_delete_texture(player);
	mlx_image_to_window(mlx, c->img, c->x, c->y);
}

void	draw_chars(t_game *game, char **map)
{
	int	i;
	int	j;
	int	chrs;

	i = 0;
	chrs = game->map->n_chars - 1;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (is_char_obj(map[i][j]))
			{
				draw_char(game->mlx, game->chars[chrs], chrs);
				set_direction(game, map[i][j], chrs);
				chrs--;
			}
			j++;
		}
		i++;
	}
}
