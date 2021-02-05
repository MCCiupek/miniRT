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
	int	x;
	int	y;
}				t_resol;

typedef struct	s_alight
{
	float	light;
	t_color	colors;
}				t_alight;

typedef struct	s_light
{
	t_vect	origin;
	float	light;
	t_color	colors;
}				t_light;

typedef	struct	s_cam
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

float	limit(float n, float min, float max);
void	v_limit(t_vect *v, float min, float max);
int		ft_tabsize(char **tab);
void	ft_free(char **tab);
void	init_resol(t_resol *r, char **tab);
void	init_alight(t_alight *al, char **tab);
void	init_light(t_light *l, char **tab);
void	init_cam(t_cam	*c, char **tab);
void	init_sh(t_shape	*s, char **tab);
void	parse(char *line, t_params *params);
int		gnl(int argc, char **argv, t_params *params);

#endif
