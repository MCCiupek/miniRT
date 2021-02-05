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

# define BUFFER_SIZE 32

# define PI 3.1416

# define RES_X_MAX 2560
# define RES_Y_MAX 1600

# define GAMMA 70

# define SPC_KEY 49
# define ESC_KEY 53
# define DESTROYNOTIFY 17

# define STRUCTURENOTIFYMASK 131072

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
# include "colors.h"
# include "vectors.h"
# include "intersect.h"
# include "ray.h"
# include "parser.h"
# include "rotation.h"
# include "light.h"
# include "display.h"
# include "error.h"

# endif
