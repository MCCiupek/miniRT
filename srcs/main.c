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
		//printf("[%i] d : %f\n", i, (*(t_shape *)(lst->content)).d);
		lst = lst->next;
	}
}

int	main(int argc, char **argv)
{
	t_params	params;
	void		*mlx_ptr;
	void		*im_ptr;
	void		*win_ptr;
	t_px		px;

	if (argc < 2 || ac > 3)
		return (0);
	if (argc == 3 && ft_strcmp(argv[2], "--save"))
		return (0);
	params.shapes = NULL;
	gnl(argc, argv, &params);
	mlx_ptr = mlx_init();
	im_ptr = mlx_new_image(mlx_ptr, params.r.x, params.r.y);
	win_ptr = mlx_new_window(mlx_ptr, params.r.x, params.r.y, "miniRT");
	printf("Nb shapes = %i\n", ft_lstsize(params.shapes));
	printf("Nb lights = %i\n", ft_lstsize(params.lights));
	printf("Nb cams = %i\n", ft_lstsize(params.cams));
	//ft_lstprint(params.shapes);
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
