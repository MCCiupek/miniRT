/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mciupek <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 11:15:01 by mciupek           #+#    #+#             */
/*   Updated: 2021/01/13 18:56:04 by mciupek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vectors.h"
#include "ray.h"
#include "parser.h"
#include <stdio.h>
#include "libft.h"
#include "mlx.h"

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

int	do_intersect(t_params *params, int x, int y)
{
	t_intersect	i;
	t_vect		dir;
	t_vect		right;
	t_vect		up;
	t_vect		forward;

	x = x + params->r.x / 2;
	y = y - params->r.y / 2;

	init_vect(&forward, sin(params->c.fov / 2) * params->r.x / 2, 0, 0);
	right = crossprod(forward, params->c.direction);
	up = crossprod(right, forward);

	init_intersect(&i);
	scalprod(&right, x);
	scalprod(&up, y);

	dir = add(forward, add(right, up));
	
	init_ray(&i.ray, params->c.origin, dir);
	return (intersect_sphere(&i, *(t_shape *)params->shapes->content));
}

int	main(int argc, char **argv)
{
	t_params	params;
	void		*mlx_ptr;
	void		*win_ptr;
	int			x;
	int			y;

	params.shapes = NULL;
	gnl(argc, argv, &params);

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, params.r.x, params.r.y, "miniRT");
	
	x = 0;
	int nbpx = 0;
	while (x <= params.r.x)
	{
		y = 0;
		while (y <= params.r.y)
		{
			if (do_intersect(&params, x, y))
			{
				mlx_pixel_put(mlx_ptr, win_ptr, x, y, rgb(255, 0, 0));
				nbpx++;
			}
			y++;
		}
		x++;
	}
	printf("nb red px = %i (over %.0d)\n", nbpx, params.r.x * params.r.y);
	mlx_loop(mlx_ptr);
	
	/*printf("camera origin : (%f, %f, %f).\n", params.c.origin.x, params.c.origin.y, params.c.origin.z);
	printf("camera vect : (%f, %f, %f).\n", params.c.direction.x, params.c.direction.y, params.c.direction.z);
	printf("camera fov : %f\n", params.c.fov);

	printf("---------SPHERE 1----------\n");
	ft_lstprint(params.shapes);

	printf("-------INTERSECT----------\n");
	init_intersect(&i);
	init_vect(&p, -50, 0, 20);
	init_vect(&d, 100, 0, 0);
	init_ray(&i.ray, p, d);
	printf("ray intersept shape sp1 ? %i\n", intersect_sphere(&i, *(t_shape *)params.shapes->content));
	*/
}
