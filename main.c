/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mciupek <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 11:15:01 by mciupek           #+#    #+#             */
/*   Updated: 2021/01/19 10:07:59 by mciupek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vectors.h"
#include "ray.h"
#include "parser.h"
#include <stdio.h>
#include "libft.h"
#include <mlx.h>
#include "display.h"

void	ft_lstprint(t_list *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		i++;
		printf("[%i] id : %s\n", i, (*(t_shape *)(lst->content)).id);
		printf("[%i] d : %f\n", i, (*(t_shape *)(lst->content)).d);
		lst = lst->next;
	}
}

int	rgb(int r, int g, int b)
{
	return (((r&0x0ff)<<16)|((g&0x0ff)<<8)|(b&0x0ff));
}

int	deal_key(int key, void **param)
{
	printf("pxl put\n");
	mlx_pixel_put(param[0], param[1], (int)param[2], (int)param[3], rgb(255, 0, 0));
	return (0);
}

int	intersect(t_list *shapes, t_intersect *i)
{
	t_shape	*shape;

	while (shapes)
	{
		shape = (t_shape *)shapes->content;
		if (!ft_strncmp(shape->id, "sp", 3))
			intersect_sphere(i, shape);
		else if (!ft_strncmp(shape->id, "pl", 3))
			intersect_plan(i, shape);
		shapes = shapes->next;
	}
	return (i->shape != NULL);
}

int	do_intersect(t_params *params, t_px *px)
{
	t_intersect	i;
	t_vect		dir;
	int		x;
	int		y;
	
	x = px->x - params->r.x / 2;
	y = px->y - params->r.y / 2;
	init_intersect(&i);
	init_vect(&dir, x, y, 1 / (2 * tan(params->c.fov / 2)) * params->r.x / 2);
	init_ray(&i.ray, params->c.origin, dir);
	if (intersect(params->shapes, &i))
	{
		px->col = i.shape->colors;
		return (1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_params	params;
	void		*mlx_ptr;
	void		*win_ptr;
	t_px		px;

	params.shapes = NULL;
	gnl(argc, argv, &params);

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, params.r.x, params.r.y, "miniRT");
	
	px.x = 0;
	while (px.x <= params.r.x)
	{
		px.y = 0;
		while (px.y <= params.r.y)
		{
			if (do_intersect(&params, &px))
				mlx_pixel_put(mlx_ptr, win_ptr, px.x, px.y, rgb(px.col.r, px.col.g, px.col.b));
			px.y++;
		}
		px.x++;
	}
	//printf("ok!\n");
	mlx_loop(mlx_ptr);
}
