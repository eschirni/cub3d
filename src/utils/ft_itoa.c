/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschirni <eschirni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 21:25:30 by eschirni          #+#    #+#             */
/*   Updated: 2022/07/19 19:45:50 by eschirni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	ft_get_size(long *ln)
{
	int	size;
	int	i;

	size = 1;
	i = *ln;
	while (i / 10 != 0)
	{
		size++;
		i /= 10;
	}
	if (*ln < 0)
	{
		*ln *= -1;
		size++;
	}
	return (size);
}

char	*ft_itoa(int n)
{
	char	*c;
	int		size;
	int		i;
	long	ln;

	ln = n;
	size = ft_get_size(&ln);
	c = malloc(size + 1);
	if (c == NULL)
		return (NULL);
	c[size] = '\0';
	c[0] = '-';
	if (n == 0)
		c[0] = '0';
	i = 1;
	while (i < size + 1 && ln != 0)
	{
		c[size - i] = (ln % 10) + '0';
		ln /= 10;
		i++;
	}
	return (c);
}
