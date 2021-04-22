/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine_tools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyie <lyie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 10:24:31 by lyie              #+#    #+#             */
/*   Updated: 2021/04/21 14:04:00 by lyie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "../includes/cub3d.h"
#include "../includes/constants.h"
#include "../includes/structs.h"

static void		ft_setminis(t_all *all, int no)
{
	if (no == 0)
		all->mini.tile = no;
	all->mini.play_h = no;
	all->mini.play_w = no;
	all->mini.sprite_h = no;
	all->mini.sprite_w = no;
}

static void		ft_minisizes(t_all *all)
{
	int	mini_x;
	int	mini_y;

	all->mini.tile = 8;
	all->mini.play_h = 2;
	all->mini.play_w = 2;
	all->mini.sprite_h = 2;
	all->mini.sprite_w = 2;
	mini_x = all->data.map_maxx * all->mini.tile;
	mini_y = all->data.map_maxy * all->mini.tile;
	while (all->mini.tile >= 1 && (mini_y > (all->win.h / 4)
		|| mini_x > (all->win.w / 2)))
	{
		all->mini.tile--;
		if (all->mini.tile < 5)
			ft_setminis(all, 1);
		mini_x = all->data.map_maxx * all->mini.tile;
		mini_y = all->data.map_maxy * all->mini.tile;
	}
	if (all->mini.tile <= 1)
		ft_setminis(all, 0);
}

static void		ft_initsizes(t_all *all)
{
	all->win.h = all->data.res[1];
	all->win.w = all->data.res[0];
	all->win.tile = 24;
	all->play.x = all->play.x * all->win.tile + (all->win.tile / 2);
	all->play.y = all->play.y * all->win.tile + (all->win.tile / 2);
	ft_minisizes(all);
}

static void		ft_initplus(t_all *all)
{
	all->speed = 1;
	all->turn_speed = (PI / 90);
	all->fov_ang = 60 * (PI / 180);
	if (all->data.res[0] > 800 && all->data.res[1] > 800)
	{
		all->speed = 5;
		all->turn_speed = (PI / 50);
	}
	else if (all->data.res[0] > 700 && all->data.res[1] > 700)
		all->speed = 3;
	else if (all->data.res[0] > 350 && all->data.res[1] > 350)
	{
		all->turn_speed = (PI / 120);
		all->speed = 2;
	}
	else if (all->data.res[0] > 150 && all->data.res[1] > 150)
	{
		all->speed = 0.5;
		all->turn_speed = (PI / 250);
	}
	else if (all->data.res[0] > 0 && all->data.res[1] > 0)
	{
		all->speed = 0.2;
		all->turn_speed = (PI / 270);
	}
}

int				ft_initall(t_all *all)
{
	int	max_x;
	int	max_y;

	if (!(all->mlx.mlx = mlx_init()))
		return (-1);
	mlx_get_screen_size(all->mlx.mlx, &max_x, &max_y);
	if (all->data.res[0] >= max_x)
		all->data.res[0] = max_x;
	if (all->data.res[1] >= max_y)
		all->data.res[1] = max_y;
	if (!(all->mlx.mlx_win = mlx_new_window(all->mlx.mlx,
			all->data.res[0], all->data.res[1], "Cub3D")))
		return (-1);
	if (!(all->mlx.img = mlx_new_image(all->mlx.mlx,
			all->data.res[0], all->data.res[1])))
		return (-1);
	if (!(all->mlx.img_addr = (int *)mlx_get_data_addr(all->mlx.img,
			&all->mlx.bpp, &all->mlx.line_len, &all->mlx.endian)))
		return (-1);
	ft_initplus(all);
	ft_initplaynew(all);
	ft_initsizes(all);
	return (1);
}
