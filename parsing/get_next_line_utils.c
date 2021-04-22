/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyie <lyie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 15:58:00 by lyie              #+#    #+#             */
/*   Updated: 2021/04/21 13:53:57 by lyie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"
#include "../includes/structs.h"

static char	*ft_createstring(char const *s1, char const *s2,
		char **cat, int store)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	while (s1[++i] != '\0')
		(*cat)[i] = s1[i];
	while (++j < store)
		(*cat)[i + j] = s2[j];
	(*cat)[i + j] = '\0';
	free((void *)s1);
	return (*cat);
}

char		*ft_strjoin(char const *s1, char const *s2, int store)
{
	char	*cat;
	int		size;

	if (s1 == NULL)
	{
		cat = malloc(sizeof(char) * store + 1);
		if (!cat)
			return (NULL);
		size = 0;
		while (size < store)
		{
			cat[size] = s2[size];
			size++;
		}
		cat[size] = '\0';
		return (cat);
	}
	size = (ft_strlen(((char *)s1))) + store;
	cat = malloc(sizeof(char) * size + 1);
	if (!cat)
		return (NULL);
	return (ft_createstring(s1, s2, &cat, store));
	free((void *)s1);
	return (cat);
}

char		*ft_substr(char const *s, unsigned int start, int len)
{
	char	*finalstr;
	int		i;

	if (!(s))
		return (NULL);
	if ((int)start >= ft_strlen((char *)s))
		len = 0;
	else if (ft_strlen((char *)&s[start]) < len)
		len = ft_strlen((char *)&s[start]);
	finalstr = malloc(sizeof(char) * len + 1);
	if (!finalstr)
		return (NULL);
	i = 0;
	while (i < len && (s[start + i] != '\0'))
	{
		finalstr[i] = s[start + i];
		i++;
	}
	free((void *)s);
	finalstr[i] = '\0';
	return (finalstr);
}
