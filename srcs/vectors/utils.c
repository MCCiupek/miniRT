/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mciupek <mciupek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 15:17:06 by mciupek           #+#    #+#             */
/*   Updated: 2021/01/19 15:20:56 by mciupek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		ft_tabsize(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

float	limit(float n, float min, float max)
{
	return (fmax(min, fmin(n, max)));
}

int		v_limit(t_vect *v, float min, float max)
{
	if (v->x != limit(v->x, min, max) || v->y != limit(v->y, min, max)
		|| v->z != limit(v->z, min, max))
		return (1);
	return (0);
}
