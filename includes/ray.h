/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mciupek <mciupek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 13:13:33 by mciupek           #+#    #+#             */
/*   Updated: 2021/01/20 12:42:08 by mciupek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H

# include "minirt.h"

typedef struct	s_ray
{
	t_vect	origin;
	t_vect	direction;
	float	tmax;
}				t_ray;

void			init_ray(t_ray *r, t_vect origin, t_vect destination);
t_vect			calculate(t_ray r, float t);

#endif
