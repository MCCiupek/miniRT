/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mciupek <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 11:15:01 by mciupek           #+#    #+#             */
/*   Updated: 2021/01/12 18:11:51 by mciupek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vectors.h"
#include "ray.h"
#include "parser.h"
#include <stdio.h>
#include "libft.h"

void	ft_lstprint(t_list *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		i++;
		printf("[%i] id : %s\n", i, (*(t_shape *)(lst->content)).id);
		printf("[%i] d : %f\n", i, (*(t_shape *)(lst->content)).d);
		lst = lst->next;
	}
}

int	main(int argc, char **argv)
{
	t_intersect	i;
	t_params	params;
	t_vect		p;
	t_vect		d;
	t_list		**l;

	params.shapes = NULL;
	gnl(argc, argv, &params);
	
	printf("camera origin : (%f, %f, %f).\n", params.c.origin.x, params.c.origin.y, params.c.origin.z);
	printf("camera vect : (%f, %f, %f).\n", params.c.direction.x, params.c.direction.y, params.c.direction.z);
	printf("camera fov : %f\n", params.c.fov);

	l = &params.shapes;
	printf("shapes nb : %i\n", ft_lstsize(*l));

	printf("---------SPHERE 1----------\n");
	ft_lstprint(params.shapes);

	printf("-------INTERSECT----------\n");
	init_intersect(&i);
	init_vect(&p, -50, 0, 20);
	init_vect(&d, 100, 0, 0);
	init_ray(&i.ray, p, d);
	printf("ray intersept shape sp1 ? %i\n", intersect_sphere(&i, *(t_shape *)params.shapes->content));
	
}
