/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mciupek <mciupek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 11:07:45 by mciupek           #+#    #+#             */
/*   Updated: 2021/01/20 12:51:37 by mciupek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTORS_H
# define VECTORS_H

# include "minirt.h"

typedef struct	s_vect
{
	float	x;
	float	y;
	float	z;
}				t_vect;

void	init_vect(t_vect *v, float x, float y, float z);
void	init_vect_c(t_vect *v, float c);
void	init_vect_p(t_vect *v, t_vect *p1, t_vect *p2);
t_vect	copy(t_vect v);
float	len3(t_vect v);
void	scalprod(t_vect *v, float n);
t_vect	scalprod_v(t_vect v, float n);
t_vect	add(t_vect u, t_vect v);
t_vect	subs(t_vect u, t_vect v);
float	dotprod(t_vect u, t_vect v);
t_vect	crossprod(t_vect u, t_vect v);
void	normalize(t_vect *v);
t_vect	normalize_v(t_vect v);
int		is_null(t_vect v);

#endif
