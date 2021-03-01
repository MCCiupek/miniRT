/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_pl.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mciupek <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 11:15:01 by mciupek           #+#    #+#             */
/*   Updated: 2021/01/20 12:42:33 by mciupek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

float	t_inter_plan(t_intersect *i, t_shape *shape)
{
	float	dn;
	float	t;

	dn = dotprod(i->ray.direction, shape->n);
	if (!dn)
		return (RAY_MAX);
	t = dotprod(subs(shape->p0, i->ray.origin), shape->n) / dn;
	return (t);
}

int		intersect_plan(t_intersect *i, t_shape *plan)
{
	float	t;

	plan->n = normalize_v(copy(plan->direction));
	t = t_inter_plan(i, plan);
	if (t <= RAY_MIN || t >= i->t)
		return (0);
	i->t = t;
	i->shape = plan;
	return (1);
}
