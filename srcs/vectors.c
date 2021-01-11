/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mciupek <mciupek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 11:19:24 by mciupek           #+#    #+#             */
/*   Updated: 2021/01/11 14:21:13 by mciupek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vectors.h"

/*void	init_point(t_point *p, int x, int y, int z);
{
	p->x = x;
	p->y = y;
	p->z = z;
}

t_vect add_p(t_point u, t_point v)
{
	t_point	res;

	res.x = u.x + v.x;
	res.y = u.y + v.y;
	res.z = u.z + v.z;
	return (res);
}

t_vect subs_p(t_point u, t_point v)
{
	t_point	res;

	res.x = u.x - v.x;
	res.y = u.y - v.y;
	res.z = u.z - v.z;
	return (res);
}
*/

void	init_vect(t_vect *v, float x, float y, float z)
{
	v->x = x;
	v->y = y;
	v->z = z;
}

void	init_vect_c(t_vect *v, float c)
{
	v->x = c;
	v->y = c;
	v->z = c;
}

void	init_vect_p(t_vect *v, t_vect *p1, t_vect *p2)
{
	v->x = p2->x - p1->x;
	v->y = p2->y - p1->y;
	v->z = p2->z - p1->z;
}

t_vect	copy(t_vect v)
{
	t_vect	res;

	res.x = v.x;
	res.y = v.y;
	res.z = v.z;
	return (res);
}

float		len3(t_vect v)
{
	return (sqrt(pow(v.x, 2) + pow(v.y, 2) + pow(v.z, 2)));
}

void	scalprod(t_vect *v, float n)
{
	v->x *= n;
	v->y *= n;
	v->z *= n;
}

t_vect add(t_vect u, t_vect v)
{
	t_vect	res;

	res.x = u.x + v.x;
	res.y = u.y + v.y;
	res.z = u.z + v.z;
	return (res);
}

t_vect subs(t_vect u, t_vect v)
{
	t_vect	res;

	res.x = u.x - v.x;
	res.y = u.y - v.y;
	res.z = u.z - v.z;
	return (res);
}

float		dotprod(t_vect u, t_vect v)
{
	return (u.x * v.x + u.y * v.y + u.z + v.z);
}

t_vect	crossprod(t_vect u, t_vect v)
{
	t_vect	res;

	res.x = u.y * v.z - u.z * v.y;
	res.y = u.z * v.x - u.x * v.z;
	res.z = u.x * v.y - u.y * v.x;
	return (res);
}

void	normalize(t_vect *v)
{
	scalprod(v, 1 / len3(*v));
}
