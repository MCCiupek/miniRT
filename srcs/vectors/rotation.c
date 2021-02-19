/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mciupek <mciupek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 15:17:06 by mciupek           #+#    #+#             */
/*   Updated: 2021/01/19 15:20:56 by mciupek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	rx(t_vect *vect, float x)
{
	t_vect	tmp;

	tmp.x = vect->x;
	tmp.y = vect->y * cos(x) - vect->z * sin(x);
	tmp.z = vect->y * sin(x) + vect->z * cos(x);
	*vect = tmp;
}

void	ry(t_vect *vect, float y)
{
	t_vect	tmp;

	tmp.x = vect->x * cos(y) + vect->z * sin(y);
	tmp.y = vect->y;
	tmp.z = vect->x * -sin(y) + vect->z * cos(y);
	*vect = tmp;
}

void	rz(t_vect *vect, float z)
{
	t_vect	tmp;

	tmp.x = vect->x * cos(z) - vect->y * sin(z);
	tmp.y = vect->x * sin(z) + vect->y * cos(z);
	tmp.z = vect->z;
	*vect = tmp;
}

void	rotate(t_vect *vect, t_vect *angle)
{
	rx(vect, angle->x);
	ry(vect, angle->y);
	rz(vect, angle->z);
}

void	anti_rot(t_vect *vect, t_vect *angle)
{
	rz(vect, -angle->z);
	ry(vect, -angle->y);
	rx(vect, -angle->x);
}
