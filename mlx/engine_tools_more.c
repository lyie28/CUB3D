/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine_tools_more.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyie <lyie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 11:52:27 by lyie              #+#    #+#             */
/*   Updated: 2021/04/23 12:34:15 by lyie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "../includes/cub3d.h"
#include "../includes/constants.h"
#include "../includes/structs.h"

void		ft_initplaynew(t_all *all)
{
	int	y;
	int	x;

	all->play.turn_dir = 0;
	all->play.hor_ang = 0;
	all->play.walk_dir = 0;
	all->win.max_x = 0;
	all->play.rotate_angle = 0;
	y = -1;
	while (all->data.map[++y])
	{
		x = -1;
		while (all->data.map[y][++x])
		{
			if (ft_charcheck("NSEW", all->data.map[y][x]))
			{
				all->play.y = y;
				all->play.x = x;
				ft_setangle(&all->play.rotate_angle, all->data.map[y][x]);
			}
		}
		all->win.max_x = x > all->win.max_x ? x : all->win.max_x;
	}
	all->win.max_y = y;
}

static int	ft_texturefail(t_all *all)
{
	write(1, "Error:\nTexture failed to load\n", 30);
	ft_close(all);
	return (-1);
}

int			ft_loadtextures(t_all *all)
{
	if (!(all->tex[0].img = mlx_xpm_file_to_image(all->mlx.mlx,
				all->data.no, &(all->tex[0].w), &(all->tex[0].h))))
		return (ft_texturefail(all));
	if (!(all->tex[1].img = mlx_xpm_file_to_image(all->mlx.mlx,
				all->data.ea, &(all->tex[1].w), &(all->tex[1].h))))
		return (ft_texturefail(all));
	if (!(all->tex[2].img = mlx_xpm_file_to_image(all->mlx.mlx,
				all->data.so, &(all->tex[2].w), &(all->tex[2].h))))
		return (ft_texturefail(all));
	if (!(all->tex[3].img = mlx_xpm_file_to_image(all->mlx.mlx,
				all->data.we, &(all->tex[3].w), &(all->tex[3].h))))
		return (ft_texturefail(all));
	if (!(all->tex[4].img = mlx_xpm_file_to_image(all->mlx.mlx,
				all->data.sprite, &(all->tex[4].w), &(all->tex[4].h))))
		return (ft_texturefail(all));
	ft_texture_address(all);
	return (1);
}

void		ft_freetextures(t_all *all)
{
	int	i;

	i = 0;
	while (all->tex[i].img && i < 5)
	{
		mlx_destroy_image(all->mlx.mlx, all->tex[i].img);
		i++;
	}
}

void		ft_setangle(float *angle, char c)
{
	if (c == 'N')
		*angle = 1.5 * PI;
	if (c == 'E')
		*angle = 0;
	if (c == 'S')
		*angle = 0.5 * PI;
	if (c == 'W')
		*angle = 1 * PI;
}
