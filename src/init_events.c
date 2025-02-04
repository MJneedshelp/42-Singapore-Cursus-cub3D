/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_events.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mintan <mintan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 14:04:54 by mintan            #+#    #+#             */
/*   Updated: 2025/02/04 11:42:13 by mintan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include "../include/ft_printf.h"
#include "../include/get_next_line.h"
#include "../include/cub3d.h"

/* Description: events to be triggered when there are mouse events. Maps the
   scroll up and down button to the magnification factor, the number of
   iterations and the rng factor. Also converts the positon of the cursor and
   sets it as the origin of the complex plane. Used in the mlx_hook function:
*/

/* MJ TO DECIDE LATER IF YOU WANT TO KEEP ANY OF THE MOUSE EVENTS IN

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

*/

/* Description: events to be triggered when there are keyboard events.
   Any button press sets the cub.event to 1 to trigger a new image to be
   drawn. Used in the mlx_mouse_hook function:
	- ESC: closes the window
	- MJ TO ADD IN THE OTHER KEY PRESS ITEMS AFTERWARDS
*/

int	key_event(int keysym, t_cub *cub)
{
	cub->event = 1;
	if (keysym == XK_Escape)
		close_window(cub);
	// else if (keysym == XK_Up)
	// else if (keysym == XK_Down)
	// else if (keysym == XK_Right)
	// else if (keysym == XK_Left)
	// else if (keysym == XK_space)
	// 	init_parameters(cub);
	return (0);
}

/* Description: function to be used in the mlx_loop_hook. Triggers the
   draw_game function when an event occurs as events change the parameters
   of the image.
*/

int	no_event(t_cub *cub)
{
	if (cub->event == 1)
	{
		// draw_game(&(cub->img), cub);
		cub->event = 0;
	}
	return (0);
}

/* Description: Closes the window, destroys the image and destroys the display.
   This frees the memory allocated in the heap used by the minilibx. The
   function then exits the programme afterwards. This function is called when
   the window is closed either with the ESC key or the X button on the window
   is clicked.
*/

int	close_window(t_cub *cub)
{
	mlx_destroy_window(cub->mlx_ptr, cub->win_ptr);
	cub->win_ptr = NULL;
	mlx_destroy_image(cub->mlx_ptr, cub->img.mlx_img);
	cub->img.mlx_img = NULL;
	mlx_destroy_display(cub->mlx_ptr);
	free (cub->mlx_ptr);
	cub->mlx_ptr = NULL;
	exit (EXIT_SUCCESS);
}

/* Description: initialises all the mouse and key events using the
   mlx_mouse_hook and the mlx_hook functions.
*/

void	init_events(t_cub *cub)
{
	// mlx_mouse_hook(cub->win_ptr, mouse_event, cub);
	mlx_hook(cub->win_ptr, DestroyNotify, NoEventMask, close_window, cub);
	mlx_hook(cub->win_ptr, KeyPress, KeyPressMask, key_event, cub);
}
