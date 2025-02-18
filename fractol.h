/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sngantch <sngantch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 22:20:03 by sngantch          #+#    #+#             */
/*   Updated: 2025/02/18 23:40:06 by sngantch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "minilibx_opengl_20191021/mlx.h"
# include "x11.h"
# include "colors.h"

# define ERROR_MESSAGE "Please enter \n\t\"./fractol mandelroot\" or \n\t\".fractol julia <value_1> <value_2>\""


# define WIDTH 800
# define HEIGHT 800




/* Complex value*/

typedef struct s_complex
{   //real
    double x;
    //i
    double y;
}       t_complex;

/* IMAGE 
.it's the pixels buffer 
. values from mlx_get_data_addr()
*/

typedef struct s_img
{
    void *img_ptr; // Pointer to image struct 
    char *pixels_ptr; // points to the actual pixels 
    int bpp; // bit per pixel
    int endian;
    int line_len;
}       t_img;



/* FRACTAL ID 
    MLX stuff
    Image
    Hooks values     
*/

typedef struct s_fractal
{
    char *name;
    //MLX
    void *mlx_connection;
    void *mlx_window;
    //Image
    t_img img;

    // Hooks member variables // TODOLATER
    double escape_value; // Hypotenuse
    int interation_definition; //Value tight witht the image quality and rendering speed
    double shift_x;
    double shift_y;
}           t_fractal;

int ft_strncmp(char *s1, char *s2, int n);
void    putstr_fd(char *s, int fd);

/* init*/
void fractal_init(t_fractal *fractal);

/* render*/
void fractal_render(t_fractal *fractal);

/*math*/
double map(double unscaled_num, double new_min, double new_max, double old_min, double old_max);
t_complex sum_complex(t_complex z1, t_complex z2);
t_complex square_complex(t_complex z);

/* hooks_event*/
int key_handler(int keysym, t_fractal *fractal);
int close_handler(t_fractal *fractal);
// int mouse_handler(int keysym);


#endif