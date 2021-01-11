/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mciupek <mciupek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 11:19:24 by mciupek           #+#    #+#             */
/*   Updated: 2021/01/08 13:11:39 by mciupek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vectors.h"

void	init_point(t_point *p, int x, int y);
{
	p->x = x;
	p->y = y;
}

void	init_vect(t_vect *v, int x, int y, int z)
{
	v->x = x;
	v->y = y;
	v->z = z;
}

t_vect	copy(t_vect v)
{
	t_vect	res;

	res.x = v.x;
	res.y = v.y;
	res.z = v.z;
	return (res);
}

int	len3(t_vect v)
{
	return (sqrt(pow(v.x, 2) + pow(v.y, 2) + pow(v.z, 2)));
}

void	scalprod(t_vect *v, int n)
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

int	dotprod(t_vect u, t_vect v)
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
	scalprod(v, 1 / len3(v));
}
