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

int		init_obj_lst(t_params *params, void *(*f)(void *, char **tab),
							void *obj, char **tab)
{
	t_list	*elem;
	t_list	**lst;
	int		err;

	if (!obj)
		return (ft_free(tab) + MEM_ERR);
	//	error(MEM_ERR, tab, line, params);
	if (!ft_strncmp(tab[0], "c", 2))
		lst = &params->cams;
	if (!ft_strncmp(tab[0], "l", 2))
		lst = &params->lights;
	if (is_shape(tab[0]))
		lst = &params->shapes;
	err = (int)f(obj, tab);
	elem = ft_lstnew(obj);
	ft_lstadd_back(lst, elem);
	return (err);
}

static int	parse_lsts(t_params *params, char **tab)
{
	void	*obj;

	if (!ft_strncmp(tab[0], "c", 2))
	{
		obj = (t_cam *)malloc(sizeof(t_cam));
		return (init_obj_lst(params, (void *)init_cam, obj, tab));
		//return (1);
	}
	else if (!ft_strncmp(tab[0], "l", 2))
	{
		obj = (t_light *)malloc(sizeof(t_light));
		return (init_obj_lst(params, (void *)init_light, obj, tab));
		//return (1);
	}
	else if (is_shape(tab[0]))
	{
		obj = (t_shape *)malloc(sizeof(t_shape));
		return (init_obj_lst(params, (void *)init_sh, obj, tab));
		//return (1);
	}
	return (-1);
}

int		parse(char *line, t_params *params)
{
	char	**tab;
	int		err;

	tab = ft_split(line, ' ');
	if (!tab || !tab[0])
		return (ft_free(tab));
	else if (!ft_strncmp(tab[0], "R", 2))
	{
		if (params->r.count)
			return (ft_free(tab) + AR_DUP);
		//	error(AR_DUP, tab, line, params);
		return (ft_free(tab) + init_resol(params, tab));
		//	return (ft_free(tab) + RES_FMT);
	}
	else if (!ft_strncmp(tab[0], "A", 2))
	{
		if (params->al.count)
			return (ft_free(tab) + AR_DUP);
		//	error(AR_DUP, tab, line, params);
		return (ft_free(tab) + init_alight(params, tab));
		//	return (ft_free(tab) + AMB_FMT);
	}
	err = parse_lsts(params, tab);
	if (err == -1 && *tab[0] != '#')
		return (ft_free(tab) + ID_ERR);
		//error(ID_ERR, tab, line, params);
	return (ft_free(tab) + err);
}

int			gnl(int argc, char **argv, t_params *params)
{
	int		fd;
	char	*line;
	int		i;
	int		ret;

	i = 0;
	ret = 0;
	if (argc == 2)
		fd = open(argv[1], O_RDONLY);
	else
		fd = open(argv[2], O_RDONLY);
	if (fd < 1)
		error(RD_ERR, NULL, NULL, NULL);
	i = get_next_line(fd, &line);
	while (i != -1)
	{
		if (!ret)
			ret = parse(line, params);
		free(line);
		if (i == 0)
			break ;
		i = get_next_line(fd, &line);
	}
	if (argc == 2)
		close(fd);
	if (ret)
		error(ret, NULL, NULL, NULL);
	return (0);
}
