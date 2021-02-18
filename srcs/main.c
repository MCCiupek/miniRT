/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mciupek <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 11:15:01 by mciupek           #+#    #+#             */
/*   Updated: 2021/02/15 15:21:59 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"
//#include "minirt.h"

static void	check_params(int argc, char **argv)
{
	char	**tab;

	if (argc < 2 || argc > 3)
		error(1);
	if (argc == 3 && ft_strncmp(argv[1], "-save", 6))
		error(2);
	if (argc == 2)
	{
		tab = ft_split(argv[1], '.');
		if (ft_strncmp(tab[ft_tabsize(tab) - 1], "rt",
				ft_strlen(tab[ft_tabsize(tab) - 1])))
		{
			ft_free(tab);
			error(3);
		}
		ft_free(tab);
	}
}

static void	init_params(int argc, char **argv, t_params *params, t_mlx *mlx)
{
	check_params(argc, argv);
	params->r.count = 0;
	params->al.count = 0;
	params->shapes = NULL;
	params->cams = NULL;
	params->lights = NULL;
	mlx->imgs = NULL;
	gnl(argc, argv, params);
	mlx->mlx = mlx_init();
	get_screen_size(*mlx, params);
}

static t_data	*switch_cam(t_params *params, t_mlx *mlx)
{
	t_data		*img;
	t_list		*elem;

	params->c = *(t_cam *)params->cams->content;
	img = (t_data *)malloc(sizeof(t_data));
	create_image(img, mlx, params);
	elem = ft_lstnew(img);
	ft_lstadd_back(&mlx->imgs, elem);
	return (img);
}

int	main(int argc, char **argv)
{
	t_params	params;
	t_mlx		mlx;
	t_data		*img;
	t_list		*first;

	init_params(argc, argv, &params, &mlx);
	first = params.cams;
	while (params.cams)
	{
		img = switch_cam(&params, &mlx);
		if (argc == 3)
		{
			free_lsts(&params, first);
			save_bmp(&mlx, img, &params, FILENAME);
		}
		params.cams = params.cams->next;
	}
	mlx.win = mlx_new_window(mlx.mlx, params.r.x, params.r.y, "miniRT");
	ft_lstlast(mlx.imgs)->next = mlx.imgs;
	free_lsts(&params, first);
	mlx_put_image_to_window(mlx.mlx, mlx.win,
		(*(t_data *)mlx.imgs->content).img, 0, 0);
	mlx_events(mlx);
	return (0);
}
