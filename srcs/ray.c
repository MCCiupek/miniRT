/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mciupek <mciupek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 14:28:07 by mciupek           #+#    #+#             */
/*   Updated: 2021/01/12 12:50:34 by mciupek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"
#include "vectors.h"
#include <math.h>
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

int	intersect(t_intersect i)
{
	return (!i.shape);
}

int	intersect_plan(t_intersect i, t_shape *plan)
{
	float dn;
	float t;
	t_vect	n;

	init_vect(&n, 1, 1, 1);
	dn = dotprod(i.ray.direction, n);
	if (!dn)
		return (0);
	t = dotprod(subs(plan->p0, i.ray.origin), n) / dn;
	if (t <= RAY_MIN || t >= i.t)
		return (0);
	i.t = t;
	i.shape = plan;
	return (1);
}

float	resolve_eq(float a, float b, float c)
{
	float delta;
	float x1;
	float x2;

	printf("a = %f\nb = %f\nc = %f\n", a, b, c);
	delta = pow(b, 2) - 4 * a * c;
	if (delta < 0)
		return (-1);
	x1 = (-b - sqrt(delta)) / (2 * a);	
	x2 = (-b + sqrt(delta)) / (2 * a);
	if (x1 > x2)
		return x2;
	return (x1);
}

int	intersect_sphere(t_intersect *i, t_shape sphere)
{
	t_ray	r;
	float	t;
	t_vect	p;
	t_vect	d;

	r = i->ray;
	r.origin.x -= sphere.p0.x;
	r.origin.y -= sphere.p0.y;
	r.origin.z -= sphere.p0.z;
	printf("z : %f\n", sphere.p0.z);
	d = r.direction;
	p = r.origin;
	t = resolve_eq(pow(len3(d), 2), 2 * dotprod(d, p), pow(len3(p), 2) - pow(sphere.d / 2, 2));
	if (t <= RAY_MIN || t >= i->t)
		return (0);
	i->t = t;
	i->shape = &sphere;
	return (1);
}
