/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_cy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mciupek <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 11:15:01 by mciupek           #+#    #+#             */
/*   Updated: 2021/01/20 12:42:33 by mciupek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static float	resolve_eq2(float a, float b, float c)
{
	float	delta;
	float	x1;
	float	x2;

	delta = pow(b, 2) - 4 * a * c;
	if (delta < 0)
		return (RAY_MAX);
	x1 = (-b - sqrt(delta)) / (2 * a);
	x2 = (-b + sqrt(delta)) / (2 * a);
	if (x1 < 0)
		x1 = RAY_MAX;
	if (x2 < 0)
		x2 = RAY_MAX;
	if (x1 < x2)
		return (x2);
	return (x1);
}

static void		fill_tab(t_vect v[], t_intersect *i, t_shape *cy, float y[])
{
	y[0] = resolve_eq(dotprod(v[0], v[0]), 2 * dotprod(v[0], v[1]),
			dotprod(v[1], v[1]) - pow(cy->d / 2, 2));
	y[1] = resolve_eq2(dotprod(v[0], v[0]), 2 * dotprod(v[0], v[1]),
			dotprod(v[1], v[1]) - pow(cy->d / 2, 2));
	y[2] = dotprod(cy->direction, subs(scalprod_v(i->ray.direction, y[0]),
				subs(cy->p0, i->ray.origin)));
	y[3] = dotprod(cy->direction, subs(scalprod_v(i->ray.direction, y[1]),
				subs(cy->p0, i->ray.origin)));
}

int				intersect_cy(t_intersect *i, t_shape *cy)
{
	t_vect	v[2];
	float	y[4];

	normalize(&cy->direction);
	v[0] = scalprod_v(cy->direction, dotprod(i->ray.direction, cy->direction));
	v[0] = subs(i->ray.direction, v[0]);
	v[1] = scalprod_v(cy->direction, dotprod(subs(i->ray.origin, cy->p0),
				cy->direction));
	v[1] = subs(subs(i->ray.origin, cy->p0), v[1]);
	fill_tab(v, i, cy, y);
	if (y[3] < cy->h && y[3] > RAY_MIN && y[1] >= RAY_MIN && y[1] < i->t)
	{
		i->t = y[1];
		i->shape = cy;
	}
	if (y[2] < cy->h && y[2] > RAY_MIN && y[0] >= RAY_MIN && y[0] < i->t)
	{
		i->t = y[0];
		i->shape = cy;
	}
	return (i->shape != NULL);
}
