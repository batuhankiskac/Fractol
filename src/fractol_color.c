/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiskac <bkiskac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 12:45:00 by bkiskac           #+#    #+#             */
/*   Updated: 2025/02/05 22:04:10 by bkiskac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	blend_colors(int color1, int color2, double t)
{
	int	r;
	int	g;
	int	b;

	r = (int)((1 - t) * ((color1 >> 16) & 0xFF)
			+ t * ((color2 >> 16) & 0xFF) * 3);
	g = (int)((1 - t) * ((color1 >> 8) & 0xFF)
			+ t * ((color2 >> 8) & 0xFF) * 3);
	b = (int)((1 - t) * (color1 & 0xFF)
			+ t * (color2 & 0xFF) * 3);
	r = (int)(r + (255 - r) * t * 2);
	g = (int)(g + (255 - g) * t * 0.1);
	b = (int)(b + (255 - b) * t * 4);
	return ((r << 16) | (g << 8) | b);
}

void	color_shift(t_fractal *fractal)
{
	static int	colors[] = {WHITE, DEEP_PURPLE, INDIGO, AZURE, TURQUOISE,
		SPRING_GREEN, CHARTREUSE, GOLDEN, CORAL, CRIMSON, VIOLET,
		AQUA, ELECTRIC_BLUE, HOT_PINK, NEON_GREEN};
	static int	color_index;

	color_index = (color_index + 1)
		% (sizeof(colors) / sizeof(colors[0]));
	fractal->color = colors[color_index];
	fractol_render(fractal);
}
