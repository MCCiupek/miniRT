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

static int	split_and_init(char *src, t_vect *vec)
{
	char	**coord;

	coord = NULL;
	coord = ft_split(src, ',');
	if (check_coord(coord))
		return (ft_free(coord) + COORD_FMT);
	init_vect(vec, ft_atof(coord[0]), ft_atof(coord[1]), ft_atof(coord[2]));
	return (ft_free(coord));
}

int			init_tr(char **tab, t_shape *s)
{
	char	**coord;

	coord = NULL;
	if (ft_tabsize(tab) != 5)
		return (TR_FMT);
	if (split_and_init(tab[2], &s->p1)
		|| split_and_init(tab[3], &s->p2))
		return (COORD_FMT);
	return (0);
}

int			init_cy(char **tab, t_shape *s)
{
	if (ft_tabsize(tab) != 6 || !is_num(tab[3], 1, 0) || !is_num(tab[4], 1, 0))
		return (CYL_FMT);
	s->d = fabs(ft_atof(tab[3]));
	s->h = fabs(ft_atof(tab[4]));
	return (0);
}

int			check_shapes(t_shape *s, char **tab)
{
	if (!ft_strncmp(s->id, "sp", 3)
		&& (ft_tabsize(tab) != 4 || !is_num(tab[2], 1, 0)))
		return (SPHERE_FMT);
	if (!ft_strncmp(s->id, "pl", 3) && ft_tabsize(tab) != 4)
		return (PLANE_FMT);
	if (!ft_strncmp(s->id, "sq", 3)
		&& (ft_tabsize(tab) != 5 || !is_num(tab[3], 1, 0)))
		return (SQUARE_FMT);
	return (0);
}

int			init_sh(t_shape *s, char **tab)
{
	int	err;

	if (!s)
		return (MEM_ERR);
	ft_strlcpy(s->id, tab[0], 3);
	if ((err = check_shapes(s, tab)))
		return (err);
	if (init_rgb(tab, s))
		return (COLOR_FMT);
	if (split_and_init(tab[1], &s->p0))
		return (COORD_FMT);
	if (!ft_strncmp(s->id, "tr", 3))
		err = init_tr(tab, s);
	if (!ft_strncmp(s->id, "sp", 3))
		s->d = fabs(ft_atof(tab[2]));
	if (!ft_strncmp(s->id, "cy", 3))
		err = init_cy(tab, s);
	if (!ft_strncmp(s->id, "sq", 3))
		s->h = fabs(ft_atof(tab[3]));
	if (!ft_strncmp(s->id, "pl", 2) || !ft_strncmp(s->id, "sq", 3)
		|| !ft_strncmp(s->id, "cy", 3))
		if (split_and_init(tab[2], &s->direction)
			|| v_limit(&s->direction, -1, 1))
			return (COORD_FMT);
	return (0 + err);
}
