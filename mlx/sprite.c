/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyie <lyie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 13:44:17 by lyie              #+#    #+#             */
/*   Updated: 2021/04/20 18:10:14 by lyie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "../includes/cub3d.h"
#include "../includes/constants.h"
#include "../includes/structs.h"

static void	ft_printsprite(t_all *all, int y, int x)
{
	int	avoid;
	int	colour;
	int	position;

	position = (y * (all->mlx.line_len / 4)) + x;
	avoid = all->tex[4].addr[0];
	colour = all->tex[4].addr[(int)all->tex[4].off_y
		* all->tex[4].w + all->tex[4].off_x];
	if (colour != avoid)
		all->mlx.img_addr[position] = colour;
}

static void	ft_drawspr(t_sprite *spr, t_all *all, t_ray *ray, int s_no)
{
	t_draw	sp;

	sp.i = -1;
	while (++(sp.i) < s_no)
	{
		sp.x = (spr[sp.i].left_x) - 1;
		while (++(sp.x) < spr[sp.i].right_x)
		{
			sp.w = all->tex[4].w / spr[sp.i].w;
			all->tex[4].off_x = (int)(sp.x - spr[sp.i].left_x) * sp.w;
			sp.y = (spr[sp.i].top_y) - 1;
			while (++(sp.y) < spr[sp.i].bot_y)
			{
				if (sp.x > 0 && sp.x < all->win.w
						&& sp.y > 0 && sp.y < all->win.h)
				{
					sp.top = sp.y + (spr[sp.i].h / 2) - (all->win.h / 2);
					all->tex[4].off_y = sp.top * (all->tex[4].h / spr[sp.i].h);
					if (spr[sp.i].dist < ray[sp.x].dist)
						ft_printsprite(all, sp.y, sp.x);
				}
			}
		}
	}
}

static void	ft_match(t_all *all, t_sprite *spr, int sprite_no, t_draw co)
{
	ft_initsprite(spr, sprite_no);
	spr->y = co.y * all->win.tile + all->win.tile / 2;
	spr->x = co.x * all->win.tile + all->win.tile / 2;
}

static void	ft_assign(t_sprite *sprite, t_all *all)
{
	sprite->dist = ft_hyp(sprite->x, all->play.x, sprite->y, all->play.y);
}

void		ft_rendersprite(t_all *a, t_ray *raystruct, int s_no)
{
	t_draw		co;
	t_3d		myspr[s_no + 1];
	t_sprite	sp[s_no + 1];

	co.y = -1;
	co.i = 0;
	while (a->data.map[++(co.y)])
	{
		co.x = -1;
		while (a->data.map[co.y][++(co.x)])
		{
			if (a->data.map[co.y][co.x] == '2')
			{
				ft_match(a, &sp[co.i], s_no, co);
				if (ft_spritevisible(a, &sp[co.i]))
				{
					ft_assign(&sp[co.i], a);
					myspr[co.i] = ft_setsprite(&sp[co.i], a);
					co.i++;
				}
			}
		}
	}
	ft_sortsprites(s_no, sp);
	ft_drawspr(sp, a, raystruct, s_no);
}
