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

/*typedef struct	s_bmp_h
{
	uint8_t		bmp_type[2];
	int			file_size;
	int16_t		reserved1;
	int16_t		reserved2;
	uint32_t	offset;
}				t_bmp_h;

typedef struct	s_dib_h
{
	uint32_t	size_header;
	uint32_t	width;
	uint32_t	height;
	int16_t		planes;
	int16_t		bit_count;
	uint32_t	compr;
	uint32_t	img_size;
	uint32_t	ppm_x;
	uint32_t	ppm_y;
	uint32_t	clr_used;
	uint32_t	clr_important;
}				t_dib_h;*/

int     close_wdw(int keycode, t_mlx *vars);
int     handle_key(int keycode, t_mlx *vars);
t_data	*create_image(t_mlx *mlx, t_params *params);
void    save_bmp(t_data *img, t_params *params, const char *filename);

#endif
