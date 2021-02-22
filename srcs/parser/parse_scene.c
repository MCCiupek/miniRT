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

#include "minirt.h"

void	init_resol(t_resol *r, char **tab)
{
	if (ft_tabsize(tab) != 3 || !tab[1] || !tab[2] || !is_num(tab[1], 0, 0)
		|| !is_num(tab[2], 0, 0) || ft_atoi(tab[1]) < 1 || ft_atoi(tab[2]) < 1)
		error(RES_FMT, tab);
	r->x = ft_atoi(tab[1]);
	r->y = ft_atoi(tab[2]);
	r->count++;
}

void	init_alight(t_alight *al, char **tab)
{
	char	**rgb;

	if (ft_tabsize(tab) != 3 || !tab[1] || !tab[2] || !is_num(tab[1], 1, 0))
		error(AMB_FMT, tab);
	al->light = limit(ft_atof(tab[1]), 0.0, 1.0);
	rgb = ft_split(tab[2], ',');
	check_col(rgb);
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

	if (ft_tabsize(tab) != 4 || !tab[1] || !tab[2] || !tab[3]
		|| !is_num(tab[3], 1, 0) || ft_atof(tab[3]) > 180.0)
		error(CAM_FMT, tab);
	coord = ft_split(tab[1], ',');
	vect = ft_split(tab[2], ',');
	check_coord(coord);
	check_coord(vect);
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

	if (ft_tabsize(tab) != 4 || !tab[1] || !tab[2] || !tab[3]
		|| !is_num(tab[2], 1, 0))
		error(LIGHT_FMT, tab);
	coord = ft_split(tab[1], ',');
	rgb = ft_split(tab[3], ',');
	check_col(rgb);
	check_coord(coord);
	init_vect(&l->origin,
		ft_atof(coord[0]),
		ft_atof(coord[1]),
		ft_atof(coord[2]));
	l->light = limit(ft_atof(tab[2]), 0.0, 1.0);
	init_colors(&l->colors,
		limit(ft_atof(rgb[0]), 0, 255),
		limit(ft_atof(rgb[1]), 0, 255),
		limit(ft_atof(rgb[2]), 0, 255));
	ft_free(coord);
	ft_free(rgb);
}
