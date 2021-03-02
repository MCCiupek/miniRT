/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_sq.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mciupek <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 11:15:01 by mciupek           #+#    #+#             */
/*   Updated: 2021/01/20 12:42:33 by mciupek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static int	is_inside_square(t_shape *square, t_vect p)
{
	t_vect	dist;
	t_vect	tmp;
	t_vect	e[2];
	float	d[2];
	float	border;

	init_vect(&tmp, 0, 1, 0);
	dist = subs(p, square->p0);
	border = square->h / 2;
	if (fabs(square->n.y) == 1)
		e[0] = (t_vect){square->n.y, 0, 0};
	else
		e[0] = crossprod(tmp, square->n);
	e[1] = crossprod(square->n, e[0]);
	d[0] = dotprod(dist, normalize_v(e[0]));
	d[1] = dotprod(dist, normalize_v(e[1]));
	return (fabs(d[0]) <= border && fabs(d[1]) <= border);
}

int			intersect_sq(t_intersect *i, t_shape *sq)
{
	float	t;
	t_vect	p;

	sq->n = copy(sq->direction);
	t = t_inter_plan(i, sq);
	if (t <= RAY_MIN || t >= i->t)
		return (0);
	p = calculate(i->ray, t);
	if (is_inside_square(sq, p))
	{
		i->t = t;
		i->shape = sq;
		return (1);
	}
	return (0);
}
