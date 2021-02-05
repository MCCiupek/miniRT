/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mciupek <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 14:40:39 by mciupek           #+#    #+#             */
/*   Updated: 2021/01/18 17:46:56 by mciupek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"
//#include "minirt.h"

float	limit(float n, float min, float max)
{
	return(fmax(min, fmin(n, max)));
}

void	v_limit(t_vect *v, float min, float max)
{
	v->x = limit(v->x, min, max);
	v->y = limit(v->y, min, max);
	v->z = limit(v->z, min, max);
}

void	c_limit(t_color *c)
{
	c->r = limit(c->r, 0, 255);
	c->g = limit(c->g, 0, 255);
	c->b = limit(c->b, 0, 255);
}

void	init_sh(t_shape	*s, char **tab)
{
	char	**coord;
	char	**rgb;

	if (!s)
		exit(4);
	ft_strlcpy(s->id, tab[0], 3);
	coord = ft_split(tab[1], ',');
	rgb = ft_split(tab[ft_tabsize(tab) - 1], ',');
	init_vect(&s->p0, ft_atof(coord[0]), ft_atof(coord[1]), ft_atof(coord[2]));
	if (!ft_strncmp(s->id, "tr", 3))
	{
		free(coord);
		coord = ft_split(tab[2], ',');
		init_vect(&s->p1, ft_atof(coord[0]), ft_atof(coord[1]), ft_atof(coord[2]));
		free(coord);
		coord = ft_split(tab[3], ',');
		init_vect(&s->p2, ft_atof(coord[0]), ft_atof(coord[1]), ft_atof(coord[2]));
	}
	if (!ft_strncmp(s->id, "sp", 3))
		s->d = fabs(ft_atof(tab[2]));
	if (!ft_strncmp(s->id, "cy", 3))
	{
		s->d = fabs(ft_atof(tab[3]));
		s->h = fabs(ft_atof(tab[4]));
	}
	if (!ft_strncmp(s->id, "sq", 3))
		s->h = fabs(ft_atof(tab[3]));
	if (!ft_strncmp(s->id, "pl", 2) || !ft_strncmp(s->id, "sq", 3) || !ft_strncmp(s->id, "cy", 3))
	{
		free(coord);
		coord = ft_split(tab[2], ',');
		init_vect(&s->direction, ft_atof(coord[0]), ft_atof(coord[1]), ft_atof(coord[2]));
		v_limit(&s->direction, -1.0, 1.0);
	}	
	init_colors(&s->colors, ft_atof(rgb[0]), ft_atof(rgb[1]), ft_atof(rgb[2]));
	c_limit(&s->colors);
	ft_free(coord);
	ft_free(rgb);
}
