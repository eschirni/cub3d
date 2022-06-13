/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_direction.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschirni <eschirni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 23:43:04 by eschirni          #+#    #+#             */
/*   Updated: 2022/06/13 23:45:08 by eschirni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void init_north(t_game *game, int n)
{
	game->chars[n]->w[0] = 0;
	game->chars[n]->w[1] = -5;
	game->chars[n]->a[0] = -5;
	game->chars[n]->a[1] = 0;
	game->chars[n]->s[0] = 0;
	game->chars[n]->s[1] = 5;
	game->chars[n]->d[0] = 5;
	game->chars[n]->d[1] = 0;
}

static void init_east(t_game *game, int n)
{
	game->chars[n]->w[0] = 5;
	game->chars[n]->w[1] = 0;
	game->chars[n]->a[0] = 0;
	game->chars[n]->a[1] = -5;
	game->chars[n]->s[0] = -5;
	game->chars[n]->s[1] = 0;
	game->chars[n]->d[0] = 0;
	game->chars[n]->d[1] = 5;
}

static void init_south(t_game *game, int n)
{
	game->chars[n]->w[0] = 0;
	game->chars[n]->w[1] = 5;
	game->chars[n]->a[0] = 5;
	game->chars[n]->a[1] = 0;
	game->chars[n]->s[0] = 0;
	game->chars[n]->s[1] = -5;
	game->chars[n]->d[0] = -5;
	game->chars[n]->d[1] = 0;
}

static void init_west(t_game *game, int n)
{
	game->chars[n]->w[0] = -5;
	game->chars[n]->w[1] = 0;
	game->chars[n]->a[0] = 0;
	game->chars[n]->a[1] = 5;
	game->chars[n]->s[0] = 5;
	game->chars[n]->s[1] = 0;
	game->chars[n]->d[0] = 0;
	game->chars[n]->d[1] = -5;
}

void	set_direction(t_game *game, char direction, int n)
{
	if (direction == 'N')
		init_north(game, n);
	else if (direction == 'E')
		init_east(game, n);
	else if (direction == 'S')
		init_south(game, n);
	else if (direction == 'W')
		init_west(game, n);
}
