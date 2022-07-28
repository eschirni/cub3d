/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btenzlin <btenzlin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 20:38:36 by btenzlin          #+#    #+#             */
/*   Updated: 2022/07/28 21:03:09 by btenzlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	get_map_size(char **file, int start)
{
	int	i;
	int	count;

	i = start;
	count = 0;
	while (file[i])
	{
		i++;
		count++;
	}
	return (count);
}

int	get_x(char **file, int start)
{
	int	len;
	int	tmp;

	len = 0;
	while (file[start])
	{
		tmp = ft_strlen(file[start]);
		if (tmp > len)
			len = tmp;
		start++;
	}
	return (len);
}

void	check_line(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != ' ')
			ft_error("config syntax error", NULL);
		i++;
	}
}

int	is_map(char *line)
{
	int	i;
	int	tile;

	i = 0;
	tile = 0;
	while (line[i])
	{
		if (line[i] == '0' || line[i] == '1')
		{
			i++;
			tile++;
		}
		else if (line[i] == ' ')
			i++;
		else
			return (0);
	}
	if (tile == 0)
		return (0);
	return (1);
}

void	count_del(char *s)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if (s[i] == ',')
			count++;
		i++;
	}
	if (count != 2)
		ft_error("too much rgb delimiters", NULL);
}
