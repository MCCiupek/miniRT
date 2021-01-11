/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mciupek <mciupek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 11:07:45 by mciupek           #+#    #+#             */
/*   Updated: 2021/01/11 12:37:24 by mciupek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTORS_H
# define VECTORS_H

# include <math.h>

/*typedef struct s_point
{
	int	x;
	int	y;
	int z;
}				t_point;
*/
typedef struct s_vect
{
	float	x;
	float	y;
	float	z;
}				t_vect;

//void	init_point(t_point *p, int x, int y, int z);
//t_point	add_p(t_point u, t_point v);
//t_point	subs_p(t_point u, t_point v);
void	init_vect(t_vect *v, float x, float y, float z);
void	init_vect_c(t_vect *v, float c);
void	init_vect_p(t_vect *v, t_vect *p1, t_vect *p2);
t_vect	copy(t_vect v);
float		len3(t_vect v);
void	scalprod(t_vect *v, float n);
t_vect	add(t_vect u, t_vect v);
t_vect	subs(t_vect u, t_vect v);
float		dotprod(t_vect u, t_vect v);
t_vect	crossprod(t_vect u, t_vect v);
void	normalize(t_vect *v);

#endif
