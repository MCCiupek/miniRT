/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mciupek <mciupek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 15:21:51 by mciupek           #+#    #+#             */
/*   Updated: 2021/01/19 15:23:52 by mciupek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROTATION_H
# define ROTATION_H

# include "minirt.h"

void	rx(t_vect *vect, float x);
void	ry(t_vect *vect, float y);
void	rz(t_vect *vect, float z);
void	rotate(t_vect *vect, t_vect *angle);
void	anti_rot(t_vect *vect, t_vect *angle);

#endif
