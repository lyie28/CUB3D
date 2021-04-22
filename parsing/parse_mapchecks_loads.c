/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_mapchecks_loads.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 11:31:12 by user42            #+#    #+#             */
/*   Updated: 2021/04/22 09:28:16 by lyie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

char		*ft_line_prep(char **line, char *buffer, t_checks *checks)
{
	int	i;
	int	size;

	if (!spaceline(*line))
	{
		i = -1;
		while (ft_spacebar((*line)[++i]))
			(*line)[i] = '+';
		while ((*line)[++i])
			ft_swap(&((*line)[i]));
	}
	size = ft_maplen(*line);
	if (size < 3)
		checks->size = -1;
	return (ft_mapjoin(buffer, (*line), size + 2));
}

int			ft_inputter(t_data *data, char *line)
{
	int	i;
	int	err;

	err = 0;
	i = 0;
	if (!line)
		return (-1);
	if (line[i] && !(ft_fullhouse(*data)))
	{
		while (ft_spacebar(line[i]))
			i++;
		if (line[i])
		{
			err = ft_fillin(&line[i], data);
			if (err == -1)
				return (-3);
			i++;
		}
	}
	if (ft_fullhouse(*data))
		return (-2);
	return (0);
}

static int	ft_validpaths(t_data data)
{
	int	fd;

	fd = open(data.no, O_RDONLY);
	close(fd);
	if (fd < 0)
		return (0);
	fd = open(data.so, O_RDONLY);
	close(fd);
	if (fd < 0)
		return (0);
	fd = open(data.ea, O_RDONLY);
	close(fd);
	if (fd < 0)
		return (0);
	fd = open(data.we, O_RDONLY);
	close(fd);
	if (fd < 0)
		return (0);
	fd = open(data.sprite, O_RDONLY);
	close(fd);
	if (fd < 0)
		return (0);
	return (1);
}

int			ft_runmapchecks(t_data *data, int rows)
{
	if (ft_border((*data).map, rows) == 0)
		return (ft_printerrorfree(data->errors.fifteen, data));
	if (ft_border((*data).map, rows) == -1)
		return (ft_printerrorfree(data->errors.sixteen, data));
	if (ft_validmap((*data).map, rows) == -1)
		return (ft_printerrorfree(data->errors.seven, data));
	if (ft_validmap((*data).map, rows) == 0)
		return (ft_printerrorfree(data->errors.nine, data));
	if (ft_overlap((*data).map, rows) != 1)
		return (ft_printerrorfree(data->errors.ten, data));
	return (1);
}

int			ft_runchecks(t_data *data, int rows)
{
	if (ft_colours(data) == -1)
		return (-1);
	if (ft_rescheck((*data).res, data) == -1)
		return (-1);
	if (!ft_validpaths(*data))
		return (ft_printerrorfree(data->errors.svteen, data));
	return (ft_runmapchecks(data, rows));
}
