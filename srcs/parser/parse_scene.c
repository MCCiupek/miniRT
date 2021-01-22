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

void	init_resol(t_resol	*r, char  **tab)
{
	r->x = ft_atoi(tab[1]);
	r->y = ft_atoi(tab[2]);
}

void	init_alight(t_alight	*al, char  **tab)
{
	char	**rgb;

	al->light = ft_atof(tab[1]);
	rgb = ft_split(tab[2], ',');
	init_colors(&al->colors, ft_atoi(rgb[0]), ft_atoi(rgb[1]), ft_atoi(rgb[2]));
	ft_free(rgb);
}

void	init_cam(t_cam	*c, char  **tab)
{
	char	**coord;
	char	**vect;

	coord = ft_split(tab[1], ',');
	vect = ft_split(tab[2], ',');
	init_vect(&c->origin, ft_atof(coord[0]), ft_atof(coord[1]), ft_atof(coord[2]));
	init_vect(&c->direction, ft_atoi(vect[0]), ft_atoi(vect[1]), ft_atoi(vect[2]));
	c->fov = ft_atof(tab[3]);
	ft_free(coord);
	ft_free(vect);
}

void	init_light(t_light *l, char **tab)
{
	char	**coord;
	char	**rgb;

	coord = ft_split(tab[1], ',');
	rgb = ft_split(tab[3], ',');
	init_vect(&l->origin, ft_atof(coord[0]), ft_atof(coord[1]), ft_atof(coord[2]));
	l->light = ft_atof(tab[2]);
	init_colors(&l->colors, ft_atoi(rgb[0]), ft_atoi(rgb[1]), ft_atoi(rgb[2]));
	ft_free(coord);
	ft_free(rgb);
}
