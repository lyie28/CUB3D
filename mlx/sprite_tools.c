/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_tools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyie <lyie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 16:53:37 by lyie              #+#    #+#             */
/*   Updated: 2021/04/20 18:11:07 by lyie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "../includes/cub3d.h"
#include "../includes/constants.h"
#include "../includes/structs.h"

void		ft_initsprite(t_sprite *sprite, int sprite_no)
{
	sprite->x = 0;
	sprite->y = 0;
	sprite->dist = 0;
	sprite->angle = 0;
	sprite->left_x = 0;
	sprite->right_x = 0;
	sprite->top_y = 0;
	sprite->bot_y = 0;
	sprite->h = 0;
	sprite->w = 0;
	sprite->no = sprite_no;
}

t_3d		ft_setsprite(t_sprite *sprite, t_all *all)
{
	t_3d	mysprite;
	float	perpdist;

	mysprite.disttoplane = (all->win.w / 2) / tan(all->fov_ang / 2);
	sprite->angle = atan2(sprite->y - all->play.y,
			sprite->x - all->play.x) - all->play.rotate_angle;
	perpdist = sprite->dist * cos(sprite->angle);
	sprite->h = (all->win.tile / sprite->dist)
		* mysprite.disttoplane;
	sprite->w = sprite->h;
	sprite->top_y = (all->win.h / 2) - (sprite->h / 2);
	if (sprite->top_y < 0)
		sprite->top_y = 0;
	sprite->bot_y = (all->win.h / 2) + (sprite->h / 2);
	if (sprite->bot_y > all->win.h)
		sprite->bot_y = all->win.h;
	sprite->angle = ft_normalise_ang(sprite->angle);
	sprite->left_x = (all->win.w / 2)
		+ (tan(sprite->angle) * mysprite.disttoplane) - (sprite->w / 2);
	sprite->right_x = sprite->left_x + sprite->w;
	return (mysprite);
}

t_sprite	*ft_sortsprites(int no_sprites, t_sprite *sprites)
{
	int			i;
	int			j;
	t_sprite	temp;

	i = 0;
	while (i < no_sprites - 1)
	{
		j = i + 1;
		while (j < no_sprites)
		{
			ft_initsprite(&temp, no_sprites);
			if (sprites[i].dist < sprites[j].dist)
			{
				temp = sprites[i];
				sprites[i] = sprites[j];
				sprites[j] = temp;
			}
			j++;
		}
		i++;
	}
	return (sprites);
}

int			ft_spritevisible(t_all *all, t_sprite *sprite)
{
	sprite->angle = all->play.rotate_angle
		- atan2(sprite->y - all->play.y, sprite->x - all->play.x);
	if (sprite->angle > PI)
		sprite->angle = sprite->angle - (2 * PI);
	if (sprite->angle < PI * -1)
		sprite->angle = sprite->angle + (2 * PI);
	sprite->angle = fabsf(sprite->angle);
	if (sprite->angle < (all->fov_ang / 2))
		return (1);
	return (0);
}

int			ft_spritecount(t_all *all)
{
	int			x;
	int			y;
	int			sprite_no;
	t_sprite	temp;

	y = 0;
	sprite_no = 0;
	while (all->data.map[y])
	{
		x = 0;
		while (all->data.map[y][x])
		{
			if (all->data.map[y][x] == '2')
			{
				ft_initsprite(&temp, 0);
				temp.y = (y * all->win.tile + all->win.tile / 2);
				temp.x = (x * all->win.tile + all->win.tile / 2);
				if (ft_spritevisible(all, &temp))
					sprite_no++;
			}
			x++;
		}
		y++;
	}
	return (sprite_no);
}
