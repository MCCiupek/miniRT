/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mciupek <mciupek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 14:23:28 by mciupek           #+#    #+#             */
/*   Updated: 2021/01/19 09:22:39 by mciupek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISPLAY_H
# define DISPLAY_H

# include "minirt.h"

typedef struct	s_color
{
	int	r;
	int	g;
	int b;
}				t_color;

typedef struct	s_px
{
	int	x;
	int	y;
	t_color	col;
}				t_px;

void			init_colors(t_color *c, int r, int g, int b);
int				rgb(int r, int g, int b);

# endif