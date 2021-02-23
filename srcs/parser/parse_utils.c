/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mciupek <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 14:40:39 by mciupek           #+#    #+#             */
/*   Updated: 2021/02/11 12:00:45 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	init_rgb(char **tab, t_shape *s)
{
	char	**rgb;

	rgb = NULL;
	rgb = ft_split(tab[ft_tabsize(tab) - 1], ',');
	if (check_col(rgb))
		return (ft_free(rgb) + COLOR_FMT);
	init_colors(&s->colors, ft_atof(rgb[0]), ft_atof(rgb[1]), ft_atof(rgb[2]));
	return (ft_free(rgb));
}

int	is_num(char *s, int is_float, int is_neg)
{
	int	cpt_minus;
	int	cpt_dot;
	int	i;

	cpt_minus = 0;
	cpt_dot = 0;
	i = -1;
	while (s[++i])
		if (!ft_isdigit(s[i]))
		{
			if (s[i] == '.')
			{
				if (!is_float || cpt_dot++)
					return (0);
				break ;
			}
			if (s[i] == '-')
			{
				if (!is_neg || cpt_minus++)
					return (0);
				break ;
			}
			return (0);
		}
	return (1);
}

int	check_col(char **rgb)
{
	if (!rgb[0] || !rgb[1] || !rgb[2]
		|| ft_tabsize(rgb) != 3 || !is_num(rgb[0], 1, 0)
		|| !is_num(rgb[1], 1, 0) || !is_num(rgb[2], 1, 0))
		return (COLOR_FMT);
	if (ft_atof(rgb[0]) != limit(ft_atof(rgb[0]), 0, 255) ||
		ft_atof(rgb[1]) != limit(ft_atof(rgb[1]), 0, 255)
		|| ft_atof(rgb[2]) != limit(ft_atof(rgb[2]), 0, 255))
		return (COLOR_FMT);
	return (0);
}

int	check_coord(char **coord)
{
	if (ft_tabsize(coord) != 3 || !coord[0] || !coord[1] || !coord[2]
		|| !is_num(coord[0], 1, 1) || !is_num(coord[1], 1, 1)
		|| !is_num(coord[2], 1, 1))
		return (COORD_FMT);
	return (0);
}
