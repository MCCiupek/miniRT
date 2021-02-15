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

# define GL_SILENCE_DEPRECATION

# define BUFFER_SIZE 32

# define FILENAME "render/miniRT.bmp"

# define RES_X_MAX 2560
# define RES_Y_MAX 1600

# define RAY_MIN 0.001
# define RAY_MAX 1.0e30

# define GAMMA 70

# ifdef LINUX
#  define OS 2
#  define SPC_KEY 32
#  define ESC_KEY 65307
# endif
# ifdef MACOS
#  define OS 1
#  define SPC_KEY 49
#  define ESC_KEY 53
# endif

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

# include "libft.h"
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
