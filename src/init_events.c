/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_events.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mintan <mintan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 14:04:54 by mintan            #+#    #+#             */
/*   Updated: 2024/09/14 16:36:16 by mintan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include "../include/ft_printf.h"
#include "../include/get_next_line.h"
#include "../include/fractol.h"

/* Description: events to be triggered when there are mouse events. Maps the
   scroll up and down button to the magnification factor, the number of
   iterations and the rng factor. Also converts the positon of the cursor and
   sets it as the origin of the complex plane. Used in the mlx_hook function:
*/

int	mouse_event(int button, int x, int y, t_fract *fract)
{
	t_cmplx	pix;

	pix = tf_pixel_to_cmplx(x, y, fract);
	fract->or_a = pix.re;
	fract->or_b = pix.img;
	if (button == 5)
	{
		fract->mag = (fract->mag) / MAG_STEP;
		fract->iter = fract->iter + 1;
		fract->rng = fract->rng + 1;
		fract->event = 1;
	}
	else if (button == 4)
	{
		fract->mag = (fract->mag) * MAG_STEP;
		fract->iter = fract->iter - 1;
		fract->rng = fract->rng -1;
		fract->event = 1;
	}
	return (0);
}

/* Description: events to be triggered when there are keyboard events.
   Any button press sets the fract.event to 1 to trigger a new image to be
   drawn. Used in the mlx_mouse_hook function:
	- ESC: closes the window
	- up, down, left, right: shifts the origin of the complex plane. This
	  causes the image on the window to "move"
	- + / ]: increase the number of iterations
	- - / [: decreases the number of iterations
	- space: resets the image to the original parameters, resetting the image
	  to the default
*/

int	key_event(int keysym, t_fract *fract)
{
	fract->event = 1;
	if (keysym == XK_Escape)
		close_window(fract);
	else if (keysym == XK_Up)
		fract->or_b = fract->or_b + (TRANS_STEP * fract->mag);
	else if (keysym == XK_Down)
		fract->or_b = fract->or_b - (TRANS_STEP * fract->mag);
	else if (keysym == XK_Right)
		fract->or_a = fract->or_a + (TRANS_STEP * fract->mag);
	else if (keysym == XK_Left)
		fract->or_a = fract->or_a - (TRANS_STEP * fract->mag);
	else if (keysym == XK_KP_Add || keysym == XK_bracketright)
		fract->iter += 10;
	else if (keysym == XK_KP_Subtract || keysym == XK_bracketleft)
		fract->iter -= 10;
	else if (keysym == XK_space)
		init_parameters(fract);
	return (0);
}

/* Description: function to be used in the mlx_loop_hook. Triggers the
   draw_fractal function when an event occurs as events change the parameters
   of the image.
*/

int	no_event(t_fract *fract)
{
	if (fract->event == 1)
	{
		draw_fractal(&(fract->img), fract);
		fract->event = 0;
	}
	return (0);
}

/* Description: Closes the window, destroys the image and destroys the display.
   This frees the memory allocated in the heap used by the minilibx. The
   function then exits the programme afterwards. This function is called when
   the window is closed either with the ESC key or the X button on the window
   is clicked.
*/

int	close_window(t_fract *fract)
{
	mlx_destroy_window(fract->mlx_ptr, fract->win_ptr);
	fract->win_ptr = NULL;
	mlx_destroy_image(fract->mlx_ptr, fract->img.mlx_img);
	fract->img.mlx_img = NULL;
	mlx_destroy_display(fract->mlx_ptr);
	free (fract->mlx_ptr);
	fract->mlx_ptr = NULL;
	exit (EXIT_SUCCESS);
}

/* Description: initialises all the mouse and key events using the
   mlx_mouse_hook and the mlx_hook functions.
*/

void	init_events(t_fract *fract)
{
	mlx_mouse_hook(fract->win_ptr, mouse_event, fract);
	mlx_hook(fract->win_ptr, DestroyNotify, NoEventMask, close_window, fract);
	mlx_hook(fract->win_ptr, KeyPress, KeyPressMask, key_event, fract);
}
