/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mciupek <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 14:40:39 by mciupek           #+#    #+#             */
/*   Updated: 2021/01/12 18:07:16 by mciupek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vectors.h"
#include "ray.h"
#include "parser.h"
#include "get_next_line.h"
#include "libft.h"
#include <fcntl.h>
#include <stdio.h>

void	ft_free(char **tab)
{
	int	i;

	i = -1;
	while (tab[++i])
		free(tab[i]);
	free(tab);
}

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
	ft_free(rgb);
}

void	init_cam(t_cam	*c, char  **tab)
{
	char	**coord;
	char	**vect;

	coord = ft_split(tab[1], ',');
	vect = ft_split(tab[2], ',');
	init_vect(&c->origin, ft_atof(coord[0]), ft_atof(coord[1]), ft_atof(coord[2]));
	init_vect(&c->direction, ft_atoi(vect[0]), ft_atoi(vect[1]), ft_atoi(vect[2]));
	c->fov = ft_atof(tab[3]);
	ft_free(coord);
	ft_free(vect);
}

void	init_light(t_light *l, char **tab)
{
	char	**coord;
	char	**rgb;

	coord = ft_split(tab[1], ',');
	rgb = ft_split(tab[3], ',');
	init_vect(&l->origin, ft_atof(coord[0]), ft_atof(coord[1]), ft_atof(coord[2]));
	l->light = ft_atof(tab[2]);
	init_colors(&l->colors, ft_atoi(rgb[0]), ft_atoi(rgb[1]), ft_atoi(rgb[2]));
	ft_free(coord);
	ft_free(rgb);
}

void	init_sp(t_shape	*s, char **tab)
{
	char	**coord;
	char	**rgb;

	if (!s)
	{
		printf("Error\n");
		return ;
	}
	ft_strlcpy(s->id, tab[0], 3);
	coord = ft_split(tab[1], ',');
	rgb = ft_split(tab[3], ',');
	init_vect(&s->p0, ft_atof(coord[0]), ft_atof(coord[1]), ft_atof(coord[2]));
	s->d = ft_atof(tab[2]);
	init_colors(&s->colors, ft_atoi(rgb[0]), ft_atoi(rgb[1]), ft_atoi(rgb[2]));
	ft_free(coord);
	ft_free(rgb);

}

void	parse(char *line, t_params *params)
{
	int 	i;
	char	**tab;
	t_shape	*shape;
	t_list	*new_shape;
	
	i = 0;
	tab = ft_split(line, '\t');
	if (!tab[0])
	{	ft_free(tab);
		return ;
	}
	if (!ft_strncmp(tab[0],"R", 1))
		init_resol(&params->r, tab);
	if (!ft_strncmp(tab[0], "A", 1))
		init_alight(&params->al, tab);
	if (!ft_strncmp(tab[0], "c", 1))
		init_cam(&params->c, tab);
	if (!ft_strncmp(tab[0], "l", 1))
		init_light(&params->l, tab);
	if (!ft_strncmp(tab[0], "sp", 2))
	{
		shape = malloc(sizeof(t_shape));
		init_sp(shape, tab);
		new_shape = ft_lstnew(shape);
		ft_lstadd_back(&params->shapes, new_shape);
	}
	ft_free(tab);
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
		free(line);
		if (i == 0)
			break;
	}
	if (argc == 2)
		close(fd);
	return (0);
}
