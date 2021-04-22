/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 22:42:12 by user42            #+#    #+#             */
/*   Updated: 2021/04/21 14:19:30 by lyie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include "get_next_line.h"
# include "cub3d.h"
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <fcntl.h>
# include <math.h>

typedef struct	s_sprite
{
	float	x;
	float	y;
	float	dist;
	float	angle;
	float	h;
	float	w;
	float	left_x;
	float	right_x;
	float	bot_y;
	float	top_y;
	int		no;
}				t_sprite;

typedef struct	s_window
{
	int	tile;
	int	h;
	int	w;
	int	max_x;
	int	max_y;
}				t_window;

typedef struct	s_3d
{
	float	disttoplane;
	float	perp;
	float	projwallh;
	int		h;
	int		top_y;
	int		bottom_y;
}				t_3d;

typedef struct	s_mlxdata
{
	void	*mlx;
	void	*mlx_win;
	void	*img;
	int		*img_addr;
	int		bpp;
	int		line_len;
	int		endian;
	int		close;

}				t_mlxdata;

typedef struct	s_checks
{
	int gnl;
	int input;
	int size;
}				t_checks;

typedef struct	s_errors
{
	char	*one;
	char	*two;
	char	*three;
	char	*four;
	char	*five;
	char	*six;
	char	*seven;
	char	*eight;
	char	*nine;
	char	*ten;
	char	*eleven;
	char	*twelve;
	char	*thirteen;
	char	*fourteen;
	char	*fifteen;
	char	*sixteen;
	char	*svteen;
	char	*eighteen;
	char	*nineteen;
	char	*twenty;
	char	*tone;
	char	*ttwo;
}				t_errors;

typedef struct	s_draw
{
	int		i;
	int		x;
	int		y;
	float	w;
	int		top;
}				t_draw;

typedef struct	s_tex
{
	void	*img;
	int		*addr;
	int		bpp;
	int		line_len;
	int		endian;
	int		h;
	int		w;
	int		off_x;
	int		off_y;
	int		colour;
}				t_tex;

typedef struct	s_square
{
	int				x;
	int				y;
	int				w;
	int				h;
	unsigned int	colour;
	unsigned int	outline;
}				t_square;

typedef struct	s_data
{
	int			full_house;
	int			res[3];
	int			floor[3];
	int			ceiling[3];
	unsigned	floor_rgb;
	unsigned	ceiling_rgb;
	char		*sprite;
	char		*no;
	char		*so;
	char		*ea;
	char		*we;
	char		**map;
	int			save;
	int			map_maxx;
	int			map_maxy;
	t_errors	errors;
}				t_data;

typedef struct	s_play
{
	float	x;
	float	y;
	float	rotate_angle;
	float	hor_ang;
	int		turn_dir;
	int		walk_dir;
}				t_play;

typedef struct	s_hits
{
	float	x;
	float	y;
	float	xstep;
	float	ystep;
	float	tempx;
	float	tempy;
	int		checkx;
	int		checky;
}				t_hits;

typedef struct	s_mini
{
	int	tile;
	int	play_h;
	int	play_w;
	int	sprite_h;
	int	sprite_w;
}				t_mini;

typedef	struct	s_compass
{
	int	x;
	int	y;
}				t_compass;

typedef struct	s_ray
{
	float	ray_angle;
	float	hit_x;
	float	hit_y;
	float	vert_x;
	float	vert_y;
	float	hor_x;
	float	hor_y;
	float	dist;
	int		face_up;
	int		face_down;
	int		face_left;
	int		face_right;
	int		vert_hit;
	int		hor_hit;
	int		ray_no;
	int		hitisvert;
}				t_ray;

typedef struct	s_all
{
	t_mlxdata	mlx;
	t_sprite	sprite;
	t_data		data;
	t_play		play;
	t_window	win;
	t_tex		tex[5];
	t_mini		mini;
	float		fov_ang;
	float		speed;
	float		turn_speed;
}				t_all;

typedef struct	s_line
{
	int		position;
	int		deltax;
	int		deltay;
	int		longestside;
	int		i;
	float	xincrement;
	float	yincrement;
	float	currentx;
	float	currenty;
}				t_line;

#endif
