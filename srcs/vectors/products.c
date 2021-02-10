/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mciupek <mciupek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 11:19:24 by mciupek           #+#    #+#             */
/*   Updated: 2021/01/20 12:51:22 by mciupek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"
//#include "minirt.h"

void	scalprod(t_vect *v, float n)
{
	v->x *= n;
	v->y *= n;
	v->z *= n;
}

t_vect	scalprod_v(t_vect v, float n)
{
	t_vect	res;

	res.x = v.x * n;
	res.y = v.y * n;
	res.z = v.z * n;
	return (res);
}

float	dotprod(t_vect u, t_vect v)
{
	return (u.x * v.x + u.y * v.y + u.z * v.z);
}

t_vect	crossprod(t_vect u, t_vect v)
{
	t_vect	res;

	res.x = u.y * v.z - u.z * v.y;
	res.y = u.z * v.x - u.x * v.z;
	res.z = u.x * v.y - u.y * v.x;
	return (res);
}
