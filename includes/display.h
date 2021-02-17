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

#ifndef DISPLAY_H
# define DISPLAY_H

# include "minirt.h"

# define BMP_FILENAME "miniRT.bmp"
# define TRUE_COLOR 24
# define DEFAULT_DPI 96
# define PPM_CONV_FACTOR 39.375
# define HEADER_BYTES 54
# define DEFAULT_BIPLANES 1
# define FILE_PERMISSIONS 0644
# define PIXEL_LEN 4

typedef struct  s_mlx {
        void    *mlx;
        void    *win;
		t_list	*imgs;
}               t_mlx;

typedef struct  s_data {
    void        *img;
    char        *addr;
    int         bits_per_pixel;
    int         line_length;
    int         endian;
}               t_data;

typedef struct	s_bmp_h
{
	unsigned char	bmp_type[2];
	int				file_size;
	short			reserved1;
	short			reserved2;
	unsigned int	offset;
}				t_bmp_h;

typedef struct	s_dib_h
{
	unsigned int	size_header;
	unsigned int	width;
	unsigned int	height;
	short			planes;
	short			bit_count;
	unsigned int	compr;
	unsigned int	img_size;
	unsigned int	ppm_x;
	unsigned int	ppm_y;
	unsigned int	clr_used;
	unsigned int	clr_important;
}				t_dib_h;

# ifdef MACOS
void mlx_destroy_display(void *mlx);
# endif

void    free_imgs(t_mlx *mlx);
int		reload_image(t_mlx *mlx);
int     close_wdw(t_mlx *mlx);
int     handle_key(int keycode, t_mlx *vars);
void	create_image(t_data *img, t_mlx *mlx, t_params *params);
void    save_bmp(t_mlx *mlx, t_data *img, t_params *params, const char *filename);

#endif
