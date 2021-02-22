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

static void	split_and_init(char **dest, char *src, t_vect *vec)
{
	dest = ft_split(src, ',');
	check_coord(dest);
	init_vect(vec, ft_atof(dest[0]), ft_atof(dest[1]), ft_atof(dest[2]));
	ft_free(dest);
}

void		init_tr(char **coord, char **tab, t_shape *s)
{
	if (ft_tabsize(tab) != 5)
		error(TR_FMT, tab);
	split_and_init(coord, tab[2], &s->p1);
	split_and_init(coord, tab[3], &s->p2);
}

void		init_cy(char **tab, t_shape *s)
{
	if (ft_tabsize(tab) != 6 || !is_num(tab[3], 1, 0) || !is_num(tab[4], 1, 0))
		error(CYL_FMT, tab);
	s->d = fabs(ft_atof(tab[3]));
	s->h = fabs(ft_atof(tab[4]));
}

void		check_shapes(t_shape *s, char **tab)
{
	if (!ft_strncmp(s->id, "sp", 3)
		&& (ft_tabsize(tab) != 4 || !is_num(tab[2], 1, 0)))
		error(SPHERE_FMT, tab);
	if (!ft_strncmp(s->id, "pl", 3) && ft_tabsize(tab) != 4)
		error(PLANE_FMT, tab);
	if (!ft_strncmp(s->id, "sq", 3)
		&& (ft_tabsize(tab) != 5 || !is_num(tab[3], 1, 0)))
		error(SQUARE_FMT, tab);
}

void		init_sh(t_shape *s, char **tab)
{
	char	**coord;
	char	**rgb;

	if (!s)
		error(MEM_ERR, tab);
	ft_strlcpy(s->id, tab[0], 3);
	coord = NULL;
	rgb = NULL;
	check_shapes(s, tab);
	init_rgb(rgb, tab, s);
	split_and_init(coord, tab[1], &s->p0);
	if (!ft_strncmp(s->id, "tr", 3))
		init_tr(coord, tab, s);
	if (!ft_strncmp(s->id, "sp", 3))
		s->d = fabs(ft_atof(tab[2]));
	if (!ft_strncmp(s->id, "cy", 3))
		init_cy(tab, s);
	if (!ft_strncmp(s->id, "sq", 3))
		s->h = fabs(ft_atof(tab[3]));
	if (!ft_strncmp(s->id, "pl", 2) || !ft_strncmp(s->id, "sq", 3)
		|| !ft_strncmp(s->id, "cy", 3))
	{
		split_and_init(coord, tab[2], &s->direction);
		v_limit(&s->direction, -1.0, 1.0);
	}
}
