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

#include "../includes/minirt.h"
//#include "minirt.h"

void	init_colors(t_color *c, int r, int g, int b)
{
	c->r = r;
	c->g = g;
	c->b = b;
}

int	rgb(int r, int g, int b)
{
	return (((r&0x0ff)<<16)|((g&0x0ff)<<8)|(b&0x0ff));
}