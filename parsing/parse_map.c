/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 17:12:26 by user42            #+#    #+#             */
/*   Updated: 2021/03/10 11:02:23 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int			ft_maplen(char *line)
{
	int	start;
	int	end;
	int	size;

	if (!line)
		return (0);
	size = ft_strlen(line);
	start = 0;
	end = size - 1;
	while (line[start] == ' ')
		start++;
	if (start == size)
		return (0);
	while (line[end] == ' ' && end > start)
		end--;
	size = end - start;
	if (size < 0)
		return (0);
	return (size);
}

int			ft_rowcounter(char *buffer)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (buffer[i])
	{
		if (buffer[i] == '-')
			count++;
		i++;
	}
	return (count);
}

static char	*ft_createmap(char *s1, char *s2, char **cat, int store)
{
	int		i;
	int		j;
	char	*valids;

	valids = "012SNWE";
	i = -1;
	j = -1;
	while (s1[++i] != '\0' && s1 != NULL)
		(*cat)[i] = s1[i];
	while (++j < store - 1 && s2 != NULL)
	{
		while (s2[j] == ' ')
			j++;
		if (s2[j] == '-')
			(*cat)[i] = '*';
		else
			(*cat)[i] = s2[j];
		i++;
	}
	(*cat)[i] = '-';
	(*cat)[i + 1] = '\0';
	return (*cat);
}

char		*ft_mapjoin(char *s1, char *s2, int store)
{
	char	*cat;
	int		size;

	if (!s1)
	{
		cat = malloc((sizeof(char)) * (store + 2));
		if (!cat)
		{
			free(s2);
			return (NULL);
		}
		free(s1);
		ft_strlcpy(cat, s2, store + 2);
		return (cat);
	}
	size = (ft_strlen((char *)s1)) + store;
	cat = malloc((sizeof(char)) * (size + 2));
	if (!cat)
	{
		free(s2);
		return (NULL);
	}
	cat = ft_createmap(s1, s2, &cat, store);
	free(s1);
	return (cat);
}
