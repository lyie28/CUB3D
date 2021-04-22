/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyie <lyie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 13:44:07 by lyie              #+#    #+#             */
/*   Updated: 2021/04/21 13:11:32 by lyie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "../includes/cub3d.h"
#include "../includes/constants.h"
#include "../includes/structs.h"

void	ft_raycaster(t_all *all, t_ray *raystruct)
{
	int		rays;
	int		i;
	float	ray_angle;

	i = 0;
	rays = all->win.w;
	while (i < rays)
	{
		ray_angle = all->play.rotate_angle + atan((i - rays / 2) \
		/ ((rays / 2) / tan(all->fov_ang / 2)));
		raystruct[i] = ft_castray(i, ray_angle, (*all));
		ray_angle = 0;
		i++;
	}
}

t_ray	init_raydata(void)
{
	t_ray	ray;

	ray.ray_no = 0;
	ray.hitisvert = 0;
	ray.face_up = 0;
	ray.face_down = 0;
	ray.face_left = 0;
	ray.face_right = 0;
	ray.ray_angle = 0;
	ray.hor_x = 0;
	ray.hor_y = 0;
	ray.vert_x = 0;
	ray.vert_y = 0;
	ray.hit_x = 0;
	ray.hit_y = 0;
	ray.hor_hit = 0;
	ray.vert_hit = 0;
	ray.dist = 0;
	return (ray);
}

t_ray	ft_castray(int ray_no, float ray_angle, t_all all)
{
	t_ray	ray;
	t_3d	build;

	ray = init_raydata();
	ray.ray_no = ray_no;
	ray.ray_angle = ft_normalise_ang(ray_angle);
	if ((ray.ray_angle > 0 && ray.ray_angle < PI))
		ray.face_down = 1;
	else
		ray.face_up = 1;
	if (ray.ray_angle < (0.5 * PI) || ray.ray_angle > (1.5 * PI))
		ray.face_right = 1;
	else
		ray.face_left = 1;
	ft_checkhor(all, &ray);
	ft_checkvert(all, &ray);
	ft_distcheck(&ray, all);
	ray.dist = sqrt(((ray.hit_x - all.play.x)
				* (ray.hit_x - all.play.x))
			+ ((ray.hit_y - all.play.y) * (ray.hit_y - all.play.y)));
	build = ft_set3ddata(ray, all);
	ft_printcolumn(ray, build, &all);
	return (ray);
}
