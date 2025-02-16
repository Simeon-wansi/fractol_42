/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sngantch <sngantch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 23:14:52 by sngantch          #+#    #+#             */
/*   Updated: 2025/02/16 03:19:56 by sngantch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx_opengl_20191021/mlx.h"
#include <stdlib.h>  // For exit()
#include <stdio.h>

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
} t_data;

typedef struct s_vars {
	void	*mlx;
	void	*win;
	t_data	img;
} t_vars;

// Function to handle key press (ESC to exit)
int	close_window(t_vars *vars)
{
	mlx_destroy_image(vars->mlx, vars->img.img);
	mlx_destroy_window(vars->mlx, vars->win);
	exit(0); // Properly exit the program
}

void my_mlx_pixel_put(t_data  *data, int x, int y, int color)
{
    char    *dst;
    
    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}


void draw_square(t_data *img, int start_x, int start_y,  int size, int color)
{
    int x;
    int y;

    y = start_y;
    while(y <= 40)
    {    
        x = start_x;
        while(x <= size)
        {
            my_mlx_pixel_put(img, x, y, color);
            x++;
        }
        y++;
    }
}

// void draw_circle(t_data *img, int start_x, int raduis, int color)
// {
    
// }

// int key_hook(int keycode, t_vars *vars)
// {
//     (t_vars *)vars;
//     printf("Hello from key_hook! %d\n", keycode);
//     return (0);
// }


int	main(void)
{
	t_vars	vars;
    
	vars.mlx = mlx_init();
	if (!vars.mlx)
		return (1);
	
	vars.win = mlx_new_window(vars.mlx, 1920, 1080, "My Window");
	if (!vars.win)
		return (1);

	vars.img.img = mlx_new_image(vars.mlx, 1920, 1080);
	vars.img.addr = mlx_get_data_addr(vars.img.img, &vars.img.bits_per_pixel, &vars.img.line_length, &vars.img.endian);


    for (int i = 0; i < 1920 * 1080; i++) {
		((unsigned int*)vars.img.addr)[i] = 0x00000000;  // Clear to black (or any color)
	}
    
    draw_square(&vars.img, 5, 5, 50, 0x00FF0000);
    printf("First square drawn\n");

    mlx_put_image_to_window(vars.mlx, vars.win, vars.img.img, 0, 0);
    
    draw_square(&vars.img, 100, 100, 50, 0xFFFFFF00);
    printf("Second square drawn\n");
    
    mlx_put_image_to_window(vars.mlx, vars.win, vars.img.img, 0, 0);
    printf("Image flushed to window\n");


    // mlx_key_hook(vars.win, key_hook, &vars);
	// Handle ESC key (keycode 53 on macOS)
	mlx_hook(vars.win, 17, 0, (void *)close_window, &vars);  // Handle window close event
	mlx_key_hook(vars.win, (void *)close_window, &vars);  // Handle ESC key

	mlx_loop(vars.mlx);

	return (0);
}