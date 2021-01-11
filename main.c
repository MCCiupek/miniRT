/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mciupek <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 11:15:01 by mciupek           #+#    #+#             */
/*   Updated: 2021/01/11 18:45:34 by mciupek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vectors.h"
#include "ray.h"
#include "parser.h"
#include <stdio.h>
#include "libft.h"

int	main(int argc, char **argv)
{
	t_vect	p;
	float	fov;
	t_vect	d;
	t_shape	sp1;
	t_intersect	i;
	t_params	params;

	gnl(argc, argv, &params);
	init_vect(&p, -50, 0, 20);
	init_vect(&d, 100, 0, 0);
	printf("camera : (%f, %f, %f).\n", p.x, p.y, p.z);
	
	printf("---------SPHERE 1----------\n");
	sp1.str = "sp";
	init_vect(&sp1.p0, 0, 0, 20);
	sp1.d = 10;
	init_colors(&sp1.colors, 10, 0, 225);
	printf("identifiant : %s\ninit_vector(%f, %f, %f)\ndiameter : %f\ncolors : (%i, %i, %i)\n", sp1.str, sp1.p0.x, sp1.p0.y, sp1.p0.z, sp1.d, sp1.colors.r, sp1.colors.g, sp1.colors.b);

	printf("-------INTERSECT----------\n");
	init_intersect(&i);
	init_ray(&i.ray, p, d);
	printf("ray intersept shape sp1 ? %i\n", intersect_sphere(&i, sp1));
	
}
