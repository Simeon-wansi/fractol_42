
#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "minilibx_opengl_20191021/mlx.h"

# define ERROR_MESSAGE "Please enter \n\t\"./fractol mandelroot\" or \n\t\".fractol julia <value_1> <value_2>\""


# define WIDTH 800
# define HEIGHT 800
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
}           t_fractal;

int ft_strncmp(char *s1, char *s2, int n);
void    putstr_fd(char *s, int fd);

/* init*/

void fractal_init(t_fractal *fractal);

# endif