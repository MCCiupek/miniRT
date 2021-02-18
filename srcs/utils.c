/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mciupek <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 14:40:39 by mciupek           #+#    #+#             */
/*   Updated: 2021/02/11 12:00:45 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"
//#include "minirt.h"

void	ft_free(char **tab)
{
	int	i;

	i = -1;
	while (tab[++i])
		free(tab[i]);
	free(tab);
}

void	free_imgs(t_mlx *mlx)
{
	t_list	*elem;
	t_list	*tmp;

	elem = mlx->imgs->next;
	mlx->imgs->next = NULL;
	while (elem)
	{
		tmp = elem->next;
		mlx_destroy_image(mlx->mlx, ((t_data *)elem->content)->img);
		free((t_data *)elem->content);
		free(elem);
		elem = tmp;
	}
}

void	free_mlx(t_mlx *mlx)
{
	mlx_destroy_image(mlx->mlx, ((t_data *)mlx->imgs->content)->img);
	free((t_data *)mlx->imgs->content);
	free(mlx->imgs);
	if (OS == 2)
		mlx_destroy_display(mlx->mlx);
	free(mlx->mlx);
}
