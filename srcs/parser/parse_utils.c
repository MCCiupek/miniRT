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

void	init_rgb(char **rgb, char **tab, t_shape *s)
{
	rgb = ft_split(tab[ft_tabsize(tab) - 1], ',');
	check_col(rgb);
	init_colors(&s->colors, ft_atof(rgb[0]), ft_atof(rgb[1]), ft_atof(rgb[2]));
	ft_free(rgb);
}

int		is_num(char *s, int is_float, int is_neg)
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
		}
	return (1);
}

void	check_col(char **rgb)
{
	if (!rgb[0] || !rgb[1] || !rgb[2] || !is_num(rgb[0], 1, 0)
		|| !is_num(rgb[1], 1, 0) || !is_num(rgb[2], 1, 0))
	{
		ft_free(rgb);
		error(COLOR_FMT);
	}
}

void	check_coord(char **coord)
{
	if (!coord[0] || !coord[1] || !coord[2] || !is_num(coord[0], 1, 1)
		|| !is_num(coord[1], 1, 1) || !is_num(coord[2], 1, 1))
	{
		ft_free(coord);
		error(COORD_FMT);
	}
}
