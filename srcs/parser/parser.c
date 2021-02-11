/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mciupek <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 14:40:39 by mciupek           #+#    #+#             */
/*   Updated: 2021/02/11 11:47:52 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"
//#include "minirt.h"

void	ft_free(char **tab)
{
	int	i;

	i = -1;
	while (tab[++i])
		free(tab[i]);
	free(tab);
}

void	init_obj_lst(t_list **lst, void *(*f)(void *, char **tab),
							void *obj, char **tab)
{
	t_list	*elem;

	f(obj, tab);
	elem = ft_lstnew(obj);
	ft_lstadd_back(lst, elem);
}

int		is_shape(char *tab)
{
	return (!ft_strncmp(tab, "sp", 3) || !ft_strncmp(tab, "pl", 3) ||
			!ft_strncmp(tab, "sq", 3) || !ft_strncmp(tab, "cy", 3) ||
			!ft_strncmp(tab, "tr", 3));
}

void	parse(char *line, t_params *params)
{
	char	**tab;
	void	*obj;

	if (!(tab = ft_split(line, ' ')) || !tab[0])
		return (ft_free(tab));
	if (!ft_strncmp(tab[0], "R", 2))
		init_resol(&params->r, tab);
	if (!ft_strncmp(tab[0], "A", 2))
		init_alight(&params->al, tab);
	if (!ft_strncmp(tab[0], "c", 2))
	{
		obj = (t_cam *)malloc(sizeof(t_cam));
		init_obj_lst(&params->cams, (void *)init_cam, obj, tab);
	}
	if (!ft_strncmp(tab[0], "l", 2))
	{
		obj = (t_light *)malloc(sizeof(t_light));
		init_obj_lst(&params->lights, (void *)init_light, obj, tab);
	}
	if (is_shape(tab[0]))
	{
		obj = (t_shape *)malloc(sizeof(t_shape));
		init_obj_lst(&params->shapes, (void *)init_sh, obj, tab);
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
		free(line);
		if (i == 0)
			break ;
	}
	if (argc == 2)
		close(fd);
	return (0);
}
