/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mciupek <mciupek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 11:19:24 by mciupek           #+#    #+#             */
/*   Updated: 2021/01/20 12:51:22 by mciupek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"
//#include "minirt.h"

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

int		is_null(t_vect v)
{
	return (v.x == 0 && v.y == 0 && v.z == 0);
}
