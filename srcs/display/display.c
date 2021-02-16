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

#include "../../includes/minirt.h"
//#include "minirt.h"

void    free_imgs(t_mlx *mlx)
{
	t_list	*elem;
	//t_list	*tmp;

	elem = mlx->imgs->next;
	mlx->imgs->next = NULL;
	ft_lstclear(&elem, (void *)free);
	/*while (elem)
	{
		tmp = elem->next;
		ft_lstdelone(elem, (void *)free);
		elem = tmp;
	}*/
	//ft_lstclear(&mlx->imgs, (void *)free);
    //free(mlx->imgs);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int		close_wdw(int keycode, t_mlx *vars)
{
	(void)keycode;
	(void)vars;
	//free_imgs(vars);
	exit(EXIT_SUCCESS);
	return (0);
}

int		handle_key(int keycode, t_mlx *vars)
{
	if (keycode == SPC_KEY)
	{
		vars->imgs = vars->imgs->next;
		mlx_put_image_to_window(vars->mlx, vars->win,
			(*(t_data *)vars->imgs->content).img, 0, 0);
		return (1);
	}
	if (keycode == ESC_KEY)
	{
		free_imgs(vars);
		mlx_destroy_window(vars->mlx, vars->win);
		exit(EXIT_SUCCESS);
	}
	return (1);
}

t_data	*create_image(t_mlx *mlx, t_params *params)
{
	t_data		*img;
	t_px		px;

	img = malloc(sizeof(img));
	img->img = mlx_new_image(mlx->mlx, params->r.x, params->r.y);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->line_length, &img->endian);
	px.x = 0;
	while (px.x < params->r.x)
	{
		px.y = 0;
		while (px.y < params->r.y)
		{
			if (do_intersect(params, &px))
				my_mlx_pixel_put(img, px.x, px.y,
					rgb(px.col.r, px.col.g, px.col.b));
			px.y++;
		}
		px.x++;
	}
	return (img);
}
