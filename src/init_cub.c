/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cub.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mintan <mintan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 01:09:25 by mintan            #+#    #+#             */
/*   Updated: 2025/02/04 10:59:44 by mintan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include "../include/ft_printf.h"
#include "../include/get_next_line.h"
#include "../include/cub3d.h"

/* Description: Initialises the cub structure, which holds all the
   information required for the programme. Used to pass information across
   the different functions in the programme:
	- mlx_ptr: pointer to a big structure storing a lot of minilibx info
	- win_ptr: pointer to the created window
	- t_img: struct to hold all the information required for the image
	- event: identifier to use to draw a new image when a mouse or key event
	  takes place
*/

t_cub	init_cub(char *argv[])
{
	t_cub	cub;

	cub.mlx_ptr = mlx_init();
	if (cub.mlx_ptr == NULL)
		exit (EXIT_FAILURE);
	cub.win_ptr = mlx_new_window(cub.mlx_ptr, WIN_LEN, WIN_HT, WIN_NAME);
	if (cub.win_ptr == NULL)
	{
		free (cub.mlx_ptr);
		exit (EXIT_FAILURE);
	}
	cub.img.mlx_img = mlx_new_image(cub.mlx_ptr, WIN_LEN, WIN_HT);
	cub.img.addr = mlx_get_data_addr(cub.img.mlx_img, &(cub.img.bpp), \
	&(cub.img.line_len), &(cub.img.endian));

	cub.event = 1;
	return (cub);
}

/* Description: function to put pixels on to an image. This is used instead of
	mlx_pixel_put. Maps the x and y coordinates of the pixel to a memory
	address of an image.
*/

void	img_pixel_put(t_img *img, int x, int y, int color)
{
	char	*pixel;

	pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(unsigned int *)pixel = color;
}
