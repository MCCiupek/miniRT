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
#ifdef MACOS
# include <OpenGL/gl.h>
# include <OpenGL/glu.h>
# include <GLUT/glut.h>
static void mlx_get_screen_size(void *mlx, int *x_max, int *y_max)
{
	//GLint maxViewportSize[2];

	(void)mlx;
	//glGetIntegerv(GL_MAX_VIEWPORT_DIMS, maxViewportSize);
	*x_max = RES_X_MAX;//&maxViewportSize[0];
	*y_max = RES_Y_MAX;//&maxViewportSize[1];
}
#endif
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
		{
			ft_free(tab);
			error(3);
		}
		ft_free(tab);
	}
}

void	get_screen_size(t_mlx mlx, t_params *params)
{
	if (OS == 2)
		mlx_get_screen_size(mlx.mlx, &params->r.x_max, &params->r.y_max);
	else if (OS == 1)
		mlx_get_screen_size(mlx.mlx, &params->r.x_max, &params->r.y_max);
	params->r.x = (int)limit(params->r.x, 0, params->r.x_max);
	params->r.y = (int)limit(params->r.y, 0, params->r.y_max);
}

int		main(int argc, char **argv)
{
	t_params	params;
	t_mlx		mlx;
	t_data		*img;
	t_list		*elem;
	t_list		*first;

	check_params(argc, argv);
	printf("Parsing...\t\t");
	params.shapes = NULL;
	params.cams = NULL;
	params.lights = NULL;
	gnl(argc, argv, &params);
	printf("DONE\n");
	printf("Init MLX...\t\t");
	mlx.mlx = mlx_init();
	get_screen_size(mlx, &params);
	printf("DONE\n");
	int size = argc == 3 ? 1 : ft_lstsize(params.cams);
	mlx.imgs = NULL;
	first = params.cams;
	while (params.cams)
	{
		printf("Building image %i/%i...\t", size + 1 - ft_lstsize(params.cams), size);
		params.c = *(t_cam *)params.cams->content;
		img = (t_data *)malloc(sizeof(t_data));
		create_image(img, &mlx, &params);
		elem = ft_lstnew(img);
		ft_lstadd_back(&mlx.imgs, elem);
		if (argc == 3)
		{
			free_lsts(&params, first);
			save_bmp(&mlx, img, &params, FILENAME);
		}
		params.cams = params.cams->next;
		printf("DONE\n");
	}
	mlx.win = mlx_new_window(mlx.mlx, params.r.x, params.r.y, "miniRT");
	ft_lstlast(mlx.imgs)->next = mlx.imgs;
	free_lsts(&params, first);
	if (argc == 2)
	{
		printf("Preparing display...\t");
		mlx_put_image_to_window(mlx.mlx, mlx.win, (*(t_data *)mlx.imgs->content).img, 0, 0);
		printf("DONE\n");
		printf("\nPress space bar to change camera.\n");
		printf("Press escape or quit button to exit.\n\n");
		mlx_key_hook(mlx.win, handle_key, &mlx);
		mlx_hook(mlx.win, MAPNOTIFY, STRUCTURENOTIFYMASK, reload_image, &mlx);
		mlx_hook(mlx.win, DESTROYNOTIFY, STRUCTURENOTIFYMASK, close_wdw, &mlx);
		mlx_loop(mlx.mlx);
	}
	return (0);
}
