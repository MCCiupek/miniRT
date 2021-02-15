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

static void	split_and_init(char **dest, char *src, t_vect *vec, int free_dest)
{
	if (free_dest)
		ft_free(dest);
	dest = ft_split(src, ',');
	init_vect(vec, ft_atof(dest[0]), ft_atof(dest[1]), ft_atof(dest[2]));
	ft_free(dest);
}

void		init_tr(char **coord, char **tab, t_shape *s)
{
	split_and_init(coord, tab[2], &s->p1, 0);
	split_and_init(coord, tab[3], &s->p2, 0);
}

void		init_cy(char **tab, t_shape *s)
{
	s->d = fabs(ft_atof(tab[3]));
	s->h = fabs(ft_atof(tab[4]));
}

void		init_rgb(char **rgb, char **tab, t_shape *s)
{
	rgb = ft_split(tab[ft_tabsize(tab) - 1], ',');
	init_colors(&s->colors, ft_atof(rgb[0]), ft_atof(rgb[1]), ft_atof(rgb[2]));
	ft_free(rgb);
}

void		init_sh(t_shape *s, char **tab)
{
	char	**coord;
	char	**rgb;

	if (!s)
		error(5);
	ft_strlcpy(s->id, tab[0], 3);
	coord = NULL;
	rgb = NULL;
	init_rgb(rgb, tab, s);
	split_and_init(coord, tab[1], &s->p0, 0);
	if (!ft_strncmp(s->id, "tr", 3))
		init_tr(coord, tab, s);
	if (!ft_strncmp(s->id, "sp", 3))
		s->d = fabs(ft_atof(tab[2]));
	if (!ft_strncmp(s->id, "cy", 3))
		init_cy(tab, s);
	if (!ft_strncmp(s->id, "sq", 3))
		s->h = fabs(ft_atof(tab[3]));
	if (!ft_strncmp(s->id, "pl", 2) || !ft_strncmp(s->id, "sq", 3) ||
					!ft_strncmp(s->id, "cy", 3))
	{
		split_and_init(coord, tab[2], &s->direction, 0);
		v_limit(&s->direction, -1.0, 1.0);
	}
	//free(coord);
}
