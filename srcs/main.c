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

void            my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char    *dst;

    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}

int             close_win(int keycode, t_mlx *vars)
{
    mlx_destroy_window(vars->mlx, vars->win);
	return (keycode);
}

int	main(int argc, char **argv)
{
	t_params	params;
	t_mlx		mlx;
	//void		*mlx_ptr;
	//void		*mlx_win;
	t_data		img;
	t_px		px;

	if (argc < 2 || argc > 3)
		return (0);
	if (argc == 3 && ft_strncmp(argv[2], "--save", 7))
		return (0);
	params.shapes = NULL;
	gnl(argc, argv, &params);
	mlx.mlx = mlx_init();
	img.img = mlx_new_image(mlx.mlx, params.r.x, params.r.y);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
                                 &img.endian);
	mlx.win = mlx_new_window(mlx.mlx, params.r.x, params.r.y, "miniRT");
	params.c = *(t_cam *)params.cams->content;
	//ft_lstprint(params.shapes);
	px.x = 0;
	while (px.x <= params.r.x)
	{
		px.y = 0;
		while (px.y <= params.r.y)
		{
			if (do_intersect(&params, &px))
				my_mlx_pixel_put(&img, px.x, px.y, rgb(px.col.r, px.col.g, px.col.b));
			px.y++;
		}
		px.x++;
	}
	ft_lstmap(params.shapes, (void *)free, (void *)ft_lstdelone);
	//printf("ok!\n");
	mlx_put_image_to_window(mlx.mlx, mlx.win, img.img, 0, 0);
	//mlx_hook(mlx.win, 2, 1L<<0, close_win, &mlx);
	mlx_loop(mlx.mlx);
}
