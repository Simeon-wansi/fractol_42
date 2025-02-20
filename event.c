/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sngantch <sngantch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 15:39:20 by sngantch          #+#    #+#             */
/*   Updated: 2025/02/20 20:32:04 by sngantch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/* ESC or pressing X in the window */
int close_handler(t_fractal *fractal)
{
    mlx_destroy_image(fractal->mlx_connection,  // mlx_ptr
                        fractal->img.img_ptr); // img_ptr
    // mlx_clair_window(fractal->mlx_connection,
    //                     fractal->mlx_window);
    mlx_destroy_window(fractal->mlx_connection, // mlx_ptr
                        fractal->mlx_window); // win_ptr
    // mlx_destroy_display(fractal->mlx_connection); //mlx_ptr
    free(fractal->mlx_connection);
    exit(EXIT_SUCCESS);
}

/* KeyWord and prototype
int (*f)(int key)
*/

int key_handler(int keysym, t_fractal *fractal)
{
    if (keysym == XK_Escape)
         close_handler(fractal);
    else if (keysym == XK_Left )
        fractal->shift_x += 0.5;
    else if (keysym == XK_Right)
         fractal->shift_x -= 0.5;
    else if (keysym == XK_Up)
        fractal->shift_y += 0.5;
    else if (keysym == XK_Down)
        fractal->shift_y -= 0.5;
    // else if (keysym ==  DestroyNotify)
        
    // else if (keysym == XK_plus)
    //      fractal->interation_definition += 10;
    // else if (keysym == XK_minus)
    //     fractal->interation_definition -= 10;
    fractal_render(fractal); // refresh the image
    printf("%d\n", keysym);
    return (0);
}

// int mouse_handler(int keysym)
// {
    
// }

