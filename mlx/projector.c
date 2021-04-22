/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projector.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyie <lyie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 13:42:42 by lyie              #+#    #+#             */
/*   Updated: 2021/04/21 09:32:14 by lyie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "../includes/cub3d.h"
#include "../includes/constants.h"
#include "../includes/structs.h"

static t_tex	ft_whichtex(t_ray ray, t_all *all)
{
	if (ray.face_up == 1)
	{
		if (ray.hitisvert == 0)
			return (all->tex[0]);
		else if (ray.face_right == 1)
			return (all->tex[1]);
		else
			return (all->tex[3]);
	}
	else
	{
		if (ray.hitisvert == 0)
			return (all->tex[2]);
		else if (ray.face_right == 1)
			return (all->tex[1]);
		else
			return (all->tex[3]);
	}
}

static void		ft_shadow(int *colour, float factor)
{
	int	a;
	int	r;
	int	g;
	int	b;

	a = (*colour & 0xFF000000);
	r = (*colour & 0xFF0000) * factor;
	g = (*colour & 0x00FF00) * factor;
	b = (*colour & 0x0000FF) * factor;
	*colour = (r & 0xFF0000) + (g & 0x00FF00) + (b & 0x0000FF);
}

static int		ft_set(t_tex tex, t_3d build, t_all *all, int y)
{
	int	topdist;
	int	colour;

	topdist = y + (build.h / 2) - (all->win.h / 2);
	tex.off_y = topdist * (float)tex.h / build.h;
	colour = tex.addr[tex.off_y * tex.w + tex.off_x];
	return (colour);
}

static void		ft_setoff_x(t_ray ray, t_tex *tex, t_all *all)
{
	if (ray.hitisvert == 1)
		(*tex).off_x = (int)(ray.hit_y * (*tex).w / all->win.tile)
			% (*tex).w;
	else
		(*tex).off_x = (int)(ray.hit_x * (*tex).w / all->win.tile)
			% (*tex).w;
}

void			ft_printcolumn(t_ray ray, t_3d build, t_all *all)
{
	int		y;
	int		position;
	int		colour;
	t_tex	tex;

	y = -1;
	tex = ft_whichtex(ray, all);
	ft_setoff_x(ray, &tex, all);
	while (++y < all->win.h)
	{
		position = y * (all->mlx.line_len / 4) + ray.ray_no;
		if (y < build.top_y && y >= 0)
			all->mlx.img_addr[position] = all->data.ceiling_rgb;
		if (y >= build.top_y && y < build.bottom_y)
		{
			colour = ft_set(tex, build, all, y);
			if (ray.hitisvert == 1)
				ft_shadow(&colour, 0.8);
			all->mlx.img_addr[position] = colour;
		}
		if (y >= build.bottom_y && y < all->win.h)
			all->mlx.img_addr[position] = all->data.floor_rgb;
	}
}
