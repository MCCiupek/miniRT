/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mciupek <mciupek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 11:07:45 by mciupek           #+#    #+#             */
/*   Updated: 2021/01/08 13:11:35 by mciupek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTORS_H
# define VECTORS_H

# include <math.h>

typedef struct s_point
{
	int	x;
	int	y;
}			t_point;

typedef struct s_vect
{
	int	x;
	int	y;
	int	z;
}			t_vect;

void	init_point(t_point *p, int x, int y);
void	init_vect(t_vect *v, int x, int y, int z);
t_vect	copy(t_vect v);
int	len3(t_vect v);
void	scalprod(t_vect *v, int n);
t_vect	add(t_vect u, t_vect v);
int	dotprod(t_vect u, t_vect v);
t_vect	crossprod(t_vect u, t_vect v);
void	normalize(t_vect *v);

#endif
