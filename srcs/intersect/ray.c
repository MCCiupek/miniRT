/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mciupek <mciupek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 14:28:07 by mciupek           #+#    #+#             */
/*   Updated: 2021/01/20 12:49:44 by mciupek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"
//#include "minirt.h"

void	init_ray(t_ray *r, t_vect origin, t_vect dir)
{
	r->origin = origin;
	r->direction = dir;
	r->tmax = RAY_MAX;
}

t_vect	calculate(t_ray r, float t)
{
	scalprod(&r.direction, t);
	r.origin.x += r.direction.x;
	r.origin.y += r.direction.y;
	r.origin.z += r.direction.z;
	return (r.origin);
}

t_vect	ft_position(t_intersect i)
{
	return (calculate(i.ray, i.t));
}