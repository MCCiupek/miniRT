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

void    set_norm(t_intersect *i)
{
    if (!i->base)
        i->base = 0;
    if (!ft_strncmp(i->shape->id, "sp", 3))
        get_norm_sp(i);
    else if (!ft_strncmp(i->shape->id, "pl", 3) ||
                !ft_strncmp(i->shape->id, "sq", 3) ||
                !ft_strncmp(i->shape->id, "tr", 3))
        get_norm_pl(i);
    else if (!ft_strncmp(i->shape->id, "cy", 3) && i->base == 1)
        get_norm_cy_base_up(i);
    else if (!ft_strncmp(i->shape->id, "cy", 3) && i->base == -1)
        get_norm_cy_base_down(i);
    else if (!ft_strncmp(i->shape->id, "cy", 3))
        get_norm_cy(i);
}

int     is_lit(t_intersect *i, t_params *params, t_light light,
                                                    t_vect light_dir)
{
    t_intersect i2;

    init_intersect(&i2);
    init_ray(&i2.ray, calculate(i->ray, i->t), normalize_v(light_dir));
    if (intersect(params->shapes, &i2, 0))
        if (len3(subs(light.origin, i2.ray.origin)) >
            len3(subs(calculate(i2.ray, i2.t), i2.ray.origin)))
            return (0);
    return (1);
}

float   get_specular(
	t_intersect *i, t_light *light, t_vect light_dir, double angle)
{
	t_vect	rev_dir;
	t_vect	reflect;
	float	coef;

	coef = 0;
	rev_dir = scalprod_v(i->ray.direction, -1);
	reflect = subs(scalprod_v(i->n, 2 * angle), normalize_v(light_dir));
	if (dotprod(reflect, rev_dir) > 0.0)
		coef = light->light * pow(dotprod(reflect, rev_dir) /
                    (len3(reflect) * len3(rev_dir)), GAMMA);
	return (coef);
}

t_color light_color(t_intersect *i, t_params *params)
{
    float       l;
    t_color     l_col;
    t_vect      spot;
    t_list      *lights;
    t_light     light;

    init_colors(&l_col, 0, 0, 0);
    mix_colors(&l_col, params->al.light, params->al.colors);
    lights = params->lights;
    while (lights)
	{
		light = *(t_light *)lights->content;
        spot = subs(light.origin, calculate(i->ray, i->t));
        set_norm(i);
        if (dotprod(i->n, spot) > 0 && is_lit(i, params, light, spot))
        {
            l = light.light * dotprod(i->n, spot) / (len3(i->n) * len3(spot));
            mix_colors(&l_col, l, light.colors);
            l = get_specular(i, &light, spot, dotprod(i->n, normalize_v(spot)));
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
