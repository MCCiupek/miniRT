/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mciupek <mciupek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 13:13:33 by mciupek           #+#    #+#             */
/*   Updated: 2021/01/19 10:04:44 by mciupek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H

# include "vectors.h"

# define RAY_MIN 0.0001
# define RAY_MAX 1.0e30

typedef struct	s_ray
{
	t_vect	origin;
	t_vect	direction;
	float	tmax;
}				t_ray;

typedef struct	s_color
{
	int	r;
	int	g;
	int b;
}				t_color;

typedef struct	s_shape
{
	char	id[3];
	t_vect	p0;
	t_vect	p1;
	t_vect	p2;
	t_vect	direction;
	float		h;
	float		d;
	t_color		colors;
}				t_shape;

typedef struct	s_intersect
{
	t_ray	ray;
	float	t;
	t_shape	*shape;
}				t_intersect;

void			init_colors(t_color *c, int r, int g, int b);
void			init_ray(t_ray *r, t_vect origin, t_vect destination);
void			init_intersect(t_intersect *i);
t_vect			calculate(t_ray r, float t);
t_vect			ft_position(t_intersect i);
float			resolve_eq(float a, float b, float c);
int				intersect_plan(t_intersect *i, t_shape *plan);
int				intersect_sphere(t_intersect *i, t_shape *sphere);


#endif
