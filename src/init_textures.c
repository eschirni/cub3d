/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschirni <eschirni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 10:06:31 by eschirni          #+#    #+#             */
/*   Updated: 2022/07/28 10:09:13 by eschirni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

static uint32_t	*get_color(mlx_texture_t *texture)
{
	int				i;
	unsigned int	pos;
	uint8_t			rgb[4];
	uint32_t		*c;

	i = 0;
	c = malloc(sizeof(uint32_t) * (texture->width + 1) * (texture->height + 1));
	if (c == NULL)
		ft_error("Allocation error!\n", NULL);
	pos = 0;
	while (pos < texture->width * texture->height * texture->bytes_per_pixel)
	{
		rgb[0] = texture->pixels[pos];
		rgb[1] = texture->pixels[pos + 1];
		rgb[2] = texture->pixels[pos + 2];
		rgb[3] = texture->pixels[pos + 3];
		c[i] = (rgb[0] << 24) + (rgb[1] << 16) + (rgb[2] << 8) + rgb[3];
		pos += texture->bytes_per_pixel;
		i++;
	}
	return (c);
}

void	init_textures(t_game *game)
{
	mlx_texture_t	*txt;

	game->textures = malloc(sizeof(t_textures));
	txt = mlx_load_png("./sprites/tile_wall64.png");
	game->textures->wall = get_color(txt);
	game->textures->wall_size[0] = txt->width;
	game->textures->wall_size[1] = txt->height;
	mlx_delete_texture(txt);
}