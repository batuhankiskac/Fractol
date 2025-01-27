/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_utils_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiskac <bkiskac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 16:47:40 by bkiskac           #+#    #+#             */
/*   Updated: 2025/01/27 17:20:11 by bkiskac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

double	map(t_map coords)
{
	return ((coords.new_max - coords.new_min) *
		(coords.unscaled_num - coords.old_min) /
		(coords.old_max - coords.old_min) + coords.new_min);
}

void	zoom_in(t_fractal *fract, double mouse_real, double mouse_i)
{
	double	zoom_factor;

	zoom_factor = 0.95;
	fract->shift_real += (mouse_real - fract->shift_real) * (1 - zoom_factor);
	fract->shift_i += (mouse_i - fract->shift_i) * (1 - zoom_factor);
	fract->zoom *= zoom_factor;
}

void	zoom_out(t_fractal *fract, double mouse_real, double mouse_i)
{
	double	zoom_factor;

	zoom_factor = 1.05;
	fract->shift_real += (mouse_real - fract->shift_real) * (1 - zoom_factor);
	fract->shift_i += (mouse_i - fract->shift_i) * (1 - zoom_factor);
	fract->zoom *= zoom_factor;
}
