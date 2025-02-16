 #include "fractol.h"

/* if the allocation does go well*/
void    malloc_error(void)
{
    perror("problems with mallloc"); //s:
    exit(EXIT_FAILURE); //status:
}


 /* 
 .INIT 
 . ~mlx 
 . ~listening events
 . ~hools data
 */

void fractal_init(t_fractal *fractal)
{
    // MLX stuff
    fractal->mlx_connection = mlx_init();
    if (NULL == fractal->mlx_connection)
        malloc_error();// To do later 
    fractal->mlx_window = mlx_new_window(fractal->mlx_connection, WIDTH, HEIGHT, 
                                            fractal->name);// title:

    if ( NULL == fractal->mlx_window)
    {
        mlx_destroy_display(fractal->mlx_connection);// mlx_ptr:
        free(fractal->mlx_connection);
        malloc_error();
    }
    fractal->img.img_ptr = mlx_new_image(fractal->mlx_connection, WIDTH, HEIGHT);

    if (NULL == fractal->img.img_ptr)
    {
        mlx_destroy_window(fractal->mlx_connection, fractal->mlx_window);
        mlx_destroy_display(fractal->mlx_connection);// mlx_ptr:
        free(fractal->mlx_connection);
        malloc_error();
    }

    fractal->img.pixels_ptr = mlx_get_data_addr(fractal->img.img_ptr, 
                                                &fractal->img.bpp,
                                                &fractal->img.line_len,
                                                &fractal->img.endian);

    // events_init() // to do later
    // data_init(fractal) // todo later
}