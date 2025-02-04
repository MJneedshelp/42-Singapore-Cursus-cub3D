/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mintan <mintan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 16:20:22 by mintan            #+#    #+#             */
/*   Updated: 2025/02/04 11:38:59 by mintan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include "../include/ft_printf.h"
#include "../include/get_next_line.h"
#include "../include/cub3d.h"

// int	main(int argc, char *argv[])
int	main(void)
{
	t_cub	cub;

	cub = init_cub();
	
	
	
	
	init_events(&cub);
	mlx_loop_hook(cub.mlx_ptr, &no_event, &cub);
	mlx_loop(cub.mlx_ptr);
}
