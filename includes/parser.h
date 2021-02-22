/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mciupek <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 14:51:12 by mciupek           #+#    #+#             */
/*   Updated: 2021/01/13 14:24:36 by mciupek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "minirt.h"

typedef struct	s_resol
{
	int	x_max;
	int	y_max;
	int	x;
	int	y;
	int	count;
}				t_resol;

typedef struct	s_alight
{
	float	light;
	t_color	colors;
	int		count;
}				t_alight;

typedef struct	s_light
{
	t_vect	origin;
	float	light;
	t_color	colors;
}				t_light;

typedef struct	s_cam
{
	t_vect	origin;
	t_vect	direction;
	float	fov;
}				t_cam;

typedef struct	s_shape
{
	char	id[3];
	t_vect	p0;
	t_vect	p1;
	t_vect	p2;
	t_vect	direction;
	t_vect	n;
	t_vect	sides[2];
	float	h;
	float	d;
	t_color	colors;
}				t_shape;

typedef struct	s_params
{
	t_resol		r;
	t_alight	al;
	t_light		l;
	t_cam		c;
	t_list		*shapes;
	t_list		*cams;
	t_list		*lights;
}				t_params;

int				is_num(char *s, int is_float, int is_neg);
void			check_col(char **rgb, char *line, t_params *params);
void			check_coord(char **coord, char *line, t_params *params);
void			init_rgb(char **tab, t_shape *s, char *line, t_params *params);
void			init_resol(t_params *params, char **tab, char *line);
void			init_alight(t_params *params, char **tab, char *line);
void			init_light(t_light *l, char **tab, char *line, t_params *params);
void			init_cam(t_cam	*c, char **tab, char *line, t_params *params);
void			init_sh(t_shape	*s, char **tab, char *line, t_params *params);
void			init_obj_lst(t_params *params, void *(*f)(void *, char **tab, char *line, t_params *params),
							void *obj, char **tab, char *line);
void			parse(char *line, t_params *params);
int				gnl(int argc, char **argv, t_params *params);

#endif
