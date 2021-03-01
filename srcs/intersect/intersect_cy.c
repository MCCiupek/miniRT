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

float	inter_cy_base(t_intersect *i, t_shape *cy, int pl)
{
	t_vect	tmp;
	t_vect	dist;
	t_vect	p;
	float	t;

	cy->n = copy(cy->direction);
	tmp = cy->p0;
	if (pl)
		cy->p0 = add(cy->p0, scalprod_v(cy->direction, cy->h));
	t = t_inter_plan(i, cy);
	p = calculate(i->ray, t);
	init_vect_p(&dist, &p, &cy->p0);
	cy->p0 = tmp;
	if (len3(dist) >= cy->d / 2 || t < CY_RAY_MIN || t >= i->t)
		return (RAY_MAX);
	i->t = t;
	i->shape = cy;
	if (pl)
		i->base = 1;
	if (!pl)
		i->base = -1;
	return (1);
}

int		intersect_cy(t_intersect *i, t_shape *cy)
{
	t_vect	v[2];
	float	y[2];

	normalize(&cy->direction);
	v[0] = scalprod_v(cy->direction, dotprod(i->ray.direction, cy->direction));
	v[0] = subs(i->ray.direction, v[0]);
	v[1] = scalprod_v(cy->direction, dotprod(subs(i->ray.origin, cy->p0),
				cy->direction));
	v[1] = subs(subs(i->ray.origin, cy->p0), v[1]);
	y[0] = resolve_eq(dotprod(v[0], v[0]), 2 * dotprod(v[0], v[1]),
			dotprod(v[1], v[1]) - pow(cy->d / 2, 2));
	y[1] = dotprod(cy->direction, subs(scalprod_v(i->ray.direction, y[0]),
				subs(cy->p0, i->ray.origin)));
	if (y[1] >= cy->h || y[1] <= CY_RAY_MIN)
	{
		inter_cy_base(i, cy, 0);
		inter_cy_base(i, cy, 1);
		y[0] = RAY_MAX;
	}
	if (y[0] >= CY_RAY_MIN && y[0] < i->t)
	{
		i->t = y[0];
		i->shape = cy;
	}
	return (i->shape != NULL);
}
