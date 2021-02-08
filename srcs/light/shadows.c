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
/*float next_rand(int s) 
{
    s = (1664525u * s + 1013904223u);
    return (s&0x00FFFFFF / 0x01000000);
}

float   get_alpha(t_light light, t_vect position)
{
    t_vect up;
    t_vect to_light;
    t_vect n;
    t_vect to_light_edge;

    init_vect(&up, 0, 1.0, 0);
    to_light = normalize_v(subs(light.origin, position));
    n = crossprod(to_light, up);
    if (is_null(n))
        n.x = 1.0;
    to_light_edge = normalize_v(subs(add(light.origin, scalprod_v(n, light.light)), position));
    return (acos(dotprod(to_light, to_light_edge)) * 2.0);
}

t_vect angle_axis(float angle, t_vect axis, t_vect v) 
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
    return((t_vect) {-dotprod(r[0], v), -dotprod(r[1], v), -dotprod(r[2], v)});
}

t_vect  get_direction(t_vect direction, float alpha)
{
    float   phi;
    float   angle;
    t_vect  v;
    t_vect  north;
    t_vect  axis;

    v.z = next_rand(1) * (1.0 - cos(alpha)) + cos(alpha);
    phi = next_rand(1) * 2.0 * PI;
    v.x = sqrt(1.0 - v.z * v.z) * cos(phi);
    v.y = sqrt(1.0 - v.z * v.z) * sin(phi);
    init_vect(&north, 0, 0, 1);
    axis = normalize_v(crossprod(north, normalize_v(direction)));
    angle = acos(dotprod(normalize_v(direction), north));
    //scalprod(&axis, angle);
    //rotate(&v, &axis);
    //return(scalprod_v(v, -1));
    return(angle_axis(angle, axis, v));
}*/