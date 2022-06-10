/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschirni <eschirni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 15:56:52 by eschirni          #+#    #+#             */
/*   Updated: 2022/06/10 15:56:54 by eschirni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd);
void	*ft_calloc(size_t size);
size_t	ft_strclen(const char *s, char c);
char	*ft_strcdup(char *s1, char c, size_t start);
char	*ft_strchr(const char *s, int c);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

#endif