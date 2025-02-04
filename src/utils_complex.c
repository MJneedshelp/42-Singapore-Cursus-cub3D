/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_complex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mintan <mintan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 16:30:00 by mintan            #+#    #+#             */
/*   Updated: 2024/09/14 16:20:35 by mintan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include "../include/ft_printf.h"
#include "../include/get_next_line.h"
#include "../include/fractol.h"

/* Description: calculates the square of a complex number. Returns a complex
   number in the form of a structure that contains the real and imaginary
   parts of the complex number.
*/

t_cmplx	sqr_cmplx(t_cmplx input)
{
	t_cmplx	res;

	res.re = (input.re * input.re) - (input.img * input.img);
	res.img = 2 * input.re * input.img;
	return (res);
}

/* Description: calculates the sum of 2 complex numbers. Sums the real and
   imaginary parts of the number individually. Returns a complex number in
   the form of a structure that contains the real and imaginary parts of
   the complex number.
*/

t_cmplx	sum_cmplx(t_cmplx input1, t_cmplx input2)
{
	t_cmplx	res;

	res.re = input1.re + input2.re;
	res.img = input1.img + input2.img;
	return (res);
}

/* Description: calculates the magnitude of a complex number.
   - Complex number input: a + bi
   - Magnitude = sqrt(a^2 + b^2)
   Return: magnitude of the complex number as a double
*/

double	magnitude_cmplx(t_cmplx input)
{
	double	ret;

	ret = sqrt((input.re * input.re) + (input.img * input.img));
	return (ret);
}

/* Description: takes in the pixel coordinates and applies a formula to
   transform it to a complex number on the complex plane. The formula scales
   based on the magnification factor and translates left, right, up, down
   based on the given origin.
*/

t_cmplx	tf_pixel_to_cmplx(int p_x, int p_y, t_fract *fract)
{
	t_cmplx	res;

	res.re = fract->mag * ((double)p_x / WIN_LEN * U_A - (U_A / 2)) + \
	fract->or_a;
	res.img = fract->mag * ((double)-p_y / WIN_HT * U_B + (U_B / 2)) + \
	fract->or_b;
	return (res);
}
