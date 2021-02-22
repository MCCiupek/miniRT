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

#include "minirt.h"

#ifdef MACOS
void	mlx_detroy_display(void *mlx)
{
	(void)mlx;
}

int		mlx_get_screen_size(void *mlx, int *x_max, int *y_max)
{
	(void)mlx;
	*x_max = RES_X_MAX;
	*y_max = RES_Y_MAX;
	return (0);
}
#endif

void	get_screen_size(t_mlx mlx, t_params *params)
{
	if (OS == 2)
		mlx_get_screen_size(mlx.mlx, &params->r.x_max, &params->r.y_max);
	else if (OS == 1)
		mlx_get_screen_size(mlx.mlx, &params->r.x_max, &params->r.y_max);
	params->r.x = (int)limit(params->r.x, 1, params->r.x_max);
	params->r.y = (int)limit(params->r.y, 1, params->r.y_max);
}

void	mlx_events(t_mlx mlx)
{
	mlx_key_hook(mlx.win, handle_key, &mlx);
	mlx_hook(mlx.win, MAPNOTIFY, STRUCTURENOTIFYMASK, reload_image, &mlx);
	mlx_hook(mlx.win, DESTROYNOTIFY, STRUCTURENOTIFYMASK, close_wdw, &mlx);
	mlx_loop(mlx.mlx);
}
