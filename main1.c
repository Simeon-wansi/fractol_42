/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sngantch <sngantch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 18:56:51 by sngantch          #+#    #+#             */
/*   Updated: 2025/02/15 23:13:43 by sngantch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx_opengl_20191021/mlx.h"
#include <stdlib.h>  // For exit()

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

// int	main(void)
// {
// 	t_vars	vars;

// 	vars.mlx = mlx_init();
// 	if (!vars.mlx)
// 		return (1);
	
// 	vars.win = mlx_new_window(vars.mlx, 1920, 1080, "My Window");
// 	if (!vars.win)
// 		return (1);

// 	vars.img.img = mlx_new_image(vars.mlx, 1920, 1080);
// 	vars.img.addr = mlx_get_data_addr(vars.img.img, &vars.img.bits_per_pixel, &vars.img.line_length, &vars.img.endian);

// 	// Handle ESC key (keycode 53 on macOS)
// 	mlx_hook(vars.win, 17, 0, (void *)close_window, &vars);  // Handle window close event
// 	mlx_key_hook(vars.win, (void *)close_window, &vars);  // Handle ESC key

// 	mlx_loop(vars.mlx);

// 	return (0);
// }



// typedef struct	s_data {
// 	void	*img;
// 	char	*addr;
// 	int		bits_per_pixel;
// 	int		line_length;
// 	int		endian;
// }				t_data;


int	main(void)
{
	void	*mlx;
	t_data	img;

	mlx = mlx_init();
	img.img = mlx_new_image(mlx, 1920, 1080);

	/*
	** After creating an image, we can call `mlx_get_data_addr`, we pass
	** `bits_per_pixel`, `line_length`, and `endian` by reference. These will
	** then be set accordingly for the *current* data address.
	*/
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
}

// int main(void)
// {
//     void    *mlx;
//     void    *mlx_win;

//     mlx = mlx_init();
//     mlx_win = mlx_new_window(mlx, 1920, 1880, "Sim Dev!");
//     mlx_look(mlx);
// }