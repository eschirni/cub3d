/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_direction.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschirni <eschirni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 23:43:04 by eschirni          #+#    #+#             */
/*   Updated: 2022/06/21 19:36:52 by eschirni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_dir(t_game *game, int n, float pi)
{
	if (n != 0)
		return ;
	game->chars[n]->ray = malloc(sizeof(t_ray));
	game->chars[n]->pa = pi;
	calc_rotate(game, 0.0f, n);
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
