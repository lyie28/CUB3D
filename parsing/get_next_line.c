/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyie <lyie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 15:58:13 by lyie              #+#    #+#             */
/*   Updated: 2021/04/09 11:53:38 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"
#include "../includes/structs.h"

static int	ft_nline(char **line, char **chest, int i, int size)
{
	if (!((*line) = malloc(sizeof(char) * i + 1)))
		return (-1);
	ft_strlcpy((*line), (*chest), i + 1);
	*chest = ft_substr((*chest), i + 1, (size - i));
	if (!(*chest))
	{
		free(*chest);
		return (-1);
	}
	return (1);
}

static int	ft_freereturn(char **chest, int value)
{
	free(*chest);
	if (value == 0)
		*chest = NULL;
	return (value);
}

static int	ft_endfile(char **line, char **chest)
{
	int	i;
	int	size;

	size = ft_strlen(*chest);
	i = (ft_strchr(*chest, '\n'));
	if (i != -1)
		return (ft_nline(line, chest, i, size));
	if ((ft_strlen(*chest)) != 0)
	{
		(*line) = ft_strdup(*chest);
		if (!(*line))
			return (ft_freereturn(chest, -1));
	}
	else
	{
		(*line) = ft_strdup("");
		if (!(*line))
			return (ft_freereturn(chest, -1));
	}
	return (ft_freereturn(chest, 0));
}

static int	ft_nullify(char **line, char **chest)
{
	if (!(*chest))
	{
		(*line) = ft_strdup("");
		if (!(*line))
			return (-1);
		return (0);
	}
	return (ft_endfile(line, chest));
}

int			get_next_line(int fd, char **line)
{
	static char	*chest;
	int			i;
	int			store;
	int			size;
	char		buffer[1 + 1];

	store = (read(fd, buffer, 1));
	if (1 < 1 || fd < 0 || read(fd, 0, 0) < 0 || !line)
		return (-1);
	while (store > 0)
	{
		chest = ft_strjoin(chest, buffer, store);
		if (!chest)
		{
			if (chest != NULL)
				free(chest);
			return (-1);
		}
		size = ft_strlen(chest);
		i = (ft_strchr(chest, '\n'));
		if (i != -1)
			return (ft_nline(line, &chest, i, size));
		store = (read(fd, buffer, 1));
	}
	return (ft_nullify(line, &chest));
}
