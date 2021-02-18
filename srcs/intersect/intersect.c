/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mciupek <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 11:15:01 by mciupek           #+#    #+#             */
/*   Updated: 2021/01/20 12:42:33 by mciupek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"
//#include "minirt.h"

void	init_intersect(t_intersect *i)
{
	i->base = 0;
	i->t = RAY_MAX;
	i->shape = NULL;
}

int	intersect(t_list *shapes, t_intersect *i, int interrupt)
{
	t_shape	*shape;

	while (shapes)
	{
		shape = (t_shape *)shapes->content;
		if (!ft_strncmp(shape->id, "sp", 3))
			intersect_sphere(i, shape);
		else if (!ft_strncmp(shape->id, "pl", 3))
			intersect_plan(i, shape);
		else if (!ft_strncmp(shape->id, "sq", 3))
			intersect_sq(i, shape);
		else if (!ft_strncmp(shape->id, "tr", 3))
			intersect_tr(i, shape);
		else if (!ft_strncmp(shape->id, "cy", 3))
			intersect_cy(i, shape);
		shapes = shapes->next;
		if (interrupt && i->shape)
			return (1);
	}
	return (i->shape != NULL);
}

static t_vect	look_at(t_vect d, t_vect cam_dir)
{
	t_vect	x_axis;
	t_vect	y_axis;
	t_vect	z_axis;
	t_vect	tmp;
	t_vect	rotated;

	init_vect(&tmp, 0, 1, 0);
	z_axis = cam_dir;
	if (cam_dir.y == 1 || cam_dir.y == -1)
		x_axis = (t_vect){cam_dir.y, 0, 0};
	else
		x_axis = crossprod(tmp, z_axis);
	y_axis = crossprod(z_axis, x_axis);
	rotated.x = dotprod(d, x_axis);
	rotated.y = dotprod(d, y_axis);
	rotated.z = dotprod(d, z_axis);
	return (rotated);
}

int	do_intersect(t_params *params, t_px *px)
{
	t_intersect	i;
	t_vect		dir;
	float		x;
	float		y;

	x = (px->x - params->r.x / 2.0) * params->r.x / params->r.y;
	y = (-px->y + params->r.y / 2.0) * params->r.x / params->r.y;
	init_intersect(&i);
	init_vect(&dir, x, y, 1 / (tan(M_PI / 180.0 * params->c.fov / 2))
					* params->r.x / 2);
	dir = look_at(dir, params->c.direction);
	normalize(&dir);
	init_ray(&i.ray, params->c.origin, dir);
	if (intersect(params->shapes, &i, 0))
	{
		set_colors(px, &i, params);
		return (1);
	}
	return (0);
}
