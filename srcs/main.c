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

void	check_params(int argc, char **argv)
{
	char	**tab;

	if (argc < 2 || argc > 3)
		error(1);
	if (argc == 3 && ft_strncmp(argv[1], "-save", 6))
		error(2);
	if (argc == 2)
	{
		tab = ft_split(argv[1], '.');
		if (ft_strncmp(tab[ft_tabsize(tab) - 1], "rt", ft_strlen(tab[ft_tabsize(tab) - 1])))
			error(3);
	}
}

int		main(int argc, char **argv)
{
	t_params	params;
	t_mlx		mlx;
	t_data		*img;
	t_list		*elem;

	check_params(argc, argv);
	printf("Parsing...\t\t");
	//mlx_get_screen_size(mlx.mlx, params.r.xmax, params.r.ymax);
	params.shapes = NULL;
	gnl(argc, argv, &params);
	printf("DONE\n");
	printf("Init MLX...\t\t");
	mlx.mlx = mlx_init();
	if (argc < 3)
		mlx.win = mlx_new_window(mlx.mlx, params.r.x, params.r.y, "miniRT");
	printf("DONE\n");
	int size = argc == 3 ? 1 : ft_lstsize(params.cams);
	mlx.imgs = NULL;
	while (params.cams)
	{
		printf("Building image %i/%i...\t", size + 1 - ft_lstsize(params.cams), size);
		params.c = *(t_cam *)params.cams->content;
		img = create_image(&mlx, &params);
		elem = ft_lstnew(img);
		ft_lstadd_back(&mlx.imgs, elem);
		params.cams = params.cams->next;
		printf("DONE\n");
		if (argc == 3)
			save_bmp(img, &params, FILENAME);
	}
	ft_lstlast(mlx.imgs)->next = mlx.imgs;
	if (argc == 2)
	{
		printf("Preparing display...\t");
		mlx_put_image_to_window(mlx.mlx, mlx.win, (*(t_data *)mlx.imgs->content).img, 0, 0);
		printf("DONE\n");
		printf("\nPress space bar to change camera.\n");
		printf("Press escape or quit button to exit.\n\n");
		mlx_key_hook(mlx.win, handle_key, &mlx);
		mlx_hook(mlx.win, DESTROYNOTIFY, STRUCTURENOTIFYMASK, close_wdw, &mlx);
		mlx_loop(mlx.mlx);
	}
	//ft_lstmap(params.shapes, (void *)free, (void *)ft_lstdelone);
	//ft_lstmap(params.cams, (void *)free, (void *)ft_lstdelone);
	//ft_lstmap(params.lights, (void *)free, (void *)ft_lstdelone);
	return (0);
}
