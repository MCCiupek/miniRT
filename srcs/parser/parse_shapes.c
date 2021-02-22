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

static void	split_and_init(char *src, t_vect *vec, char *line, t_params *params)
{
	char	**coord;

	coord = NULL;
	coord = ft_split(src, ',');
	check_coord(coord, line, params);
	init_vect(vec, ft_atof(coord[0]), ft_atof(coord[1]), ft_atof(coord[2]));
	ft_free(coord);
}

void		init_tr(char **tab, t_shape *s, char *line, t_params *params)
{
	char	**coord;

	coord = NULL;
	if (ft_tabsize(tab) != 5)
		error(TR_FMT, tab, line, params);
	split_and_init(tab[2], &s->p1, line, params);
	split_and_init(tab[3], &s->p2, line, params);
}

void		init_cy(char **tab, t_shape *s, char *line, t_params *params)
{
	if (ft_tabsize(tab) != 6 || !is_num(tab[3], 1, 0) || !is_num(tab[4], 1, 0))
		error(CYL_FMT, tab, line, params);
	s->d = fabs(ft_atof(tab[3]));
	s->h = fabs(ft_atof(tab[4]));
}

void		check_shapes(t_shape *s, char **tab, char *line, t_params *params)
{
	if (!ft_strncmp(s->id, "sp", 3)
		&& (ft_tabsize(tab) != 4 || !is_num(tab[2], 1, 0)))
		error(SPHERE_FMT, tab, line, params);
	if (!ft_strncmp(s->id, "pl", 3) && ft_tabsize(tab) != 4)
		error(PLANE_FMT, tab, line, params);
	if (!ft_strncmp(s->id, "sq", 3)
		&& (ft_tabsize(tab) != 5 || !is_num(tab[3], 1, 0)))
		error(SQUARE_FMT, tab, line, params);
}

void		init_sh(t_shape *s, char **tab, char *line, t_params *params)
{
	if (!s)
		error(MEM_ERR, tab, line, params);
	ft_strlcpy(s->id, tab[0], 3);
	check_shapes(s, tab, line, params);
	init_rgb(tab, s, line, params);
	split_and_init(tab[1], &s->p0, line, params);
	if (!ft_strncmp(s->id, "tr", 3))
		init_tr(tab, s, line, params);
	if (!ft_strncmp(s->id, "sp", 3))
		s->d = fabs(ft_atof(tab[2]));
	if (!ft_strncmp(s->id, "cy", 3))
		init_cy(tab, s, line, params);
	if (!ft_strncmp(s->id, "sq", 3))
		s->h = fabs(ft_atof(tab[3]));
	if (!ft_strncmp(s->id, "pl", 2) || !ft_strncmp(s->id, "sq", 3)
		|| !ft_strncmp(s->id, "cy", 3))
	{
		split_and_init(tab[2], &s->direction, line, params);
		if (v_limit(&s->direction, -1.0, 1.0))
			error(COORD_FMT, tab, line, params);
	}
}
