/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_utils_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiskac <bkiskac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 18:08:51 by bkiskac           #+#    #+#             */
/*   Updated: 2025/01/27 17:19:01 by bkiskac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	instruction(void)
{
	ft_printf("To move the fractal, use the arrow keys or WASD\n");
	ft_printf("To zoom in and out, use the mouse wheel\n");
	ft_printf("To change the color, use space key\n");
	ft_printf("To change the iterations, use the + and - keys\n");
	ft_printf("To rotate the Julia, use left or right mouse button\n");
	ft_printf("To quit, use the ESC key or simply click X on the window\n");
	ft_printf("Example Julia Sets:\n");
	ft_printf("./fractol julia -0.4 +0.6\n");
	ft_printf("./fractol julia -0.835 -0.2321\n");
}

void	malloc_error(void)
{
	perror("Malloc Error: ");
	exit(EXIT_FAILURE);
}

double	ft_atod(char *s)
{
	long	integral;
	double	fractional;
	double	power;
	int		sign;

	integral = 0;
	fractional = 0.0;
	sign = 1;
	power = 1.0;
	while (*s == '0' || (*s >= 9) && (*s <= 12))
		*s++;
	while (*s == '+' || *s == '-')
		if (*s == '-')
			sign *= -1;
	while (*s && *s != '.')
		integral = integral * 10 + (*s++ - '0');
	if (*s == '.')
		*s++;
	while (*s)
	{
		power /= 10;
		fractional = fractional + (*s++ - '0') * power;
	}
	return ((integral + fractional) * sign);
}

t_fractal	square_complex(t_fractal z)
{
	t_fractal	res;

	res.compl_real = (z.compl_real * z.compl_real) - (z.compl_i * z.compl_i);
	res.compl_i = 2 * z.compl_real * z.compl_i;
	return (res);
}

t_fractal	sum_complex(t_fractal z1, t_fractal z2)
{
	t_fractal	res;
	
	res.compl_real = z1.compl_real + z2.compl_real;
	res.compl_i = z1.compl_i + z2.compl_i;
	return (res);
}
