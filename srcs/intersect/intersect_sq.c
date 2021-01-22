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

t_vect	get_norm_sq(t_shape *square)
{
	t_vect	p[3];
	t_vect	n;

	init_vect(&p[0], - square->h / 2, - square->h / 2, 0);	//a
	init_vect(&p[1], square->h / 2, - square->h, 0);	//b
	init_vect(&p[2], - square->h / 2, square->h, 0);	//c
	rotate(&p[0], &square->direction);
	rotate(&p[1], &square->direction);
	rotate(&p[2], &square->direction);
	p[0] = add(p[0], square->p0);				//A
	p[1] = add(p[1], square->p0);				//B
	p[2] = add(p[2], square->p0);				//C
	square->sides[0] = subs(p[1], p[0]);			//AB
	square->sides[1] = subs(p[2], p[0]);			//AC
	n = crossprod(square->sides[0], square->sides[1]);
	return (n);
}

int	intersect_sq(t_intersect *i, t_shape *sq)
{
	float t;
	t_vect	v;
	float	proj[2];

	sq->n = get_norm_sq(sq);	//copy(sq->direction);
	t = t_inter_plan(i, sq);
	if (t <= RAY_MIN || t >= i->t)
		return (0);
	v = subs(calculate(i->ray, t), sq->p0);
	normalize(&sq->sides[0]);
	normalize(&sq->sides[1]);
	proj[0] = dotprod(v, sq->sides[0]);
	proj[1] = dotprod(v, sq->sides[1]);
	if ((proj[0] <= sq->h && proj[0] >= 0) && 
		(proj[1] <= sq->h && proj[1] >= 0))  
	{
		i->t = t;
		i->shape = sq;
		return (1);
	}
	return (0);
}