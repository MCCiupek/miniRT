/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mciupek <mciupek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 13:13:33 by mciupek           #+#    #+#             */
/*   Updated: 2021/01/08 17:25:30 by mciupek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H

# include "vectors.h"

# define RAY_MIN 0.0001
# define RAY_MAX 1.0e30

typedef struct	s_ray
{
	t_point	origin;
	t_vect	direction;
	float	tmax;
}			t_ray;

typedef struct	s_shape
{
	char	str[2];
	t_point	p0;
	t_point	p1;
	t_point	p2;
	t_vect	direction;
	int	h
	int	d;
	int	colors[3];
}			t_shape;

typedef struct	s_intersect
{
	t_ray	ray;
	float	t;
	t_shape	*shape;
	int	(*intersect)(t_intersect *i);
}			t_intersect;

#endif
