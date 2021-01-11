/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mciupek <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 14:40:39 by mciupek           #+#    #+#             */
/*   Updated: 2021/01/11 18:57:29 by mciupek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vectors.h"
#include "ray.h"
#include "parser.h"
#include "get_next_line.h"
#include "libft.h"
#include <fcntl.h>
#include <stdio.h>

void	init_resol(t_resol	*r, char  **tab)
{
	r->x = ft_atoi(tab[0]);
	r->y = ft_atoi(tab[1]);
}

void	init_alight(t_alight	*al, char  **tab)
{
	char	**rgb;

	al->light = ft_atof(tab[1]);
	rgb = ft_split(tab[2], ',');
	init_colors(&al->colors, ft_atoi(rgb[0]), ft_atoi(rgb[1]), ft_atoi(rgb[2]));
	free(rgb);
}

void	init_cam(t_cam	*c, char  **tab)
{
	char	**coord;
	char	**vect;

	printf("slt\n");
	coord = ft_split(tab[1], ',');
	vect = ft_split(tab[2], ',');
	printf("str : %s\n", coord[1]);
	printf("float : %f\n", ft_atof(coord[1]));
	init_vect(&c->origin, ft_atof(coord[0]), ft_atof(coord[1]), ft_atof(coord[2]));
	init_vect(&c->direction, ft_atoi(vect[0]), ft_atoi(vect[1]), ft_atoi(vect[2]));
	c->fov = ft_atof(tab[3]);
	free(coord);
	free(vect);
}

void	init_light(t_light	*l, char  **tab)
{
	char	**coord;
	char	**rgb;

	coord = ft_split(tab[1], ',');
	rgb = ft_split(tab[3], ',');
	init_vect(&l->origin, ft_atof(coord[0]), ft_atof(coord[1]), ft_atof(coord[2]));
	l->light = ft_atof(tab[2]);
	init_colors(&l->colors, ft_atoi(rgb[0]), ft_atoi(rgb[1]), ft_atoi(rgb[2]));
	free(coord);
	free(rgb);
}

void	parse(char	*line, t_params *params)
{
	int 	i;
	char	**tab;
	
	i = 0;
	tab = ft_split(line, '\t');
	printf("tab = %s\n", tab[0]);
	if (!tab)
		return ;
	if (!ft_strncmp(tab[0],"R", 1))
		init_resol(&params->r, tab);
	if (!ft_strncmp(tab[0], "A", 1))
		init_alight(&params->al, tab);
	if (!ft_strncmp(tab[0], "c", 1))
		init_cam(&params->c, tab);
	if (!ft_strncmp(tab[0], "L", 1))
		init_light(&params->l, tab);
	printf("coucou\n");
	free(tab);
}

int		gnl(int argc, char **argv, t_params *params)
{
	int		fd;
	char	*line;
	int		i;

	i = 0;
	if (argc == 1)
		fd = 0;
	else if (argc == 2)
		fd = open(argv[1], O_RDONLY);
	else
		return (2);
	while ((i = get_next_line(fd, &line)) != -1)
	{
		parse(line, params);
		//printf("[%i] line = %s\n", i, line);
		free(line);
		if (i == 0)
			break;
	}
	if (argc == 2)
		close(fd);
	return (0);
}
