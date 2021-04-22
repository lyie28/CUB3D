/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_prep.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyie <lyie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 13:43:20 by lyie              #+#    #+#             */
/*   Updated: 2021/04/22 10:14:55 by lyie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "../includes/cub3d.h"
#include "../includes/constants.h"
#include "../includes/structs.h"

int			ft_beforewall(char *line)
{
	int		i;
	int		x;
	char	*chars;

	chars = "02NSWE\n";
	i = ft_strlen(line) - 2;
	if (!line[i])
		return (0);
	while (i > 0)
	{
		x = 0;
		while (x < 6)
		{
			if (line[i] == chars[x])
				return (i);
			x++;
		}
		i--;
	}
	return (0);
}

void		ft_getmaxvalues(t_data *data)
{
	int	y;
	int	x;
	int	last_zero;

	y = 0;
	last_zero = 0;
	while (data->map[y])
	{
		x = 0;
		last_zero = ft_beforewall(data->map[y]);
		if (last_zero + 1 > data->map_maxx)
			data->map_maxx = last_zero + 2;
		y++;
	}
	data->map_maxy = y;
}

static int	ft_append(char **line, int size, int line_len)
{
	int		i;
	char	*new_line;

	i = 0;
	if (!(new_line = malloc(sizeof(char) * size + 1)))
		return (-1);
	while (i < line_len)
	{
		new_line[i] = (*line)[i];
		i++;
	}
	while (i < size)
	{
		new_line[i] = '1';
		i++;
	}
	new_line[i] = '\0';
	free((*line));
	*line = new_line;
	return (1);
}

static int	ft_trim(char **line, int size)
{
	char	*new_line;
	int		i;

	i = 0;
	if (!(new_line = malloc(sizeof(char) * size + 1)))
		return (-1);
	while (i < size)
	{
		new_line[i] = (*line)[i];
		i++;
	}
	new_line[i] = '\0';
	free(*line);
	*line = new_line;
	return (1);
}

int			ft_squarise(t_data *data)
{
	int	y;
	int	len;

	y = 0;
	while (data->map[y])
	{
		len = ft_strlen(data->map[y]);
		if (len < data->map_maxx)
		{
			if (!(ft_append(&data->map[y], data->map_maxx, len)))
				return (-1);
		}
		if (len > data->map_maxx)
		{
			if (!(ft_trim(&data->map[y], data->map_maxx)))
				return (-1);
		}
		y++;
	}
	return (1);
}
