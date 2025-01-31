/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiskac <bkiskac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 12:45:00 by bkiskac           #+#    #+#             */
/*   Updated: 2025/01/31 15:35:33 by bkiskac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int blend_colors(int color1, int color2, double t)
{
	int r1 = (color1 >> 16) & 0xFF;
	int g1 = (color1 >> 8) & 0xFF;
	int b1 = color1 & 0xFF;
	int r2 = (color2 >> 16) & 0xFF;
	int g2 = (color2 >> 8) & 0xFF;
	int b2 = color2 & 0xFF;

	int r = (int)((1.0 - t) * r1 + t * r2);
	int g = (int)((1.0 - t) * g1 + t * g2);
	int b = (int)((1.0 - t) * b1 + t * b2);

	return ((r << 16) | (g << 8) | b);
}

void color_shift(t_fractal *fractal)
{
	static int colors[] = {WHITE, DEEP_PURPLE, INDIGO, AZURE, TURQUOISE,
		SPRING_GREEN, CHARTREUSE, GOLDEN, CORAL, CRIMSON, VIOLET,
		AQUA, ELECTRIC_BLUE, HOT_PINK, NEON_GREEN};
	static int color_index;

	color_index = (color_index + 1)
		% (sizeof(colors) / sizeof(colors[0]));
	fractal->color = colors[color_index];
	fractol_render(fractal);
}
