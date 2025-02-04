/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fractal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mintan <mintan@stuident.42singapore.sg>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 09:10:59 by mintan            #+#    #+#             */
/*   Updated: 2025/02/04 12:12:43 by mintan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include "../include/ft_printf.h"
#include "../include/get_next_line.h"
#include "../include/cub3d.h"

/* Description: Draws a fractal into an image.
   Actions:
	1. For each pixel in the window, draw a colour
*/

int	draw_fractal(t_img *img, t_cub *cub)
{
	int		x;
	int		y;

	x = 0;
	while (x++ < WIN_LEN)
	{
		y = 0;
		while (y++ < WIN_HT)
		{

			img_pixel_put(img, x - 1, y - 1, COLOR_TEAL);

		}
	}
	mlx_put_image_to_window(cub->mlx_ptr, cub->win_ptr, \
	cub->img.mlx_img, 0, 0);
	return (0);
}
