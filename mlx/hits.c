/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hits.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyie <lyie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 13:09:40 by lyie              #+#    #+#             */
/*   Updated: 2021/04/21 14:12:47 by lyie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "../includes/cub3d.h"
#include "../includes/constants.h"
#include "../includes/structs.h"

static int		ft_checks(int checky, int checkx, t_all all)
{
	if (checky >= 0 && checky < all.data.map_maxy
		&& checkx >= 0 && checkx < all.data.map_maxx)
		return (1);
	return (0);
}

static t_hits	ft_setvert(t_all all, t_ray *ray)
{
	t_hits v;

	v.x = floor(all.play.x / all.win.tile) * all.win.tile;
	if (ray->face_right == 1)
		v.x = v.x + all.win.tile;
	v.y = all.play.y + (v.x - all.play.x) * tan(ray->ray_angle);
	v.xstep = all.win.tile;
	if (ray->face_left == 1)
		v.xstep = v.xstep * -1;
	v.ystep = all.win.tile * (tan(ray->ray_angle));
	if (ray->face_up == 1 && v.ystep > 0)
		v.ystep = v.ystep * -1;
	if (ray->face_down == 1 && v.ystep < 0)
		v.ystep = v.ystep * -1;
	v.checky = (int)floor(v.y / all.win.tile);
	v.checkx = (int)floor(v.x / all.win.tile);
	return (v);
}

void			ft_checkvert(t_all all, t_ray *ray)
{
	t_hits	v;

	v = ft_setvert(all, ray);
	while (ft_checks(v.checky, v.checkx, all))
	{
		v.tempx = v.x;
		if (ray->face_left == 1)
			v.tempx += -1;
		v.checkx = (int)floor(v.tempx / all.win.tile);
		if (ft_checks(v.checky, v.checkx, all) == 0)
			break ;
		if (all.data.map[v.checky][v.checkx] == '1')
		{
			ray->vert_x = v.x;
			ray->vert_y = v.y;
			ray->vert_hit = 1;
			break ;
		}
		v.x += v.xstep;
		v.y += v.ystep;
		v.checky = (int)floor(v.y / all.win.tile);
		v.checkx = (int)floor(v.x / all.win.tile);
	}
}

static	t_hits	ft_sethor(t_all all, t_ray *ray)
{
	t_hits	h;

	h.y = floor(all.play.y / all.win.tile) * all.win.tile;
	if (ray->face_down == 1)
		h.y = h.y + all.win.tile;
	h.x = all.play.x + (h.y - all.play.y) / tan(ray->ray_angle);
	h.ystep = all.win.tile;
	if (ray->face_up == 1)
		h.ystep = h.ystep * -1;
	h.xstep = all.win.tile / (tan(ray->ray_angle));
	if (ray->face_left == 1 && h.xstep > 0)
		h.xstep = h.xstep * -1;
	if (ray->face_right == 1 && h.xstep < 0)
		h.xstep = h.xstep * -1;
	h.checky = (int)floor(h.y / all.win.tile);
	h.checkx = (int)floor(h.x / all.win.tile);
	return (h);
}

void			ft_checkhor(t_all all, t_ray *ray)
{
	t_hits	h;

	h = ft_sethor(all, ray);
	while (ft_checks(h.checky, h.checkx, all))
	{
		h.tempy = h.y;
		if (ray->face_up == 1)
			h.tempy += -1;
		h.checky = (int)floor(h.tempy / all.win.tile);
		if (ft_checks(h.checky, h.checkx, all) == 0)
			break ;
		if (all.data.map[h.checky][h.checkx] == '1')
		{
			ray->hor_x = h.x;
			ray->hor_y = h.y;
			ray->hor_hit = 1;
			break ;
		}
		h.x += h.xstep;
		h.y += h.ystep;
		h.checkx = (int)floor(h.x / all.win.tile);
		h.checky = (int)floor(h.y / all.win.tile);
	}
}
