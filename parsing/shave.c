/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shave.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyie <lyie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 09:59:43 by lyie              #+#    #+#             */
/*   Updated: 2021/04/20 10:59:36 by lyie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	ft_freemap(int i, int end, char **map)
{
	while (i < end)
	{
		free(map[i]);
		i++;
	}
	free(map);
}

static char	**ft_cutup(char **map, int startcut, int endcut, t_data *data)
{
	int		size;
	int		y;
	int		i;
	char	**newmap;

	y = 0;
	while (map[y])
		y++;
	size = y - ((startcut - 1) + (endcut - 1)) + 2;
	if (!(newmap = malloc(sizeof(char *) * size)))
	{
		ft_printerrorfree(data->errors.ttwo, data);
		return (NULL);
	}
	startcut--;
	i = -1;
	while (++i < size - 1)
	{
		if (i < startcut)
			free(map[i]);
		newmap[i] = map[startcut + i];
	}
	newmap[i] = NULL;
	ft_freemap(i, y, map);
	return (newmap);
}

static int	ft_allwalls(char **line)
{
	int	x;

	x = 0;
	while ((*line)[x])
	{
		if ((*line)[x] == '+')
			(*line)[x] = '1';
		if ((*line)[x] == ' ')
			(*line)[x] = '1';
		if ((*line)[x] != '1')
			return (0);
		x++;
	}
	return (1);
}

int			ft_shave(t_data *data)
{
	int	y;
	int	startcut;
	int	endcheck;

	y = -1;
	while (data->map[++y])
	{
		if (!ft_allwalls(&data->map[y]))
			break ;
	}
	startcut = y;
	while (data->map[y])
		y++;
	y = y - 1;
	endcheck = y + 1;
	while (--y >= 0)
	{
		if (!ft_allwalls(&data->map[y]))
			break ;
	}
	if (startcut > 1 || (endcheck - y) > 1)
		data->map = ft_cutup(data->map, startcut, (endcheck - y), data);
	if (!data->map)
		return (-1);
	return (1);
}
