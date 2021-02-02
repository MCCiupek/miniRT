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

	//printf("%i, %i\n", x, y);
    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}

int             handle_key(int keycode, t_mlx *vars)
{
	//printf("%i\n", keycode);
	if (keycode == ESC_KEY)
	{
		printf("CHANGE CAM\n");
		vars->imgs = vars->imgs->next;
		mlx_put_image_to_window(vars->mlx, vars->win, (*(t_data *)vars->imgs->content).img, 0, 0);
		return (0);
	}
	if (keycode == SPC_KEY)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		return (1);
	}
	return (0);
}

int	check_params(int argc, char **argv)
{
	if (argc < 2 || argc > 3)
		return (0);
	if (argc == 3 && ft_strncmp(argv[2], "--save", 7))
		return (0);
	return (1);
}

t_data	*create_image(t_mlx *mlx, t_params *params)
{
	t_data		*img;
	t_px		px;

	//printf("\tcam : %f, %f, %f\n", params->c.origin.x, params->c.origin.y, params->c.origin.z);
	img = malloc(sizeof(img));
	img->img = mlx_new_image(mlx->mlx, params->r.x, params->r.y);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, &img->line_length,
                                 &img->endian);
	px.x = 0;
	while (px.x < params->r.x)
	{
		px.y = 0;
		while (px.y < params->r.y)
		{
			//printf("%i, %i\t", px.x, px.y);
			if (do_intersect(params, &px))
				my_mlx_pixel_put(img, px.x, px.y, rgb(px.col.r, px.col.g, px.col.b));
			px.y++;
		}
		px.x++;
	}
	return (img);
}

int	main(int argc, char **argv)
{
	t_params	params;
	t_mlx		mlx;
	t_data		*img;
	t_list		*elem;

	if (!check_params(argc, argv))
		return (0);
	params.shapes = NULL;
	gnl(argc, argv, &params);
	mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx, params.r.x, params.r.y, "miniRT");
	int size = ft_lstsize(params.cams);
	mlx.imgs = NULL;
	while (params.cams)
	{
		printf("Building image %i/%i\n", size + 1 - ft_lstsize(params.cams), size);
		params.c = *(t_cam *)params.cams->content;
		printf("\tcam : %f, %f, %f\n", params.c.origin.x, params.c.origin.y, params.c.origin.z);
		img = create_image(&mlx, &params);
		elem = ft_lstnew(img);
		ft_lstadd_back(&mlx.imgs, elem);
		params.cams = params.cams->next;
	}
	ft_lstlast(mlx.imgs)->next = mlx.imgs;
	//ft_lstmap(params.shapes, (void *)free, (void *)ft_lstdelone);
	mlx_put_image_to_window(mlx.mlx, mlx.win, (*(t_data *)mlx.imgs->content).img, 0, 0);
	mlx_key_hook(mlx.win, handle_key, &mlx);
	mlx_loop(mlx.mlx);
}
