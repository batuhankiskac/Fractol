/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiskac <bkiskac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 17:59:50 by bkiskac           #+#    #+#             */
/*   Updated: 2025/01/25 18:22:47 by bkiskac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int main(int argc, char *argv[])
{
	t_fractol	fractol;

	if ((argc == 2 && !ft_strncmp(argv[1], "mandelbrot", 10))
		|| (argc == 4 && !ft_strncmp(argv[1], "julia", 5)))
	{
		instruction();
		argv[1][0] = ft_toupper(argv[1][0]);
		fractol.title = ft_strjoin("Fractol - ", argv[1]);
		if (!ft_strncmp(fractol.title, "Fractol - Julia", 15))
		{
			fractol.julia_real = ft_atod(argv[2]);
			fractol.julia_imaginary = ft_atod(argv[3]);
		}
		fractol_init(&fractol);
		fractol_render(&fractol);
		mlx_loop(fractol.mlx);
		return (0);
	}
	ft_printf("Error: Invalid arguments\n");
	ft_printf("Usage: ./fractol <mandelbrot>\n\t or \t\n");
	ft_printf("./fractol <julia> <real> <imaginary>\n");
	exit(EXIT_FAILURE);
}

