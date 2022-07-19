/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcdup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschirni <eschirni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 19:57:50 by eschirni          #+#    #+#             */
/*   Updated: 2022/07/19 20:00:51 by eschirni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	*ft_calloc(size_t size)
{
	char	*c;

	c = malloc(size + 1);
	if (c == NULL)
		return (NULL);
	while (size + 1 != 0)
	{
		c[size] = '\0';
		size--;
	}
	return (c);
}

char	*ft_strcdup(char *s1, char c, size_t start)
{
	char	*s2;
	size_t	tmp;
	int		i;

	tmp = start;
	if (s1 == NULL)
		return (NULL);
	while (s1[start] != c)
		start++;
	if (s1[start] == '\0')
		start--;
	s2 = ft_calloc(start - tmp + 1);
	if (s2 == NULL)
		return (NULL);
	i = start - tmp;
	while (start + 1 != tmp)
	{
		s2[i] = s1[start];
		start--;
		i--;
	}
	return (s2);
}
