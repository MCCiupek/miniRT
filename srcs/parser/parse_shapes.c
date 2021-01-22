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

static int	ft_tabsize(char **tab)
{
	int	size;

	size = 0;
	while (tab[size])
		size++;
	return (size);
}

void	init_sh(t_shape	*s, char **tab)
{
	char	**coord;
	char	**rgb;

	if (!s)
	{
		printf("Error\n");
		return ;
	}
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
		s->d = ft_atof(tab[2]);
	if (!ft_strncmp(s->id, "cy", 3))
	{
		s->d = ft_atof(tab[4]);
		s->h = ft_atof(tab[5]);
	}
	if (!ft_strncmp(s->id, "sq", 3))
		s->h = ft_atof(tab[3]);
	if (!ft_strncmp(s->id, "pl", 2) || !ft_strncmp(s->id, "sq", 3) || !ft_strncmp(s->id, "cy", 3))
	{
		free(coord);
		coord = ft_split(tab[2], ',');
		init_vect(&s->direction, ft_atof(coord[0]), ft_atof(coord[1]), ft_atof(coord[2]));
	}	
	init_colors(&s->colors, ft_atoi(rgb[0]), ft_atoi(rgb[1]), ft_atoi(rgb[2]));
	ft_free(coord);
	ft_free(rgb);
}
