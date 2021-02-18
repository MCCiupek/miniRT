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

void	init_resol(t_resol *r, char **tab)
{
	r->x = ft_atoi(tab[1]);
	r->y = ft_atoi(tab[2]);
	r->count++;
}

void	init_alight(t_alight *al, char **tab)
{
	char	**rgb;

	al->light = limit(ft_atof(tab[1]), 0.0, 1.0);
	rgb = ft_split(tab[2], ',');
	init_colors(&al->colors,
		limit(ft_atof(rgb[0]), 0, 255),
		limit(ft_atof(rgb[1]), 0, 255),
		limit(ft_atof(rgb[2]), 0, 255));
	ft_free(rgb);
	al->count++;
}

void	init_cam(t_cam *c, char **tab)
{
	char	**coord;
	char	**vect;

	coord = ft_split(tab[1], ',');
	vect = ft_split(tab[2], ',');
	init_vect(&c->origin,
		ft_atof(coord[0]),
		ft_atof(coord[1]),
		ft_atof(coord[2]));
	init_vect(&c->direction,
		limit(ft_atof(vect[0]), -1.0, 1.0),
		limit(ft_atof(vect[1]), -1.0, 1.0),
		limit(ft_atof(vect[2]), -1.0, 1.0));
	c->fov = limit(ft_atof(tab[3]), 0.0, 180.0);
	ft_free(coord);
	ft_free(vect);
}

void	init_light(t_light *l, char **tab)
{
	char	**coord;
	char	**rgb;

	coord = ft_split(tab[1], ',');
	rgb = ft_split(tab[3], ',');
	init_vect(&l->origin,
		ft_atof(coord[0]),
		ft_atof(coord[1]),
		ft_atof(coord[2]));
	l->light = ft_atof(tab[2]);
	init_colors(&l->colors,
		limit(ft_atof(rgb[0]), 0, 255),
		limit(ft_atof(rgb[1]), 0, 255),
		limit(ft_atof(rgb[2]), 0, 255));
	ft_free(coord);
	ft_free(rgb);
}
