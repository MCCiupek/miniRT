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

#include "../../includes/minirt.h"
//#include "minirt.h"

float	inter_cy_base(t_intersect *i, t_shape *cy, int pl)
{
	t_vect	tmp;
    t_vect  dist;
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
    if (len3(dist) > cy->d / 2 || t < RAY_MIN || t >= i->t)
        return (RAY_MAX);
	i->t = t;
	i->shape = cy;
	if (pl)
		ft_strlcpy(i->shape->id, "cu", 3);
	if (!pl)
		ft_strlcpy(i->shape->id, "cd", 3);
	return (1);
}

int		intersect_cy(t_intersect *i, t_shape *cy)
{
	t_vect	p;
	t_vect	d;
	float	t;
	float	y;

	d = scalprod_v(cy->direction, dotprod(i->ray.direction, cy->direction));
    d = subs(i->ray.direction, d);
    p = scalprod_v(cy->direction, dotprod(subs(i->ray.origin, cy->p0), cy->direction));
    p = subs(subs(i->ray.origin, cy->p0), p);
    t = resolve_eq(dotprod(d, d), 2 * dotprod(d, p), dotprod(p, p) - pow(cy->d / 2, 2));
	y = dotprod(cy->direction, subs(scalprod_v(i->ray.direction, t), subs(cy->p0, i->ray.origin)));
	if (t >= RAY_MIN && t < i->t && y < cy->h && y > 0)
	{
		i->t = t;
		i->shape = cy;
	}
	inter_cy_base(i, cy, 0);
	inter_cy_base(i, cy, 1);
	return (i->shape != NULL);
}