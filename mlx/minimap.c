/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyie <lyie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 13:43:32 by lyie              #+#    #+#             */
/*   Updated: 2021/04/22 10:10:48 by lyie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "../includes/cub3d.h"
#include "../includes/constants.h"
#include "../includes/structs.h"

void		ft_square(t_square square, t_mlxdata *mlx, int funct, t_all *all)
{
	int total_w;
	int total_h;
	int x;
	int pos;
	int starty;

	starty = square.y;
	total_w = square.x + all->mini.tile;
	total_h = square.y + all->mini.tile;
	square.outline = 0;
	while (square.y <= total_h)
	{
		x = (square.x) - 1;
		while (++x <= total_w)
		{
			pos = (square.y * (mlx->line_len / 4) + x);
			if (x == square.x || x == total_w)
				mlx->img_addr[pos] = square.outline;
			else if (square.y == starty || square.y == total_h)
				mlx->img_addr[pos] = square.outline;
			else if (funct == 0)
				mlx->img_addr[pos] = square.colour;
		}
		(square.y)++;
	}
}

void		ft_minimap_play(t_all *all, unsigned int colour)
{
	int total_w;
	int total_h;
	int x;
	int y;
	int position;

	y = ((all->play.y / all->win.tile) * all->mini.tile)
		- (all->mini.play_h / 2);
	x = ((all->play.x / all->win.tile) * all->mini.tile)
		- (all->mini.play_w / 2);
	total_h = y + all->mini.play_h;
	total_w = x + all->mini.play_w;
	while (y <= total_h)
	{
		x = (all->play.x / all->win.tile) * all->mini.tile
			- (all->mini.play_w / 2);
		while (x <= total_w)
		{
			position = (y * all->mlx.line_len / 4 + x);
			all->mlx.img_addr[position] = colour;
			x++;
		}
		y++;
	}
}

void		ft_minimap_rays(t_all *all, t_ray *rays)
{
	int			i;
	t_compass	start;
	int			endx;
	int			endy;

	i = 0;
	while (i < all->win.w)
	{
		start.x = all->play.x / all->win.tile * all->mini.tile;
		start.y = all->play.y / all->win.tile * all->mini.tile;
		endx = rays[i].hit_x / all->win.tile * all->mini.tile;
		endy = rays[i].hit_y / all->win.tile * all->mini.tile;
		ft_drawline2(start, endx, endy, all);
		i++;
	}
	ft_minimap(all, 1);
	ft_minimap_sprite(all);
}

static int	ft_unnecessary(int y, int x, t_all all)
{
	int	necessary;
	int	temp;

	temp = 0;
	necessary = 0;
	y--;
	if (y > 0)
		necessary = ft_beforewall(all.data.map[y]);
	y++;
	if (y > 0 && y < all.data.map_maxy)
		temp = ft_beforewall(all.data.map[y]);
	if (temp > necessary)
		necessary = temp;
	y++;
	if (all.data.map[y] && y < all.data.map_maxy)
		temp = ft_beforewall(all.data.map[y]);
	if (temp > necessary)
		necessary = temp;
	if (necessary == 0)
		return (1);
	if (x > necessary + 1)
		return (0);
	else
		return (1);
}

void		ft_minimap(t_all *all, int funct)
{
	int			y;
	int			x;
	t_square	square;

	y = 0;
	while (all->data.map[y] != NULL)
	{
		x = 0;
		square.y = y * all->mini.tile;
		while (all->data.map[y][x])
		{
			square.x = x * all->mini.tile;
			if (all->data.map[y][x] == '1')
				square.colour = all->data.ceiling_rgb;
			if (ft_charcheck("NSWE02", all->data.map[y][x]))
				square.colour = all->data.floor_rgb;
			if (ft_unnecessary(y, x, *all) == 1)
				ft_square(square, &(all->mlx), funct, all);
			x++;
		}
		y++;
	}
	ft_minimap_play(all, 8388736);
}
