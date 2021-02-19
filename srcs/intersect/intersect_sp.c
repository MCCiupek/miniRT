/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mciupek <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 11:15:01 by mciupek           #+#    #+#             */
/*   Updated: 2021/01/20 12:42:33 by mciupek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

float	resolve_eq(float a, float b, float c)
{
	float	delta;
	float	x1;
	float	x2;

	delta = pow(b, 2) - 4 * a * c;
	if (delta < 0)
		return (RAY_MAX);
	x1 = (-b - sqrt(delta)) / (2 * a);
	x2 = (-b + sqrt(delta)) / (2 * a);
	if (x1 > x2)
		return (x2);
	return (x1);
}

int		intersect_sphere(t_intersect *i, t_shape *sphere)
{
	t_ray	r;
	float	t;
	t_vect	p;
	t_vect	d;

	r = i->ray;
	d = r.direction;
	p = subs(r.origin, sphere->p0);
	t = resolve_eq(pow(len3(d), 2), 2 * dotprod(d, p),
			pow(len3(p), 2) - pow(sphere->d / 2, 2));
	if (t <= RAY_MIN || t >= i->t)
		return (0);
	i->t = t;
	i->shape = sphere;
	return (1);
}
