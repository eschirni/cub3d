/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btenzlin <btenzlin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 21:57:53 by eschirni          #+#    #+#             */
/*   Updated: 2022/07/04 18:44:25 by btenzlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	ft_strncmp(const char *str1, const char *str2, size_t size)
{
	unsigned char	*s1;
	unsigned char	*s2;

	s1 = (unsigned char *)str1;
	s2 = (unsigned char *)str2;
	while (*s1 == ' ')
		s1++;
	while (size > 0 && (*s1 != '\0' || *s2 != '\0'))
	{
		if (*s1 == *s2)
		{
			s1++;
			s2++;
			size--;
		}
		else
		{
			return (*s1 - *s2);
		}
	}
	return (0);
}

int	ft_strlen(char *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

bool	is_char_obj(char c)
{
	if (c == 'N' || c == 'E' || c == 'S' || c == 'W')
		return (true);
	return (false);
}

int	check_file(char *file)
{
	char	*tmp;

	tmp = file;
	tmp += ft_strlen(file) - 4;
	if (ft_strncmp(tmp, ".cub", 5))
		return (0);
	return (1);
}

void	free_2d_array(char **arr)
{
	int	i;

	if (arr)
	{
		i = 0;
		while (arr[i])
		{
			free(arr[i]);
			i++;
		}
		free(arr);
	}
}
