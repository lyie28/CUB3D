/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projector_more.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyie <lyie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 09:23:13 by lyie              #+#    #+#             */
/*   Updated: 2021/04/21 13:42:32 by lyie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "../includes/cub3d.h"
#include "../includes/constants.h"
#include "../includes/structs.h"

void	ft_distcheck(t_ray *ray, t_all all)
{
	float	h_len;
	float	v_len;

	h_len = ft_hyp(ray->hor_x, all.play.x, ray->hor_y, all.play.y);
	v_len = ft_hyp(ray->vert_x, all.play.x, ray->vert_y, all.play.y);
	if (ray->hor_hit == 0)
	{
		ray->hit_y = ray->vert_y;
		ray->hit_x = ray->vert_x;
		ray->hitisvert = 1;
	}
	else if (ray->vert_hit == 0 || h_len < v_len)
	{
		ray->hit_y = ray->hor_y;
		ray->hit_x = ray->hor_x;
	}
	else
	{
		ray->hit_y = ray->vert_y;
		ray->hit_x = ray->vert_x;
		ray->hitisvert = 1;
	}
}

t_3d	ft_set3ddata(t_ray ray, t_all all)
{
	t_3d build;

	build.perp = ray.dist * cos(ray.ray_angle - all.play.rotate_angle);
	build.disttoplane = (all.win.w / 2) / tan(all.fov_ang / 2);
	build.h = (all.win.tile / build.perp) * build.disttoplane;
	build.top_y = (all.win.h / 2) - (build.h / 2);
	if (build.top_y < 0)
		build.top_y = 0;
	build.bottom_y = (all.win.h / 2) + (build.h / 2);
	if (build.top_y > all.win.h)
		build.top_y = all.win.h;
	return (build);
}
