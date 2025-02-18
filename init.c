 #include "fractol.h"


/* if the allocation does go well*/
void    malloc_error(void)
{
    perror("problems with mallloc"); //s:
    exit(EXIT_FAILURE); //status:
}


void data_init(t_fractal *fractal)
{
    fractal->escape_value = 4; // 2^2, my hypotenuse
    fractal->interation_definition = 42;
    fractal->shift_x = 0.0;
    fractal->shift_y = 0.0;
}

// void mlx_hook(mlx_win_list_t *win_ptr, int x_event, int x_mask, int (*f)(), void *param)
static void events_init(t_fractal *fractal)
{
    mlx_hook(fractal->mlx_window, //win_ptr
            KeyPress, // x_event :  KeyPress
            KeyPressMask, // x_max: KeyPressMask
            key_handler, // handling the keycodes
            fractal ); //param
    // mlx_hook(fractal->mlx_window, //winptr
    //         ButtonPress, // x_event
    //         ButtonPressMask, // x_max
    //         mouse_handler, // todo later
    //         fractal ); // param
    mlx_hook(fractal->mlx_window, //winptr
            DestroyNotify, // x_event
            StructureNotifyMask, // x_max
            close_handler, // todo later
            fractal ); // param
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
        mlx_destroy_window(fractal->mlx_connection, fractal->mlx_window);// mlx_ptr:
        free(fractal->mlx_connection);
        malloc_error();
    }
    fractal->img.img_ptr = mlx_new_image(fractal->mlx_connection, WIDTH, HEIGHT);

    if (NULL == fractal->img.img_ptr)
    {
        mlx_destroy_window(fractal->mlx_connection, fractal->mlx_window);
        mlx_destroy_image(fractal->mlx_connection, fractal->img.img_ptr);// mlx_ptr:img_ptr
        free(fractal->mlx_connection);
        malloc_error();
    }

    fractal->img.pixels_ptr = mlx_get_data_addr(fractal->img.img_ptr, 
                                                &fractal->img.bpp,
                                                &fractal->img.line_len,
                                                &fractal->img.endian);

    events_init(fractal);
    data_init(fractal);
}