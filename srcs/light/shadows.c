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

float nextRand(int s) 
{
    s = (1664525u * s + 1013904223u);
    return (s&0x00FFFFFF / 0x01000000);
}

float   get_alpha(t_light light, t_vect position)
{
    t_vect up;
    t_vect pl;
    t_vect n;
    t_vect pe;

    init_vect(&up, 0, 1, 0);
    pl = normalize_v(subs(light.origin, position));
    n = crossprod(pl, up);
    if (is_null(n))
        n.x = 1.0;
    pe = normalize_v(subs(add(light.origin, scalprod_v(pl, light.light)), position));
    return (acos(dotprod(pl, pe)) * 2.0f);
}

t_vect angleAxis3x3(float angle, t_vect axis, t_vect v) 
{
    t_vect  r[3];
    float   t;
    
    t = 1 - cos(angle);
    init_vect(&r[0], t * axis.x * axis.x + cos(angle), 
                        t * axis.x * axis.y - sin(angle) * axis.z, 
                        t * axis.x * axis.z + sin(angle) * axis.y);
    init_vect(&r[1], t * axis.x * axis.y + sin(angle) * axis.z,  
                        t * axis.y * axis.y + cos(angle),
                        t * axis.y * axis.z - sin(angle) * axis.x);
    init_vect(&r[2], t * axis.x * axis.z - sin(angle) * axis.y,
                        t * axis.y * axis.z + sin(angle) * axis.x,
                        t * axis.z * axis.z + cos(angle));
    return((t_vect) {dotprod(r[0], v), dotprod(r[1], v), dotprod(r[2], v)});
}

t_vect  get_direction(t_vect direction, float alpha)
{
    float   phi;
    float   angle;
    t_vect  v;
    t_vect  north;
    t_vect  axis;

    v.z = nextRand(1) * (1.0f - cos(alpha)) + cos(alpha);
    phi = nextRand(1) * 2.0f * PI;
    v.x = sqrt(1.0f - v.z * v.z) * cos(phi);
    v.y = sqrt(1.0f - v.z * v.z) * sin(phi);
    init_vect(&north, 0, 0, 1);
    axis = normalize_v(crossprod(north, normalize_v(direction)));
    angle = acos(dotprod(normalize_v(direction), north));
    return(angleAxis3x3(angle, axis, v));
}

void    get_shadows(t_px *px, t_intersect *i, t_params *params)
{
    float       alpha;
    t_intersect i2;
    t_list  *lights;
    t_light light;

    lights = params->lights;
    while (lights)
    {
        light = *(t_light *)lights->content;
        alpha = get_alpha(light, i->ray.origin);
        init_intersect(&i2);
        init_ray(&i2.ray, calculate(i->ray, i->t), get_direction(i->ray.direction, alpha));
        if (intersect(params->shapes, &i2, 1))
            set_shadow(px);
        lights = lights->next;
    }
}