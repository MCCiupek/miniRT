/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mciupek <mciupek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 14:23:28 by mciupek           #+#    #+#             */
/*   Updated: 2021/01/19 09:22:39 by mciupek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLORS_H
# define COLORS_H

# include "minirt.h"

typedef struct	s_color
{
	float	r;
	float   g;
	float   b;
}				t_color;

typedef struct	s_px
{
	int	    x;
	int     y;
	t_color	col;
}				t_px;


void			init_colors(t_color *c, float r, float g, float b);
void			mix_colors(t_color *c, float coef, t_color colors);
t_color			color_x_light(t_color color, t_color rgb);
int				rgb(float r, float g, float b);
void    		switch_cam();

#endif
