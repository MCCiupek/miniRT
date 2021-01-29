/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcciupek <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 18:02:09 by mcciupek          #+#    #+#             */
/*   Updated: 2021/01/11 17:49:21 by mciupek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIGHT_H
# define LIGHT_H

# include "minirt.h"

void    get_norm_sp(t_intersect *i);
void    get_norm_pl(t_intersect *i);
void    get_norm_cy(t_intersect *i);
void    get_norm_cy_base_up(t_intersect *i);
void    get_norm_cy_base_down(t_intersect *i);
void    get_i_norm(t_intersect *i);
float   light(t_intersect *i, t_params *params);
void    set_colors(t_px *px, t_intersect *i, t_params *params);
void    set_shadow(t_px *px, float l);
float   get_alpha(t_light light, t_vect position);
float   nextRand(int s);
t_vect  angleAxis3x3(float angle, t_vect axis, t_vect v);
t_vect  get_direction(t_vect direction, float alpha);
//void    get_shadows(t_px *px, t_intersect *i, t_params *params);

# endif