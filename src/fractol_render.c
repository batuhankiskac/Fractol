/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_render.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiskac <bkiskac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 20:22:00 by bkiskac           #+#    #+#             */
/*   Updated: 2025/01/27 20:30:13 by bkiskac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

static void	fractol_set(t_fractal *z, t_fractal *c, t_fractal *fract)
{
	if (!ft_strncmp(fract->title, "Julia", 5))
	{
		c->compl_real = fract->julia_real;
		c->compl_i = fract->julia_i;
	}
	else
	{
		c->compl_real = z->compl_real;
		c->compl_i = z->compl_i;
	}
}

void	fractol_render(t_fractal *fractal)
{
	int	x;
	int	y;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
			get_complex_map(x, y, fractal);
	}
	mlx_put_image_to_window(fractal->mlx, fractal->win, fractal->img, 0, 0);
}
