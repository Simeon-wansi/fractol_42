/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sngantch <sngantch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 03:46:29 by sngantch          #+#    #+#             */
/*   Updated: 2025/02/16 05:22:33 by sngantch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* We have 2 promts 
    ~./fractol mandelroot 
    ~./fractol julia <real> <i>

*/
#include "fractol.h"
#include <string.h>

int main(int ac,  char **av)
{
    t_fractal fractal;
    
    if ((2 == ac && !ft_strncmp(av[1], "mandelroot", 10))
        || (4 == ac && !strncmp(av[1], "julia", 5)))
    {
        fractal.name = av[1];
        // TL; DR
        // Id the promps is coorect , kick off th app
        fractal_init(&fractal);
        // fractal_render(&fractal);
        mlx_loop(fractal.mlx_connection);
    }
    else
    {
        putstr_fd(ERROR_MESSAGE, STDERR_FILENO);
        exit(EXIT_FAILURE);
    }
}
