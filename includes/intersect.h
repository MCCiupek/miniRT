/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mciupek <mciupek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 13:13:33 by mciupek           #+#    #+#             */
/*   Updated: 2021/01/20 12:42:08 by mciupek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERSECT_H
# define INTERSECT_H

# include "ray.h"
# include "parser.h"
# include "minirt.h"

typedef struct	s_intersect
{
	t_ray	ray;
	float	t;
	t_shape	*shape;
    t_vect  n;
}				t_intersect;

void			init_intersect(t_intersect *i);
float	        t_inter_plan(t_intersect *i, t_shape *shape);
int				intersect_plan(t_intersect *i, t_shape *plan);
int				intersect_sphere(t_intersect *i, t_shape *sphere);
int				intersect_sq(t_intersect *i, t_shape *sq);
int				intersect_tr(t_intersect *i, t_shape *tr);
int				intersect_cy(t_intersect *i, t_shape *cy);
t_vect			ft_position(t_intersect i);
float			resolve_eq(float a, float b, float c);
int             do_intersect(t_params *params, t_px *px);
int             intersect(t_list *shapes, t_intersect *i);

# endif