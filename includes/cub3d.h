/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 22:42:12 by user42            #+#    #+#             */
/*   Updated: 2021/04/22 09:33:36 by lyie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "get_next_line.h"
# include "structs.h"
# include <unistd.h>
# include <math.h>
# include <stdlib.h>
# include <limits.h>
# include <fcntl.h>
# include "../minilibx-linux/mlx.h"

int			ft_spritecount(t_all *all);
int			ft_maplen(char *line);
void		ft_swap(char *c);
void		ft_getmaxvalues(t_data *data);
int			ft_lastchars(char *line, char *chars);
int			ft_beforewall(char *line);
int			ft_shave(t_data *data);
int			ft_squarise(t_data *data);
void		ft_drawline2(t_compass start, int endx, int endy, t_all *all);
void		ft_setangle(float *angle, char c);
int			ft_loadtextures(t_all *all);
int			ft_initall(t_all *all);
void		ft_freetextures(t_all *all);
void		ft_setangle(float *angle, char c);
void		ft_initplaynew(t_all *all);
void		ft_texture_address(t_all *all);
int			ft_bmp(t_all *all, int *image_count);
void		ft_minimap(t_all *all, int funct);
int			ft_spritevisible(t_all *all, t_sprite *sprite);
void		ft_rendersprite(t_all *all, t_ray *raystruct, int sprite_no);
void		ft_drawsprites(t_sprite *sprite, t_all *all,
			t_ray *raystruct, int sprite_no);
void		ft_minimap_sprite(t_all *all);
void		ft_minimap_player(t_all *all, unsigned int colour);
int			ft_rescheck(int res[2], t_data *data);
int			ft_strcmp(char *s1, char *s2);
int			ft_printerror_int(char *error, int (*array)[3], int no);
int			ft_printerrorfree(char *error, t_data *data);
int			ft_printerror(char *error);
int			ft_rowcounter(char *buffer);
void		ft_freestruct(t_data *data);
int			ft_isdigit(char c);
int			ft_maplen(char *line);
int			ft_rowcounter(char *buffer);
int			ft_isdigit(char c);
int			ft_xpmcheck(char *str);
int			ft_overlap(char **map, int rows);
int			ft_spacebar(char c);
int			ft_colours(t_data *data);
int			ft_border(char **map, int rows);
int			ft_runchecks(t_data *data, int rows);
int			ft_charcheckall(char *str, char c);
char		*ft_line_prep(char **line, char *buffer, t_checks *checks);
int			ft_validmap(char **map, int rows);
void		ft_data_init(t_data *data);
void		ft_printdata(t_data data);
int			ft_charcheck(char *str, char c);
char		**ft_split(const char *s, char c);
int			ft_fillin(char *str, t_data *data);
void		ft_number_builder(int *place, int *i, char c);
int			ft_fullhouse(t_data data);
void		ft_errors_init(t_errors *errors);
int			ft_inputter(t_data *data, char *line);
int			ft_parsemap(char **map, char *line, int index);
int			ft_mlxbuild(t_data data);
float		ft_normalise_ang(float ray_angle);
void		ft_checkhor(t_all all, t_ray *ray);
void		ft_checkvert(t_all all, t_ray *ray);
t_ray		ft_castray(int ray_no, float ray_angle, t_all all);
void		ft_minimap_rays(t_all *all, t_ray *rays);
void		ft_distcheck(t_ray *ray, t_all all);
float		ft_hyp(float a1, float a2, float b1, float b2);
void		ft_initsprite(t_sprite *sprite, int sprite_no);
t_3d		ft_setsprite(t_sprite *sprite, t_all *all);
t_sprite	*ft_sortsprites(int no_sprites, t_sprite *sprites);
int			ft_spritevisible(t_all *all, t_sprite *sprite);
int			ft_spritecount(t_all *all);
t_3d		ft_set3ddata(t_ray ray, t_all all);
void		ft_printcolumn(t_ray ray, t_3d build, t_all *all);
int			ft_close(t_all *all);
int			ft_keystop(int keycode, t_all *all);
int			ft_keys(int keycode, t_all *all);
void		ft_raycaster(t_all *all, t_ray *raystruct);
int			ft_runmapchecks(t_data *data, int rows);
int			spaceline(char *line);
void		ft_initposition(t_all *all);
float		ft_triglen(float ax, float px, float ay, float py);
t_tex		ft_buildtex(t_all *all);

#endif
