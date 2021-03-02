/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadows.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcciupek <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 18:02:09 by mcciupek          #+#    #+#             */
/*   Updated: 2021/01/11 17:49:21 by mciupek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	get_norm_sp(t_intersect *i)
{
	t_vect	p;

	p = calculate(i->ray, i->t);
	i->n = subs(p, i->shape->p0);
	normalize(&i->n);
}

void	get_norm_pl(t_intersect *i)
{
	i->n = i->shape->n;
	normalize(&i->n);
}

void	get_norm_cy_base_up(t_intersect *i)
{
	i->n = i->shape->n;
	normalize(&i->n);
}

void	get_norm_cy_base_down(t_intersect *i)
{
	i->n = scalprod_v(i->shape->n, -1);
	normalize(&i->n);
}

void	get_norm_cy(t_intersect *i)
{
	t_vect	p;
	t_vect	pt;
	float	t;

	p = calculate(i->ray, i->t);
	t = dotprod(subs(p, i->shape->p0), i->shape->direction);
	pt = add(i->shape->p0, scalprod_v(i->shape->direction, t));
	i->n = normalize_v(subs(p, pt));
}
