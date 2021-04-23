/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyie <lyie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 13:43:04 by lyie              #+#    #+#             */
/*   Updated: 2021/04/23 17:10:36 by lyie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "../includes/cub3d.h"
#include "../includes/constants.h"
#include "../includes/structs.h"

int			ft_close(t_all *all)
{
	int i;

	i = 0;
	system("killall -9 --quiet aplay");
	all->mlx.close = 1;
	ft_freestruct(&all->data);
	ft_freetextures(all);
	if (all->mlx.img)
		mlx_destroy_image(all->mlx.mlx, all->mlx.img);
	if (all->mlx.mlx_win)
		mlx_destroy_window(all->mlx.mlx, all->mlx.mlx_win);
	if (all->mlx.mlx)
	{
		mlx_destroy_display(all->mlx.mlx);
		free(all->mlx.mlx);
	}
	exit(0);
}

static int	ft_newimage(t_all *all)
{
	mlx_destroy_image(all->mlx.mlx, all->mlx.img);
	all->mlx.img = mlx_new_image(all->mlx.mlx,
			all->data.res[0], all->data.res[1]);
	if (!all->mlx.img)
		return (-1);
	all->mlx.img_addr = (int *)mlx_get_data_addr(all->mlx.img,
			&all->mlx.bpp, &all->mlx.line_len, &all->mlx.endian);
	if (!all->mlx.img_addr)
		return (-1);
	return (0);
}

static int	ft_setposition(t_play play, t_all *all, float step)
{
	int	ch_x;
	int	ch_y;

	ch_x = (int)floor((play.x + cos(ft_normalise_ang(play.rotate_angle
		+ play.hor_ang)) * step) / all->win.tile);
	ch_y = (int)floor((play.y + sin(ft_normalise_ang(play.rotate_angle
		+ play.hor_ang)) * step) / all->win.tile);
	if (ch_y < 0 || ch_x < 0 || ch_y >= all->win.max_y
		|| ch_x >= all->win.max_x)
		return (0);
	if (all->data.map[ch_y][ch_x] == '1')
		return (0);
	else
	{
		all->play.x = all->play.x + cos(ft_normalise_ang(
				all->play.rotate_angle + all->play.hor_ang)) * step;
		all->play.y = all->play.y + sin(ft_normalise_ang(
				all->play.rotate_angle + all->play.hor_ang)) * step;
		return (1);
	}
}

static int	ft_launch(t_all *all)
{
	static int	image_count;
	int			sprite_no;
	float		step;
	t_ray		raystruct[all->win.w];

	step = 0;
	all->play.rotate_angle += all->play.turn_dir * all->turn_speed;
	all->play.rotate_angle = ft_normalise_ang(all->play.rotate_angle);
	step = all->play.walk_dir * all->speed;
	ft_setposition(all->play, all, step);
	if (ft_newimage(all) == -1)
		ft_close(all);
	ft_raycaster(all, raystruct);
	ft_normalise_ang(all->play.rotate_angle);
	sprite_no = ft_spritecount(all);
	ft_rendersprite(all, raystruct, sprite_no);
	if (all->mini.tile > 0)
	{
		ft_minimap(all, 0);
		ft_minimap_rays(all, raystruct);
	}
	mlx_put_image_to_window(all->mlx.mlx, all->mlx.mlx_win, all->mlx.img, 0, 0);
	if (image_count == 0 && all->data.save == 1)
		ft_bmp(all, &image_count);
	return (1);
}

int			ft_mlxbuild(t_data data)
{
	t_all	all;

	all.mlx.close = 0;
	all.data = data;
	ft_initall(&all);
	ft_loadtextures(&all);
	system("aplay -q ./sounds/FYBVB.wav &");
	if (all.mlx.close == 1)
		return (1);
	mlx_loop_hook(all.mlx.mlx, ft_launch, &all);
	mlx_hook(all.mlx.mlx_win, 33, 1L << 17, ft_close, &(all));
	mlx_hook(all.mlx.mlx_win, 2, 1L << 0, ft_keys, &(all));
	mlx_hook(all.mlx.mlx_win, 3, 1L << 1, ft_keystop, &(all));
	mlx_loop(all.mlx.mlx);
	return (0);
}
