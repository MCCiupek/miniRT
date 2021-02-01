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
    else if (!ft_strncmp(i->shape->id, "pl", 3) || !ft_strncmp(i->shape->id, "sq", 3) || !ft_strncmp(i->shape->id, "tr", 3))
        get_norm_pl(i);
    else if (!ft_strncmp(i->shape->id, "cy", 3) && i->base == 1)
        get_norm_cy_base_up(i);
    else if (!ft_strncmp(i->shape->id, "cy", 3) && i->base == -1)
        get_norm_cy_base_down(i);
    else if (!ft_strncmp(i->shape->id, "cy", 3))
        get_norm_cy(i);
}

t_color  intensity(t_color c, float l)
{
    c.r *= l;
    c.g *= l;
    c.b *= l;
    return (c);
}

t_color  add_colors(t_color c1, t_color c2)
{
    c1.r += c2.r;
    c1.g += c2.r;
    c1.b += c2.r;
    return (c1);
}

t_color  mult_colors(t_color c1, t_color c2)
{
    c1.r *= c2.r;
    c1.g *= c2.r;
    c1.b *= c2.r;
    return (c1);
}

int    is_lit(t_intersect *i, t_params *params, t_light light)
{
    float       alpha;
    t_intersect i2;

    alpha = get_alpha(light, calculate(i->ray, i->t));//i->ray.origin);
    //printf("alpha = %f\n", alpha);
    init_intersect(&i2);
    init_ray(&i2.ray, calculate(i->ray, i->t), normalize_v(get_direction(i->ray.direction, alpha)));
    if (intersect(params->shapes, &i2, 0))
        if (len3(subs(light.origin, i2.ray.origin)) > len3(subs(calculate(i2.ray, i2.t), i2.ray.origin)))
            return (0);
    return (1);
}

t_color   light_color(t_intersect *i, t_params *params)
{
    float       l;
    t_color     l_col;
    t_vect      spot;
    t_list      *lights;
    t_light     light;

    l = params->al.light;
    init_colors(&l_col, 0, 0, 0);
    mix_colors(&l_col, l, params->al.colors);
    lights = params->lights;
    while (lights)
	{
		light = *(t_light *)lights->content;
        spot = subs(light.origin, calculate(i->ray, i->t));
        set_norm(i);
        if (dotprod(i->n, spot) > 0 && is_lit(i, params, light))
        {
            l = light.light * dotprod(i->n, spot) / (len3(i->n) * len3(spot));
            mix_colors(&l_col, l, light.colors);
        }
        lights = lights->next;
    }
    return (l_col);
}

void    set_colors(t_px *px, t_intersect *i, t_params *params)
{
    t_color     l;

    l = light_color(i, params);
    px->col = color_x_light(l, i->shape->colors);
}

void    set_shadow(t_px *px, float l)
{
    px->col.r *= l;
    px->col.g *= l;
    px->col.b *= l;
}