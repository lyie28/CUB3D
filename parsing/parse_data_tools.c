/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_data_tools.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 19:37:26 by user42            #+#    #+#             */
/*   Updated: 2021/03/09 20:03:08 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	ft_xpmcheck(char *str)
{
	if (str[0] != '.' || str[1] != 'x')
		return (0);
	if (str[2] != 'p' || str[3] != 'm')
		return (0);
	return (1);
}

int	ft_fullhouse(t_data data)
{
	if (data.res[0] == -1 && data.res[1] == -1)
		return (0);
	if (data.no == NULL)
		return (0);
	if (data.so == NULL)
		return (0);
	if (data.ea == NULL)
		return (0);
	if (data.we == NULL)
		return (0);
	if (data.sprite == NULL)
		return (0);
	if (data.floor[0] == -1 && data.floor[1] == -1 && data.floor[2] == -1)
		return (0);
	if (data.ceiling[0] == -1 && data.ceiling[1] == -1 && data.ceiling[2] == -1)
		return (0);
	return (1);
}
