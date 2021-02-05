/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mciupek <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 14:40:39 by mciupek           #+#    #+#             */
/*   Updated: 2021/01/18 17:46:56 by mciupek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"
//#include "minirt.h"

int		ft_tabsize(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

void	ft_free(char **tab)
{
	int	i;

	i = -1;
	while (tab[++i])
		free(tab[i]);
	free(tab);
}

void	parse(char *line, t_params *params)
{
	int 	i;
	char	**tab;
	t_list	*elem;
	t_shape	*shape;
	t_light	*light;
	t_cam	*cam;
	
	i = 0;
	//tab = ft_split(line, '\t');
	tab = ft_split(line, ' ');
	if (!tab[0])
	{	
		ft_free(tab);
		return ;
	}
	if (!ft_strncmp(tab[0],"R", 2))
		init_resol(&params->r, tab);
	if (!ft_strncmp(tab[0], "A", 2))
		init_alight(&params->al, tab);
	if (!ft_strncmp(tab[0], "c", 2))
	{
		cam = malloc(sizeof(t_cam));
		init_cam(cam, tab);
		elem = ft_lstnew(cam);
		ft_lstadd_back(&params->cams, elem);
	}
	if (!ft_strncmp(tab[0], "l", 2))
	{
		light = malloc(sizeof(t_light));
		init_light(light, tab);
		elem = ft_lstnew(light);
		ft_lstadd_back(&params->lights, elem);
	}
	if (!ft_strncmp(tab[0], "sp", 3) || !ft_strncmp(tab[0], "pl", 3) || 
		!ft_strncmp(tab[0], "sq", 3) || !ft_strncmp(tab[0], "cy", 3) || 
		!ft_strncmp(tab[0], "tr", 3))
	{
		shape = malloc(sizeof(t_shape));
		init_sh(shape, tab);
		elem = ft_lstnew(shape);
		ft_lstadd_back(&params->shapes, elem);
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
	else if (argc == 3)
		fd = open(argv[2], O_RDONLY);
	else
		return (2);
	if (!fd)
		error(4);
	while ((i = get_next_line(fd, &line)) != -1)
	{
		parse(line, params);
		//printf("[%i] line = %s\n", i, line);
		free(line);
		if (i == 0)
			break;
	}
	//printf("PARSING DONE [SUCCESS]\n");
	if (argc == 2)
		close(fd);
	return (0);
}
