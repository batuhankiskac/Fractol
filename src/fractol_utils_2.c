/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_utils_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiskac <bkiskac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 16:47:40 by bkiskac           #+#    #+#             */
/*   Updated: 2025/01/31 17:26:50 by bkiskac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

double	map(t_map coords)
{
	return ((coords.new_max - coords.new_min)
		* (coords.unscaled_num - coords.old_min)
		/ (coords.old_max - coords.old_min) + coords.new_min);
}

void	zoom_in(t_fractal *fractal, double mouse_real, double mouse_i)
{
	double	zoom_factor;

	zoom_factor = 0.95;
	fractal->shift_real += (mouse_real - fractal->shift_real)
		* (1.0 - zoom_factor);
	fractal->shift_i += (mouse_i - fractal->shift_i) * (1.0 - zoom_factor);
	fractal->zoom *= zoom_factor;
}

void	zoom_out(t_fractal *fractal, double mouse_real, double mouse_i)
{
	double	zoom_factor;

	zoom_factor = 1.05;
	fractal->shift_real += (mouse_real - fractal->shift_real)
		* (1.0 - zoom_factor);
	fractal->shift_i += (mouse_i - fractal->shift_i) * (1.0 - zoom_factor);
	fractal->zoom *= zoom_factor;
}
