/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mciupek <mciupek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 14:28:07 by mciupek           #+#    #+#             */
/*   Updated: 2021/01/20 12:49:44 by mciupek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	c_limit(t_color *c)
{
	c->r = limit(c->r, 0, 255);
	c->g = limit(c->g, 0, 255);
	c->b = limit(c->b, 0, 255);
}

void	init_colors(t_color *c, float r, float g, float b)
{
	c->r = r;
	c->g = g;
	c->b = b;
	c_limit(c);
}

int		rgb(float r, float g, float b)
{
	return ((((int)r & 0x0ff) << 16)
		| (((int)g & 0x0ff) << 8)
		| ((int)b & 0x0ff));
}

void	mix_colors(t_color *c, float coef, t_color colors)
{
	c->r += coef * colors.r / 255;
	c->g += coef * colors.g / 255;
	c->b += coef * colors.b / 255;
}

t_color	color_x_light(t_color color, t_color rgb)
{
	t_color	res;

	res.r = fmin(color.r * rgb.r, 255);
	res.g = fmin(color.g * rgb.g, 255);
	res.b = fmin(color.b * rgb.b, 255);
	return (res);
}
