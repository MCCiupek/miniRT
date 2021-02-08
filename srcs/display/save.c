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

#include "../../includes/minirt.h"
//#include "minirt.h"

static void	create_bmpfileheader(t_bmp_h *header, int size)
{
	ft_bzero(header, sizeof(t_bmp_h));
	header->bmp_type[0] = 'B';
	header->bmp_type[1] = 'M';
	header->file_size = HEADER_BYTES + size;
	header->reserved1 = 0;
	header->reserved2 = 9;
	header->offset = HEADER_BYTES;
}

/*
** This function fills the DIB header structure
*/

static void	create_bmpdibheader(t_params *params, t_dib_h *header, int size)
{
	int		ppm;

	ppm = DEFAULT_DPI * PPM_CONV_FACTOR;
	ft_bzero(header, sizeof(t_dib_h));
	header->size_header = sizeof(t_dib_h);
	header->width = params->r.x;
	header->height = params->r.y;
	header->planes = DEFAULT_BIPLANES;
	header->bit_count = TRUE_COLOR;
	header->compr = 0;
	header->img_size = HEADER_BYTES + size;
	header->ppm_x = ppm;
	header->ppm_y = ppm;
	header->clr_used = 0;
	header->clr_important = 0;
}

/*
** This function writes headers to the file
*/

static void	write_bmpheaders(t_params *params, int fd)
{
	t_bmp_h	file_header;
	t_dib_h	dib_header;
	int		size;

	size = params->r.x * params->r.y * 3;
	create_bmpfileheader(&file_header, size);
	create_bmpdibheader(params, &dib_header, size);
	write(fd, &(file_header.bmp_type), 2);
	write(fd, &(file_header.file_size), 4);
	write(fd, &(file_header.reserved1), 2);
	write(fd, &(file_header.reserved2), 2);
	write(fd, &(file_header.offset), 4);
	write(fd, &(dib_header.size_header), 4);
	write(fd, &(dib_header.width), 4);
	write(fd, &(dib_header.height), 4);
	write(fd, &(dib_header.planes), 2);
	write(fd, &(dib_header.bit_count), 2);
	write(fd, &(dib_header.compr), 4);
	write(fd, &(dib_header.img_size), 4);
	write(fd, &(dib_header.ppm_x), 4);
	write(fd, &(dib_header.ppm_y), 4);
	write(fd, &(dib_header.clr_used), 4);
	write(fd, &(dib_header.clr_important), 4);
}

void    write_bmpdata(t_data *img, t_params *params, int fd)
{
    int		x;
	int		y;
	unsigned int		*pixel;

	y = params->r.y - 1;
	while (y > -1)
	{
		x = 0;
		while (x < params->r.x)
		{
            //pixel = (unsigned int*)(img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8)));
			//i = (x + params->r.x * y) * PIXEL_LEN;
			pixel = (unsigned int *)(img->addr + (x + params->r.x * y) * PIXEL_LEN);
			if (write(fd, pixel, 3) < 0)
				error(3);
			x++;
		}
		y--;
	}
	printf("\nImage saved as '%s' in working dir.\n", FILENAME);
}

void		save_bmp(t_data *img, t_params *params, const char *filename)
{
	int		fd;

	fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, FILE_PERMISSIONS);
	if (!fd)
		error(3);
	write_bmpheaders(params, fd);
	write_bmpdata(img, params, fd);
	close(fd);
	exit(EXIT_SUCCESS);
}