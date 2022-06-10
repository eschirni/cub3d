/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschirni <eschirni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 16:54:07 by eschirni          #+#    #+#             */
/*   Updated: 2021/09/06 21:26:36 by eschirni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(size_t size)
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

size_t	ft_strclen(const char *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] != c)
		i++;
	return (i);
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

char	*ft_strchr(const char *s, int c)
{
	int	i;

	if (s == NULL)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			return ((char *)&s[i]);
		i++;
	}
	if (c == '\0')
		return ((char *)&s[i]);
	else
		return (NULL);
}
