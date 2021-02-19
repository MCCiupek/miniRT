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

static int	is_inside_square(t_shape *square, t_vect p)
{
	t_vect	dist;
	float	border;

	dist = subs(p, square->p0);
	border = square->h / 2;
	return (
		(fabs(dist.x) <= border)
		&& (fabs(dist.y) <= border)
		&& (fabs(dist.z) <= border));
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
