/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyie <lyie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 13:42:53 by lyie              #+#    #+#             */
/*   Updated: 2021/04/22 10:13:38 by lyie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "../includes/cub3d.h"
#include "../includes/constants.h"
#include "../includes/structs.h"

static void	ft_bmp_header(t_all *all, int fd)
{
	int	tmp;

	write(fd, "BM", 2);
	tmp = 14 + 40 + 4 * all->data.res[0] * all->data.res[1];
	write(fd, &tmp, 4);
	tmp = 0;
	write(fd, &tmp, 2);
	write(fd, &tmp, 2);
	tmp = 54;
	write(fd, &tmp, 4);
	tmp = 40;
	write(fd, &tmp, 4);
	write(fd, &all->data.res[0], 4);
	write(fd, &all->data.res[1], 4);
	tmp = 1;
	write(fd, &tmp, 2);
	write(fd, &all->mlx.bpp, 2);
	tmp = 0;
	write(fd, &tmp, 4);
	write(fd, &tmp, 4);
	write(fd, &tmp, 4);
	write(fd, &tmp, 4);
	write(fd, &tmp, 4);
	write(fd, &tmp, 4);
}

static void	ft_shutdown(t_all *all, int flag)
{
	if (flag == 1)
		write(1, "Error:\n Error creating .bmp file\n", 33);
	if (flag == 2)
		write(1, "Error:\n Error closing .bmp file\n", 32);
	ft_close(all);
}

int			ft_bmp(t_all *all, int *image_count)
{
	int	fd;
	int	y;
	int	x;

	(*image_count)++;
	fd = open("cub3D.bmp", O_CREAT | O_RDWR | O_TRUNC, S_IRUSR | S_IWUSR);
	if (!fd)
		ft_shutdown(all, 1);
	ft_bmp_header(all, fd);
	y = all->data.res[1] - 1;
	while (y >= 0)
	{
		x = -1;
		while (++x < all->data.res[0])
		{
			write(fd, &all->mlx.img_addr[y * all->mlx.line_len / 4 + x],
					4);
		}
		y--;
	}
	if (close(fd) == -1)
		ft_shutdown(all, 1);
	return (1);
}
