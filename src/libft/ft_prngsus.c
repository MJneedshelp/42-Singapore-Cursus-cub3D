/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prngsus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mintan <mintan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 13:00:44 by mintan            #+#    #+#             */
/*   Updated: 2024/09/14 13:01:10 by mintan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Description: pseudo random integer generator. Takes in a 2 parameters,
   and does some funky mathematics to generate another number within the
   range of 0 - mod.
*/

int	ft_prngsus(int iter, int base, int mod)
{
	int	roll;

	roll = ((iter ^ base) + 42) % mod;
	return (roll);
}
