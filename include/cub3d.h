/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mintan <mintan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 15:52:13 by mintan            #+#    #+#             */
/*   Updated: 2025/02/04 11:43:28 by mintan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <mlx.h>
# include <math.h>
# include <unistd.h>
# include <X11/keysym.h>
# include <X11/X.h>
# include <stdint.h>

# define WIN_HT 600.0
# define WIN_LEN 800.0
# define WIN_NAME "SANZAI-D"
# define COLOR_BLACK 0x000000

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_cub
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	img;
	int		event;
}	t_cub;



/* MJ TO POPULATE THIS LATER*/

/* Initialisation functions */
t_cub	init_cub(void);
void	init_events(t_cub *cub);
void	img_pixel_put(t_img *img, int x, int y, int color);

/* Hook functions used in the mlx hook functions */
// int		mouse_event(int button, int x, int y, t_fract *fract);
int		key_event(int keysym, t_cub *cub);
int		no_event(t_cub *cub);
int		close_window(t_cub *cub);


// /* Complex number operations */
// t_cmplx	sqr_cmplx(t_cmplx input);
// t_cmplx	sum_cmplx(t_cmplx input1, t_cmplx input2);
// double	magnitude_cmplx(t_cmplx input);
// t_cmplx	tf_pixel_to_cmplx(int p_x, int p_y, t_fract *fract);

// /* Draw Fractal functions */
// int		check_mandelbrot(t_cmplx input, int no_iter);
// int		draw_fractal(t_img *img, t_fract *fract);
// int		check_julia(t_cmplx input, t_cmplx c_term, int no_iter);


#endif
