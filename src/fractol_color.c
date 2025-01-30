/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiskac <bkiskac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 12:45:00 by bkiskac           #+#    #+#             */
/*   Updated: 2025/01/30 11:34:18 by bkiskac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	blend_colors(int color1, int color2, double t)
{
	int	r;
	int	g;
	int	b;

	r = (1 - t) * ((color1 & 0xFF) >> 16) + t * ((color2 & 0xFF) >> 16);
	g = (1 - t) * ((color1 & 0xFF) >> 8) + t * ((color2 & 0xFF) >> 8);
	b = (1 - t) * (color1 & 0xFF) + t * (color2 & 0xFF);
	return ((r << 16) | (g << 8) | b);
}

void	color_shift(t_fractal *fractal)
{
	static int	colors[] = {WHITE, DEEP_PURPLE, INDIGO, AZURE, TURQUOISE, SPRING_GREEN, CHARTREUSE, GOLDEN, CORAL, CRIMSON, VIOLET, AQUA, ELECTRIC_BLUE, HOT_PINK, NEON_GREEN};
	static int	color_index;

	color_index = (color_index + 1) % (sizeof(colors) / sizeof(colors[0]));
	fractal->color = colors[color_index];
	fractol_render(fractal);
}
