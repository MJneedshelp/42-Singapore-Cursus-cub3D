/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mintan <mintan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 11:08:26 by mintan            #+#    #+#             */
/*   Updated: 2024/09/14 16:47:18 by mintan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

/* Description: converts the string portion behind the decimal point into a
   decimal.
*/
static	double	calc_decimal(const char *str)
{
	double	dec;
	double	ctr;

	ctr = 1;
	dec = 0;
	while (*str >= '0' && *str <= '9')
	{
		dec = dec + (*str++ - 48) / (pow(10, ctr));
		ctr++;
	}
	return (dec);
}

/* Description: converts the initial portion of the string pointed to by str to
   a double. Returns the converted value or 0 on error. */

double	ft_atod(const char *str)
{
	double	ret;
	double	neg;

	ret = 0.0;
	neg = 1;
	while ((*str >= '\t' && *str <= '\r') || *str == ' ')
		str++;
	if (*str == '-')
	{
		neg = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
		ret = (ret * 10) + (*str++ - 48);
	if (*str == '.')
		str++;
	ret = ret + calc_decimal(str);
	return (neg * ret);
}
