/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sngantch <sngantch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 05:38:49 by sngantch          #+#    #+#             */
/*   Updated: 2025/02/18 23:07:15 by sngantch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "fractol.h"



/* Put a pixel in m y image buffer */

static void my_pixel_put(int x, int y, t_img *img, int color)
{
    int offset;
    
    offset = (y * img->line_len) + (x *(img->bpp / 8));
    *(unsigned int *)(img->pixels_ptr + offset) =  color;
}

// here we check if a point is mandelroot point or not
/*
        _______800______
        |               |
        |               |
        |               |
        |______800______|
    z = z^2 + c 
    z initially is (0, 0)
    c is the actual point
*/


static void handle_pixel(int x, int y, t_fractal *fractal)
{
    t_complex z;
    t_complex c;
    int i;
    int color;
    
    i = 0;
    /* first iteration*/
    z.x = 0.0;
    z.y = 0.0;

    // pixel coordinate x and y scaled to fit mandel needs 
    c.x = map(x, -2, +2, 0, WIDTH) + fractal->shift_x; // unscaled_num, new_min, new_max, old_min, old_max
    c.y = map(y, +2, -2, 0, HEIGHT) + fractal->shift_y;

    //How many times we want to iterate z^2 + c
    // To check the point excaped

    while(i < fractal->interation_definition)
    {  /// z^2 + c
        // z - z^2 + c
        z =  sum_complex(square_complex(z), c); // z1;z2
        
        //is the value escaped?
        // if the hypotenuse > 2i assume the point escape
        
        if ((z.x * z.x) + (z.y * z.y) > fractal->escape_value)
        {
            color = map(i, BLACK, WHITE, 0, fractal->interation_definition );
            my_pixel_put(x, y, &fractal->img, color); // img
            return;
        }
        ++i;
    }
    // We are in MANDELBROT given iteration
    my_pixel_put(x, y, &fractal->img, BRIGHT_YELLOW); // img, color
}


void fractal_render(t_fractal *fractal)
{
    int x;
    int y;

    y = -1;
    while(++y < HEIGHT)
    {
        x = -1;
        while(++x < WIDTH)
        {
            handle_pixel(x, y, fractal);
        }
    }
    mlx_put_image_to_window(fractal->mlx_connection, //mlx_ptr:
                            fractal->mlx_window, // win_ptr
                            fractal->img.img_ptr,
                             0, 0); // x, y
}