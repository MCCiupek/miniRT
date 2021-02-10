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

#include "../../includes/minirt.h"
//#include "minirt.h"

void    get_norm_sp(t_intersect *i)
{
    t_vect  p;

    p = calculate(i->ray, i->t);
    i->n = subs(p, i->shape->p0);
    normalize(&i->n);
}

void    get_norm_pl(t_intersect *i)
{
    i->n = i->shape->n;
    normalize(&i->n);
}

void    get_norm_cy_base_up(t_intersect *i)
{
    i->n = i->shape->n;
    normalize(&i->n);
}

void    get_norm_cy_base_down(t_intersect *i)
{
    i->n = scalprod_v(i->shape->n, -1);
    normalize(&i->n);
}

void    get_norm_cy(t_intersect *i)
{
    t_vect base_tmp;
    t_vect intersection_tmp;

    base_tmp = copy(i->shape->p0);
    intersection_tmp = copy(i->ray.direction);
    anti_rot(&intersection_tmp, &i->shape->direction);
    base_tmp.y = intersection_tmp.y;
    rotate(&intersection_tmp, &i->shape->direction);
    rotate(&base_tmp, &i->shape->direction);
    init_vect(&i->n, i->ray.direction.x - base_tmp.x,
                    i->ray.direction.y - base_tmp.y,
                    i->ray.direction.z - base_tmp.z);
    normalize(&i->n);
}
