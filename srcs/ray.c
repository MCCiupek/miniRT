/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mciupek <mciupek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 14:28:07 by mciupek           #+#    #+#             */
/*   Updated: 2021/01/19 12:59:25 by mciupek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"
#include "vectors.h"
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

void	init_colors(t_color *c, int r, int g, int b)
{
	c->r = r;
	c->g = g;
	c->b = b;
}

void	init_ray(t_ray *r, t_vect origin, t_vect dir)
{
	r->origin = origin;
	r->direction = dir;
	r->tmax = RAY_MAX;
}

void	init_intersect(t_intersect *i)
{
	i->t = RAY_MAX;
	i->shape = NULL;
}

t_vect	calculate(t_ray r, float t)
{
	scalprod(&r.direction, t);
	r.origin.x += r.direction.x;
	r.origin.y += r.direction.y;
	r.origin.z += r.direction.z;
	return (r.origin);
}

t_vect	ft_position(t_intersect i)
{
	return (calculate(i.ray, i.t));
}

int	intersect_plan(t_intersect *i, t_shape *plan)
{
	float dn;
	float t;
	t_vect	n;

	n = copy(plan->direction);
	dn = dotprod(i->ray.direction, n);
	if (!dn)
		return (0);
	t = dotprod(subs(plan->p0, i->ray.origin), n) / dn;
	if (t <= RAY_MIN || t >= i->t)
		return (0);
	i->t = t;
	i->shape = plan;
	return (1);
}

float	resolve_eq(float a, float b, float c)
{
	float delta;
	float x1;
	float x2;

	delta = pow(b, 2) - 4 * a * c;
	if (delta < 0)
		return (-1);
	x1 = (-b - sqrt(delta)) / (2 * a);	
	x2 = (-b + sqrt(delta)) / (2 * a);
	if (x1 > x2)
		return (x2);
	return (x1);
}

int	intersect_sphere(t_intersect *i, t_shape *sphere)
{
	t_ray	r;
	float	t;
	t_vect	p;
	t_vect	d;

	r = i->ray;
	d = r.direction;
	p = subs(r.origin, sphere->p0);
	t = resolve_eq(pow(len3(d), 2), 2 * dotprod(d, p), pow(len3(p), 2) - pow(sphere->d / 2, 2));
	if (t <= RAY_MIN || t >= i->t)
		return (0);
	i->t = t;
	i->shape = sphere;
	return (1);
}

int	get_norm_sq(t_shape *square)
{
	t_vect	sides[3];

	init_vect(&sides[0], square->h / 2, square->h / 2, 0);
	init_vect(&sides[0], - square->h / 2, square->h / 2, 0);
	init_vect(&sides[0], square->h / 2, - square->h / 2, 0);

	return (0);
}

int	intersect_sq(t_intersect *i, t_shape *sq)
{
	return (1);
}
