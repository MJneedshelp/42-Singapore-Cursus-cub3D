/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mintan <mintan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 16:20:22 by mintan            #+#    #+#             */
/*   Updated: 2025/02/04 10:59:45 by mintan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include "../include/ft_printf.h"
#include "../include/get_next_line.h"
#include "../include/cub3d.h"

int	main(int argc, char *argv[])
{
	t_cub	cub;

	cub = init_cub(argv);
	
	
	
	
	init_events(&cub);
	mlx_loop_hook(cub.mlx_ptr, &no_event, &cub);
	mlx_loop(cub.mlx_ptr);
}
