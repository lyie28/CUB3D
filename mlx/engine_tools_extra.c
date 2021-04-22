/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine_tools_extra.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyie <lyie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 13:56:37 by lyie              #+#    #+#             */
/*   Updated: 2021/04/21 13:56:46 by lyie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "../includes/cub3d.h"
#include "../includes/constants.h"
#include "../includes/structs.h"

void			ft_texture_address(t_all *all)
{
	int	i;

	i = -1;
	all->tex[0].addr = (int *)mlx_get_data_addr(all->tex[0].img, &all->mlx.bpp,
		&all->mlx.line_len, &all->mlx.endian);
	all->tex[1].addr = (int *)mlx_get_data_addr(all->tex[1].img, &all->mlx.bpp,
		&all->tex[1].line_len, &all->mlx.endian);
	all->tex[2].addr = (int *)mlx_get_data_addr(all->tex[2].img, &all->mlx.bpp,
		&all->mlx.line_len, &all->mlx.endian);
	all->tex[3].addr = (int *)mlx_get_data_addr(all->tex[3].img, &all->mlx.bpp,
		&all->mlx.line_len, &all->mlx.endian);
	all->tex[4].addr = (int *)mlx_get_data_addr(all->tex[4].img, &all->mlx.bpp,
		&all->mlx.line_len, &all->mlx.endian);
	while (++i < 5)
	{
		all->tex[i].off_x = 0;
		all->tex[i].off_y = 0;
		all->tex[i].colour = 0;
	}
}
