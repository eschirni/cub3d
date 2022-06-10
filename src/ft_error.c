/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschirni <eschirni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 20:06:03 by eschirni          #+#    #+#             */
/*   Updated: 2022/06/10 20:24:25 by eschirni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_error(char *msg, char *arg)
{
	write(2, RED, 5);
	write(2, "error: ", 7);
	while (*msg)
		write(2, msg++, 1);
	if (arg)
		while (*arg)
			write(2, arg++, 1);
	write(2, "\n", 1);
	write(2, RESET, 4);
	exit(EXIT_FAILURE);
}
