/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mciupek <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 11:15:01 by mciupek           #+#    #+#             */
/*   Updated: 2021/01/20 12:42:33 by mciupek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"
//#include "minirt.h"

void	ft_lstprint(t_list *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		i++;
		printf("[%i] id : %s\n", i, (*(t_shape *)(lst->content)).id);
		printf("[%i] dir : (%f, %f, %f)\n", i, (*(t_shape *)(lst->content)).direction.x, (*(t_shape *)(lst->content)).direction.y, (*(t_shape *)(lst->content)).direction.z);
		printf("[%i] d : %f\n", i, (*(t_shape *)(lst->content)).d);
		printf("[%i] h : %f\n\n", i, (*(t_shape *)(lst->content)).h);
		lst = lst->next;
	}
}

int	main(int argc, char **argv)
{
	t_params	params;
	void		*mlx_ptr;
	//void		*im_ptr;
	void		*win_ptr;
	t_px		px;

	if (argc < 2 || argc > 3)
		return (0);
	if (argc == 3 && ft_strncmp(argv[2], "--save", 7))
		return (0);
	params.shapes = NULL;
	gnl(argc, argv, &params);
	mlx_ptr = mlx_init();
	//im_ptr = mlx_new_image(mlx_ptr, params.r.x, params.r.y);
	win_ptr = mlx_new_window(mlx_ptr, params.r.x, params.r.y, "miniRT");
	printf("Nb shapes = %i\n", ft_lstsize(params.shapes));
	printf("Nb lights = %i\n", ft_lstsize(params.lights));
	printf("Nb cams = %i\n\n", ft_lstsize(params.cams));
	params.c = *(t_cam *)params.cams->content;
	printf("cam0 p0(%f, %f, %f)\n", ((t_cam *)params.cams->content)->origin.x, 
									((t_cam *)params.cams->content)->origin.y,
									((t_cam *)params.cams->content)->origin.z);
	printf("c p0(%f, %f, %f)\n\n", params.c.origin.x, 
									params.c.origin.y,
									params.c.origin.z);
	printf("cam0 d(%f, %f, %f)\n", ((t_cam *)params.cams->content)->direction.x, 
									((t_cam *)params.cams->content)->direction.y,
									((t_cam *)params.cams->content)->direction.z);
	printf("c d(%f, %f, %f)\n\n", params.c.direction.x, 
									params.c.direction.y,
									params.c.direction.z);
	printf("cam0 fov : %f\n", ((t_cam *)params.cams->content)->fov);
	printf("c fov : %f\n\n", params.c.fov);
	ft_lstprint(params.shapes);
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
	ft_lstmap(params.shapes, (void *)free, (void *)ft_lstdelone);
	//printf("ok!\n");
	mlx_loop(mlx_ptr);
}
