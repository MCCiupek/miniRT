/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
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

void    set_norm(t_intersect *i)
{
    if (!ft_strncmp(i->shape->id, "sp", 3))
        get_norm_sp(i);
    if (!ft_strncmp(i->shape->id, "pl", 3) || !ft_strncmp(i->shape->id, "sq", 3) || !ft_strncmp(i->shape->id, "tr", 3))
        get_norm_pl(i);
    if (!ft_strncmp(i->shape->id, "cu", 3))
        get_norm_cy_base_up(i);
    if (!ft_strncmp(i->shape->id, "cd", 3))
        get_norm_cy_base_down(i);
    if (!ft_strncmp(i->shape->id, "cb", 3))
        get_norm_cy(i);
}

float   light(t_intersect *i, t_params *params)
{
    float   l;
    t_vect  spot;
    t_list  *lights;
    t_light light;

    l = params->al.light;
    lights = params->lights;
    while (lights)
	{
		light = *(t_light *)lights->content;
        spot = subs(light.origin, calculate(i->ray, i->t));
        set_norm(i);
        if (dotprod(i->n, spot) > 0)
            l += light.light * dotprod(i->n, spot) / (len3(i->n) * len3(spot));
        lights = lights->next;
    }
    return (l);
}

void    set_colors(t_px *px, t_intersect *i, t_params *params)
{
    float   l;

    l = light(i, params);
    px->col.r = i->shape->colors.r * l;
    px->col.g = i->shape->colors.g * l;
    px->col.b = i->shape->colors.b * l;
}

void    set_shadow(t_px *px)
{
    px->col.r = 0;
    px->col.g = 0;
    px->col.b = 0;
}