/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mciupek <mciupek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 14:23:28 by mciupek           #+#    #+#             */
/*   Updated: 2021/01/19 09:22:39 by mciupek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# include "minirt.h"

typedef enum	e_err
{
	ERRNO_TO_STR = -1,
	UKN_ERR,
	NB_ARG,
	FILENAME_ERR,
	RD_ERR,
	OPT_ERR,
	MEM_ERR,
	AR_DUP,
	AMB_FMT,
	RES_FMT,
	CAM_FMT,
	LIGHT_FMT,
	SPHERE_FMT,
	PLANE_FMT,
	SQUARE_FMT,
	TR_FMT,
	CYL_FMT,
	COLOR_FMT,
	COORD_FMT,
	ID_ERR,
	NO_AMB,
	NO_CAM,
	NO_RES
}				t_err;

typedef struct	s_error
{
	t_err	u_id;
	char	*msg;
}				t_error;

void		error(t_err raised, char **tab_to_free, char *line_to_free, t_params *params);

#endif
