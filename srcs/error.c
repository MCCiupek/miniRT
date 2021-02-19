/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mciupek <mciupek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 14:28:07 by mciupek           #+#    #+#             */
/*   Updated: 2021/01/20 12:49:44 by mciupek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_error	g_errors[] =
{
	{ UKN_ERR, "Unknown error." },
	{ NB_ARG, "Invalid call: Incorrect number of arguments.\n \
	Use ./path/to/miniRT [-save] <filename>.rt" },
	{ FILENAME_ERR, "Invalid file: Use the '.rt' extension." },
	{ RD_ERR, "Invalid file: cannot read input file." },
	{ OPT_ERR, "Invalid option: Try '-save'." },
	{ MEM_ERR, "Memory allocation failed while parsing shapes." },
	{ AR_DUP, "Invalid scene: Ambient light (A) and resolution (R) \
	can only be declared once." },
	{ AMB_FMT, "Invalid scene: Ambient light badly formatted." },
	{ RES_FMT, "Invalid scene: Resolution badly formatted." },
	{ CAM_FMT, "Invalid scene: Camera badly formatted." },
	{ LIGHT_FMT, "Invalid scene: Light badly formatted." },
	{ SPHERE_FMT, "Invalid scene: Sphere badly formatted." },
	{ PLANE_FMT, "Invalid scene: Plane badly formatted." },
	{ SQUARE_FMT, "Invalid scene: Square badly formatted." },
	{ TR_FMT, "Invalid scene: Triangle badly formatted." },
	{ CYL_FMT, "Invalid scene: Cylinder badly formatted." },
	{ COLOR_FMT, "Invalid scene: Color badly formatted." },
	{ COORD_FMT, "Invalid scene: Coordinates badly formatted." },
	{ FLOAT_FMT, "Invalid scene: Floating-point number badly formatted." },
	{ NUM_FMT, "Invalid scene: Number badly formatted." },
	{ ID_ERR, "Invalid scene: Unknown identifier." },
	{ NO_AMB, "No ambient light declared. Rendering stopped." },
	{ NO_CAM, "No camera declared. Rendering stopped." },
	{ NO_LIGHT, "No light declared. Rendering stopped." },
	{ NO_OBJ, "No object declared. Rendering stopped." },
	{ NO_RES, "No resolution declared. Rendering stopped." },
	{ RES_LOW, "Resolution too low: minimum is 300x300. Rendering stopped." },
	{ SCENE_FMT, "Invalid scene: Scene badly formatted." }
};

static char	*get_error_msg(t_err raised)
{
	if (raised != ERRNO_TO_STR)
		return (g_errors[raised].msg);
	return ((char *)strerror(errno));
}

void		error(t_err raised)
{
	char	*msg;

	msg = get_error_msg(raised);
	printf("Error\n%s\n", msg);
	exit(EXIT_FAILURE);
}
