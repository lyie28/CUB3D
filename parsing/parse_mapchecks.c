/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_mapchecks.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 18:41:35 by user42            #+#    #+#             */
/*   Updated: 2021/04/22 10:14:37 by lyie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	ft_border(char **map, int rows)
{
	int	i;
	int	j;
	int	len;

	i = -1;
	len = 0;
	while (++i < rows)
	{
		j = 0;
		while (map[i][j] == '+')
			j++;
		if (i == 0 || i == rows - 1)
		{
			if (!(ft_charcheckall(&map[i][j], '1')))
				return (-1);
		}
		else
		{
			len = ft_strlen(map[i]);
			if (map[i][j] != '1' || map[i][len - 1] != '1')
				return (0);
		}
	}
	return (1);
}

int	ft_validmap(char **map, int rows)
{
	int		i;
	int		j;
	int		stock;
	char	*directions;
	char	*valids;

	directions = "NSEW";
	valids = "NSEW012+";
	stock = 0;
	i = -1;
	while (++i < rows)
	{
		j = -1;
		while (map[i][++j])
		{
			if (!ft_charcheck(valids, map[i][j]))
				return (0);
			if (ft_charcheck(directions, map[i][j]))
				stock++;
		}
	}
	if (stock != 1)
		return (-1);
	return (1);
}

int	ft_rescheck(int res[2], t_data *data)
{
	int	i;

	i = 0;
	while (i < 2)
	{
		if (res[i] < 1 || res[i] >= INT_MAX)
			return (ft_printerrorfree(data->errors.thirteen, data));
		i++;
	}
	return (1);
}

int	ft_colours(t_data *data)
{
	int	i;
	int	error;

	i = -1;
	error = 0;
	while (++i < 3)
	{
		if ((*data).floor[i] < 0 || (*data).floor[i] > 255)
			return (ft_printerrorfree(data->errors.five, data));
	}
	(*data).floor_rgb = ((*data).floor[0] << 16) + ((*data).floor[1] << 8)
		+ (*data).floor[2];
	while (++i < 3)
	{
		if ((*data).ceiling[i] < 0 || (*data).ceiling[i] > 255)
			return (ft_printerrorfree(data->errors.five, data));
	}
	(*data).ceiling_rgb = ((*data).ceiling[0] << 16)
		+ ((*data).ceiling[1] << 8) + (*data).ceiling[2];
	return (1);
}
