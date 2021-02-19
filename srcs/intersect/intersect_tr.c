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

t_vect	get_norm_tr(t_shape *tr)
{
	t_vect	n;
	t_vect	e1;
	t_vect	e2;

	e1 = subs(tr->p1, tr->p0);
	e2 = subs(tr->p2, tr->p0);
	n = crossprod(e1, e2);
	normalize(&n);
	return (n);
}

int		intersect_tr(t_intersect *i, t_shape *tr)
{
	float	t;
	t_vect	p;
	t_vect	e[3];
	t_vect	c[3];

	tr->n = get_norm_tr(tr);
	t = t_inter_plan(i, tr);
	if (t <= RAY_MIN || t >= i->t)
		return (0);
	e[0] = subs(tr->p1, tr->p0);
	e[1] = subs(tr->p2, tr->p1);
	e[2] = subs(tr->p0, tr->p2);
	p = calculate(i->ray, t);
	c[0] = subs(p, tr->p0);
	c[1] = subs(p, tr->p1);
	c[2] = subs(p, tr->p2);
	if (dotprod(tr->n, crossprod(e[0], c[0])) > 0
		&& dotprod(tr->n, crossprod(e[1], c[1])) > 0
		&& dotprod(tr->n, crossprod(e[2], c[2])) > 0)
	{
		i->t = t;
		i->shape = tr;
		return (1);
	}
	return (0);
}
