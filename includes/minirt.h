/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mciupek <mciupek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 14:23:28 by mciupek           #+#    #+#             */
/*   Updated: 2021/01/19 09:22:39 by mciupek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 32
#endif

#ifndef PI
# define PI 3.1416
#endif

# define ESC_KEY 49
# define SPC_KEY 53

/*# define KEYPRESS 2

typedef enum	e_xeventmask
{
	KEYPRESSMASK = 1L << 0,
	STRUCTURENOTIFYMASK = 1L << 17
}               t_xeventmask;*/

/************ A SUPPRIMER !!!! ************/
# include <stdio.h>
/******************************************/

# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include <fcntl.h>

# include "mlx.h"

# include "../libft/libft.h"
# include "get_next_line.h"
# include "display.h"
# include "vectors.h"
# include "intersect.h"
# include "ray.h"
# include "parser.h"
# include "rotation.h"
# include "light.h"

# endif
