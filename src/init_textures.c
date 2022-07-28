/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschirni <eschirni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 10:06:31 by eschirni          #+#    #+#             */
/*   Updated: 2022/07/28 15:17:30 by eschirni         ###   ########.fr       */
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

static uint32_t	*mirror_texture(uint32_t *texture, int size[2])
{
	int			i;
	int			j;
	int			count;
	uint32_t	*mir;

	mir = malloc(sizeof(uint32_t) * (size[0] + 1) * (size[1] + 1));
	if (!mir)	
		ft_error("failed to allocate memory", NULL);
	i = 0;
	j = size[0] - 1;
	count = 0;
	while (i < size[0] * size[1])
	{
		mir[i] = texture[j + (size[0] * count)];
		i++;
		j--;
		if (j < 0)
		{
			j = size[0] - 1;
			count++;
		}
	}
	free(texture);
	return (mir);
}

void	init_textures(t_game *game)
{
	mlx_texture_t	*txt;

	game->textures = malloc(sizeof(t_textures));
	txt = mlx_load_png(game->map->no_tex);
	if (txt == NULL || txt->height != 32 || txt->width != 32)
		ft_error("non accepted texture", NULL);
	game->textures->north = get_color(txt);
	game->textures->north_size[0] = txt->width;
	game->textures->north_size[1] = txt->height;
	mlx_delete_texture(txt);
	txt = mlx_load_png(game->map->ea_tex);
	if (txt == NULL || txt->height != 32 || txt->width != 32)
		ft_error("non accepted texture", NULL);
	game->textures->east = get_color(txt);
	game->textures->east_size[0] = txt->width;
	game->textures->east_size[1] = txt->height;
	mlx_delete_texture(txt);
	txt = mlx_load_png(game->map->so_tex);
	if (txt == NULL || txt->height != 32 || txt->width != 32)
		ft_error("non accepted texture", NULL);
	game->textures->south = get_color(txt);
	game->textures->south_size[0] = txt->width;
	game->textures->south_size[1] = txt->height;
	game->textures->south = mirror_texture(game->textures->south, game->textures->south_size);
	mlx_delete_texture(txt);
	txt = mlx_load_png(game->map->we_tex);
	if (txt == NULL || txt->height != 32 || txt->width != 32)
		ft_error("non accepted texture", NULL);
	game->textures->west = get_color(txt);
	game->textures->west_size[0] = txt->width;
	game->textures->west_size[1] = txt->height;
	game->textures->west = mirror_texture(game->textures->west, game->textures->west_size);
	mlx_delete_texture(txt);
}
