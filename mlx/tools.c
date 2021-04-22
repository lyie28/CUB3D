/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyie <lyie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 13:43:43 by lyie              #+#    #+#             */
/*   Updated: 2021/04/22 10:31:08 by lyie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "../includes/cub3d.h"
#include "../includes/structs.h"
#include "../includes/constants.h"

int		ft_keystop(int keycode, t_all *all)
{
	if (keycode == UP || keycode == DOWN)
		all->play.walk_dir = 0;
	if (keycode == LEFT || keycode == RIGHT)
	{
		all->play.hor_ang = 0;
		all->play.walk_dir = 0;
	}
	if (keycode == R_ARROW || keycode == L_ARROW)
		all->play.turn_dir = 0;
	return (1);
}

int		ft_keys(int keycode, t_all *all)
{
	int	i;

	i = 0;
	if (keycode == ESC)
	{
		ft_close(all);
		return (-1);
	}
	if (keycode == UP)
		all->play.walk_dir = -1;
	if (keycode == DOWN)
		all->play.walk_dir = 1;
	if (keycode == LEFT || keycode == RIGHT)
		all->play.hor_ang = (0.5 * PI);
	if (keycode == LEFT)
		all->play.walk_dir = -1;
	if (keycode == RIGHT)
		all->play.walk_dir = 1;
	if (keycode == R_ARROW)
		all->play.turn_dir = -1;
	if (keycode == L_ARROW)
		all->play.turn_dir = 1;
	return (1);
}

float	ft_normalise_ang(float ray_angle)
{
	ray_angle = remainder(ray_angle, (TWO_PI));
	if (ray_angle < 0)
		ray_angle = TWO_PI + ray_angle;
	return (ray_angle);
}

float	ft_hyp(float a1, float a2, float b1, float b2)
{
	return (sqrt(((a1 - a2) * (a1 - a2)) + ((b1 - b2) * (b1 - b2))));
}
