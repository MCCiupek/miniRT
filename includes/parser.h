/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mciupek <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 14:51:12 by mciupek           #+#    #+#             */
/*   Updated: 2021/01/11 17:50:00 by mciupek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

typedef struct	s_resol
{
	int	x;
	int	y;
}				t_resol;

typedef struct	s_alight
{
	float	light;
	t_color	colors;
}				t_alight;

typedef struct	s_light
{
	t_vect	origin;
	float	light;
	t_color	colors;
}				t_light;

typedef	struct	s_cam
{
	t_vect	origin;
	t_vect	direction;
	float	fov;
}				t_cam;

typedef	struct	s_shapeslist
{
	t_shape *shape;
	t_shape	*next;
}				t_shapeslist;

typedef struct	s_params
{
	t_resol			r;
	t_alight		al;
	t_light			l;
	t_cam			c;
	t_shapeslist		shapes;
}				t_params;

void	init_resol(t_resol	*r, char **tab);
void	init_alight(t_alight	*al, char **tab);
void	init_light(t_light	*l, char **tab);
void	init_cam(t_cam	*c, char **tab);
void	parse(char *line, t_params *params);
int	gnl(int argc, char **argv, t_params *params);

#endif
