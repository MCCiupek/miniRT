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

# define ERR "Unidentified error.\n"
# define ERR_1 "Incorrect number of arguments.\n"
# define ERR_2 "Unidentified input file type.\n"
# define ERR_3 "File can't be opened.\n"
# define ERR_4 "Unidentified flag.\n"
# define ERR_5 "Malloc failed while parsing shapes.\n"

void    free_imgs(t_mlx *mlx);
void    free_lsts(t_params *params, t_list *first_cam);
void    error(int err);

# endif
