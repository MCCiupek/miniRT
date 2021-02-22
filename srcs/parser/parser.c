/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mciupek <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 14:40:39 by mciupek           #+#    #+#             */
/*   Updated: 2021/02/11 12:00:45 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int			is_shape(char *tab)
{
	return (!ft_strncmp(tab, "sp", 3) || !ft_strncmp(tab, "pl", 3)
		|| !ft_strncmp(tab, "sq", 3) || !ft_strncmp(tab, "cy", 3)
		|| !ft_strncmp(tab, "tr", 3));
}

void		init_obj_lst(t_params *params, void *(*f)(void *, char **tab, char *line, t_params *params),
							void *obj, char **tab, char *line)
{
	t_list	*elem;
	t_list	**lst;

	if (!obj)
		error(MEM_ERR, tab, line, params);
	if (!ft_strncmp(tab[0], "c", 2))
		lst = &params->cams;
	if (!ft_strncmp(tab[0], "l", 2))
		lst = &params->lights;
	if (is_shape(tab[0]))
		lst = &params->shapes;
	f(obj, tab, line, params);
	elem = ft_lstnew(obj);
	ft_lstadd_back(lst, elem);
}

static int	parse_lsts(t_params *params, char **tab, char *line)
{
	void	*obj;

	if (!ft_strncmp(tab[0], "c", 2))
	{
		obj = (t_cam *)malloc(sizeof(t_cam));
		init_obj_lst(params, (void *)init_cam, obj, tab, line);
		return (1);
	}
	else if (!ft_strncmp(tab[0], "l", 2))
	{
		obj = (t_light *)malloc(sizeof(t_light));
		init_obj_lst(params, (void *)init_light, obj, tab, line);
		return (1);
	}
	else if (is_shape(tab[0]))
	{
		obj = (t_shape *)malloc(sizeof(t_shape));
		init_obj_lst(params, (void *)init_sh, obj, tab, line);
		return (1);
	}
	return (0);
}

void		parse(char *line, t_params *params)
{
	char	**tab;

	tab = ft_split(line, ' ');
	if (!tab || !tab[0])
		return (ft_free(tab));
	else if (!ft_strncmp(tab[0], "R", 2))
	{
		if (params->r.count)
			error(AR_DUP, tab, line, params);
		init_resol(params, tab, line);
	}
	else if (!ft_strncmp(tab[0], "A", 2))
	{
		if (params->al.count)
			error(AR_DUP, tab, line, params);
		init_alight(params, tab, line);
	}
	else if (!parse_lsts(params, tab, line) && *tab[0] != '#')
		error(ID_ERR, tab, line, params);
	ft_free(tab);
}

int			gnl(int argc, char **argv, t_params *params)
{
	int		fd;
	char	*line;
	int		i;

	i = 0;
	if (argc == 2)
		fd = open(argv[1], O_RDONLY);
	else
		fd = open(argv[2], O_RDONLY);
	if (fd < 1)
		error(RD_ERR, NULL, NULL, NULL);
	i = get_next_line(fd, &line);
	while (i != -1)
	{
		parse(line, params);
		free(line);
		if (i == 0)
			break ;
		i = get_next_line(fd, &line);
	}
	if (argc == 2)
		close(fd);
	return (0);
}
