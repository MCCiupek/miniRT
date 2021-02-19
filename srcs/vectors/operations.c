/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mciupek <mciupek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 11:19:24 by mciupek           #+#    #+#             */
/*   Updated: 2021/01/20 12:51:22 by mciupek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vect	add(t_vect u, t_vect v)
{
	t_vect	res;

	res.x = u.x + v.x;
	res.y = u.y + v.y;
	res.z = u.z + v.z;
	return (res);
}

t_vect	subs(t_vect u, t_vect v)
{
	t_vect	res;

	res.x = u.x - v.x;
	res.y = u.y - v.y;
	res.z = u.z - v.z;
	return (res);
}

void	normalize(t_vect *v)
{
	scalprod(v, 1 / len3(*v));
}

t_vect	normalize_v(t_vect v)
{
	return (scalprod_v(v, 1 / len3(v)));
}

float	len3(t_vect v)
{
	return (sqrt(pow(v.x, 2) + pow(v.y, 2) + pow(v.z, 2)));
}
