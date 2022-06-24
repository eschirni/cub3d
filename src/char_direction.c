/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_direction.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btenzlin <btenzlin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 23:43:04 by eschirni          #+#    #+#             */
/*   Updated: 2022/06/24 13:53:14 by btenzlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_dir(t_game *game, int n, float pi)
{
	if (n != 0)
		return ;
	game->chars[n]->ray = malloc(sizeof(t_ray));
	game->chars[n]->pa = pi;
	calc_rotate(game, game->map, 0.0f, n);
}

void	set_direction(t_game *game, char direction, int n)
{
	if (direction == 'N')
		init_dir(game, n, (float)M_PI_2 + (float)M_PI);
	else if (direction == 'E')
		init_dir(game, n, (float)M_PI * 2);
	else if (direction == 'S')
		init_dir(game, n, (float)M_PI_2);
	else if (direction == 'W')
		init_dir(game, n, (float)M_PI);
}
