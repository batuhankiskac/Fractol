/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiskac <bkiskac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 17:59:50 by bkiskac           #+#    #+#             */
/*   Updated: 2025/01/25 18:19:13 by bkiskac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int main(int argc, char const *argv[])
{
	t_fractol	fractol;

	if ((argc == 2 && !ft_strncmp(argv[1], "mandelbrot", 10))
		|| (argc == 4 && !ft_strncmp(argv[1], "julia", 5)))
	{
		instruction();
		return (0);
	}
	ft_printf("Error: Invalid arguments\n");
	ft_printf("Usage: ./fractol <mandelbrot>\n\t or \t\n");
	ft_printf("./fractol <julia> <real> <imaginary>\n");
	exit(EXIT_FAILURE);
}

