/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyie <lyie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 15:52:16 by lyie              #+#    #+#             */
/*   Updated: 2021/04/20 14:07:38 by lyie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stddef.h>
# include "cub3d.h"

char	*ft_mapjoin(char *s1, char *s2, int store);
int		get_next_line(int fd, char **line);
char	*ft_strjoin(char const *s1, char const *s2, int store);
char	*ft_substr(char const *s, unsigned int start, int len);
void	*ft_memmove(void *dst, const void *src, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memccpy(void *dest, const void *src, int c, size_t n);
int		ft_strlen(char *str);
char	*ft_strdup(char *str);
int		get_next_line(int fd, char **line);
int		ft_strchr(char *s, char c);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
#endif
