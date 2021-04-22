/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_more.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 11:33:12 by user42            #+#    #+#             */
/*   Updated: 2021/04/20 14:05:59 by lyie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_number_builder(int *place, int *i, char c)
{
	*place = (*place * 10) + (c - '0');
	(*i)++;
}

void	ft_data_init(t_data *data)
{
	(*data).res[0] = -1;
	(*data).res[1] = -1;
	(*data).res[2] = '\0';
	(*data).no = 0;
	(*data).so = 0;
	(*data).we = 0;
	(*data).ea = 0;
	(*data).ceiling[0] = -1;
	(*data).ceiling[1] = -1;
	(*data).ceiling[2] = -1;
	(*data).ceiling_rgb = 0;
	(*data).floor[0] = -1;
	(*data).floor[1] = -1;
	(*data).floor[2] = -1;
	(*data).floor_rgb = 0;
	(*data).sprite = NULL;
	(*data).map = NULL;
	(*data).save = 0;
	(*data).map_maxx = 0;
	(*data).map_maxy = 0;
}

int		ft_charcheckall(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != c)
			return (0);
		i++;
	}
	return (1);
}

int		ft_charcheck(char *str, char c)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			count++;
		i++;
	}
	if (count == 0)
		return (0);
	return (1);
}
