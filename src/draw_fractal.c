/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fractal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mintan <mintan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 09:10:59 by mintan            #+#    #+#             */
/*   Updated: 2024/09/14 16:56:12 by mintan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include "../include/ft_printf.h"
#include "../include/get_next_line.h"
#include "../include/fractol.h"

/* Description: checks if a given complex number is part of the mandelbrot set
   given the number of iterations n.
   Actions:
	- Calculate the ith term of the mandelbrot equation for each iteration
	  until the nth term term
	  	- Mandelbrot equation: Z_n+1 = (Z_n)^2 + C
	- Check the magnitude of the ith term
		- If the magnitude |z_i| =< 2: part of the mandelbrot set
		- If the magnitude |z_i| > 2: not part of the mandelbrot set. Break and
		return the number of iterations when the it diverges
	- Return 0 if |z_n| =< 2
*/

int	check_mandelbrot(t_cmplx input, int no_iter)
{
	t_cmplx	term;
	int		i;

	term.re = 0.0;
	term.img = 0.0;
	i = 0;
	while (i < no_iter)
	{
		term = sum_cmplx(sqr_cmplx(term), input);
		i++;
		if (magnitude_cmplx(term) > 2)
			return (i);
	}
	return (0);
}

/* Description: checks if a given complex number is part of the julia set
   given the number of iterations n as well as the real and imaginary terms of
   the complex number in the julia set.
   Actions:
	- Calculate the ith term of the julia equation for each iteration
	  until the nth term term
	  	- Julia equation: Z_n+1 = (Z_n)^2 + C
		- Z_0: current position on the complex plan
		- C: given complex term
	- Check the magnitude of the ith term
		- If the magnitude |z_i| =< 2: part of the julia set
		- If the magnitude |z_i| > 2: not part of the julia set. Break and
		return the number of iterations when the it diverges
	- Return 0 if |z_n| =< 2
*/

int	check_julia(t_cmplx input, t_cmplx c_term, int no_iter)
{
	t_cmplx	term;
	int		i;

	term.re = input.re;
	term.img = input.img;
	i = 0;
	while (i < no_iter)
	{
		term = sum_cmplx(sqr_cmplx(term), c_term);
		i++;
		if (magnitude_cmplx(term) > 2)
			return (i);
	}
	return (0);
}

/* Description: Generates a colour by taking in an integer and passing it
   into a pseudo random number generator to generate a random integer
   corresponding to the red, green or blue value. Uses bitwise operations
   to combine the integers of each red, green and blue value into a 32 bit
   integer.
*/

int	gen_colour(int iter, t_fract *fract)
{
	uint8_t	red;
	uint8_t	green;
	uint8_t	blue;

	red = ft_prngsus(iter, fract->rng, 255);
	green = ft_prngsus(iter, fract->rng * 2, 255);
	blue = ft_prngsus(iter, fract->rng * 3, 255);
	return (red << 16 | green << 8 | blue);
}

/* Description: Draws a fractal into an image.
   Actions:
	1. For each pixel in the window, convert the pixel coordinates into complex
	   coordinates
	2. Check if the the complex coordinates lies within the fractal set.
		- In set: colour black
		- Not in set: generate a pseudo-random colour
*/

int	draw_fractal(t_img *img, t_fract *fract)
{
	int		x;
	int		y;
	t_cmplx	pix;
	int		esc;

	x = 0;
	while (x++ < WIN_LEN)
	{
		y = 0;
		while (y++ < WIN_HT)
		{
			pix = tf_pixel_to_cmplx(x, y, fract);
			if (fract->set == 1)
				esc = check_mandelbrot(pix, fract->iter);
			else
				esc = check_julia(pix, fract->j_term, fract->iter);
			if (esc == 0)
				img_pixel_put(img, x - 1, y - 1, COLOR_BLACK);
			else
				img_pixel_put(img, x - 1, y - 1, gen_colour(esc, fract));
		}
	}
	mlx_put_image_to_window(fract->mlx_ptr, fract->win_ptr, \
	fract->img.mlx_img, 0, 0);
	return (0);
}
