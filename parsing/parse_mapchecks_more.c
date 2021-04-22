/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_mapchecks_more.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 11:31:33 by user42            #+#    #+#             */
/*   Updated: 2021/04/22 10:12:17 by lyie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int			spaceline(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (!ft_spacebar(line[i]))
			return (0);
		i++;
	}
	return (1);
}

static int	ft_check(char *line, int x)
{
	int		len;
	int		fin;
	char	*valids;

	valids = "NSWE120";
	fin = 0;
	fin = x + 1;
	len = ft_strlen(line);
	if (len <= fin)
		return (-1);
	if ((x - 1) < 0)
		return (-1);
	x = x - 1;
	while (x <= fin)
	{
		if (!(ft_charcheck(valids, line[x])))
			return (-1);
		x++;
	}
	return (1);
}

int			ft_overlap(char **map, int rows)
{
	int	x;
	int	y;

	y = -1;
	while (++y < rows)
	{
		x = -1;
		while (map[y][++x])
		{
			if (ft_charcheck("02NESW", map[y][x]))
			{
				if (y - 1 > 0)
				{
					if (ft_check(map[y - 1], x) == -1)
						return (-1);
				}
				if ((y + 1) < rows)
				{
					if (ft_check(map[y + 1], x) == -1)
						return (-1);
				}
			}
		}
	}
	return (1);
}
