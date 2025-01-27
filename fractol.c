/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiskac <bkiskac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 17:59:50 by bkiskac           #+#    #+#             */
/*   Updated: 2025/01/27 20:07:35 by bkiskac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int main(int argc, char *argv[])
{
	t_fractal	fractal;

	if ((argc == 2 && !ft_strncmp(argv[1], "mandelbrot", 10))
		|| (argc == 4 && !ft_strncmp(argv[1], "julia", 5)))
	{
		instruction();
		argv[1][0] = ft_toupper(argv[1][0]);
		fractal.title = argv[1];
		if (!ft_strncmp(fractal.title, "Julia", 15))
		{
			fractal.julia_real = ft_atod(argv[2]);
			fractal.julia_i = ft_atod(argv[3]);
		}
		fractol_init(&fractal);
		fractol_render(&fractal);
		mlx_loop(fractal.mlx);
		return (0);
	}
	ft_printf("Error: Invalid arguments\n");
	ft_printf("Usage: ./fractol <mandelbrot>\n\t or \t\n");
	ft_printf("./fractol <julia> <real> <imaginary>\n");
	exit(EXIT_FAILURE);
}

