/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mciupek <mciupek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 14:28:07 by mciupek           #+#    #+#             */
/*   Updated: 2021/01/20 12:49:44 by mciupek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"
//#include "minirt.h"

void    free_lsts(t_params *params)
{
    ft_lstiter(params->shapes, (void *)free);
	ft_lstiter(params->cams, (void *)free);
	ft_lstiter(params->lights, (void *)free);
}

void    error(int err)
{
	ft_putstr_fd("Error :\n", 1);
	if (err == 1)
		ft_putstr_fd(ERR_1, 1);
	else if (err == 2)
		ft_putstr_fd(ERR_2, 1);
	else if (err == 3)
		ft_putstr_fd(ERR_3, 1);
	else if (err == 4)
		ft_putstr_fd(ERR_4, 1);
    else if (err == 5)
		ft_putstr_fd(ERR_5, 1);
	else
		ft_putstr_fd(ERR, 1);
	exit(EXIT_SUCCESS);
}
