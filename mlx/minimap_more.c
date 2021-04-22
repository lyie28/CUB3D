/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_more.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyie <lyie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 09:57:50 by lyie              #+#    #+#             */
/*   Updated: 2021/04/21 14:01:55 by lyie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "../includes/cub3d.h"
#include "../includes/constants.h"
#include "../includes/structs.h"

void	ft_drawline2(t_compass start, int endx, int endy, t_all *all)
{
	t_line l;

	l.i = 0;
	l.deltax = (endx - start.x);
	l.deltay = (endy - start.y);
	l.longestside = abs(l.deltax) >= abs(l.deltay) ?
		abs(l.deltax) : abs(l.deltay);
	l.xincrement = l.deltax / (float)l.longestside;
	l.yincrement = l.deltay / (float)l.longestside;
	l.currentx = start.x;
	l.currenty = start.y;
	while (l.i < l.longestside)
	{
		l.position = ((round(l.currenty)) * (all->mlx.line_len / 4)
				+ (round(l.currentx)));
		if (l.currenty > 0 && l.currenty < all->win.w)
		{
			if (l.currentx > 0 && l.currentx < all->win.h)
				all->mlx.img_addr[l.position] = 16738740;
		}
		l.currentx += l.xincrement;
		l.currenty += l.yincrement;
		l.i++;
	}
}

void	ft_mini_drawsprite(int y, int x, t_all *all)
{
	int	endy;
	int	endx;
	int	position;
	int startx;

	startx = x;
	endy = y + all->mini.sprite_h;
	endx = x + all->mini.sprite_w;
	while (y <= endy)
	{
		x = startx;
		while (x <= endx)
		{
			position = (y * all->mlx.line_len / 4 + x);
			all->mlx.img_addr[position] = 6749952;
			x++;
		}
		y++;
	}
}

void	ft_minimap_sprite(t_all *all)
{
	int	x;
	int	y;
	int s_x;
	int	s_y;

	y = 0;
	while (all->data.map[y])
	{
		x = 0;
		while (all->data.map[y][x])
		{
			if (all->data.map[y][x] == '2')
			{
				s_y = y * all->mini.tile + (all->mini.tile
					/ 2) - (all->mini.sprite_h / 2);
				s_x = x * all->mini.tile + (all->mini.tile
					/ 2) - (all->mini.sprite_w / 2);
				ft_mini_drawsprite(s_y, s_x, all);
			}
			x++;
		}
		y++;
	}
}
