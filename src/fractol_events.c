/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_events.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiskac <bkiskac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 18:30:17 by bkiskac           #+#    #+#             */
/*   Updated: 2025/01/27 17:34:35 by bkiskac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

static int	julia_track(int button, int x, int y, t_fractal *fract)
{
	if (button == Button1 || button == Button3)
	{
		fract->julia_real =
	}
	return (0);
}

int	handle_key(int keysym, t_fractal *fractal)
{
	if (keysym == XK_Escape)
		handle_close(fractal);
	else if (keysym == XK_Left || keysym == XK_a)
		fractal->shift_real += (0.1 * fractal->zoom);
	else if (keysym == XK_Right || keysym == XK_d)
		fractal->shift_real -= (0.1 * fractal->zoom);
	else if (keysym == XK_Up || keysym == XK_w)
		fractal->shift_i -= (0.1 * fractal->zoom);
	else if (keysym == XK_Down || keysym == XK_s)
		fractal->shift_i += (0.1 * fractal->zoom);
	else if (keysym == XK_KP_Add)
		fractal->iterations += 32;
	else if (keysym == XK_KP_Subtract)
		fractal->iterations -= 32;
	else if (keysym == XK_space)
		color_shift(fractal);
	fractol_render(fractal);
	return (0);
}

int	handle_mouse(int button, int x, int y, t_fractal *fractal)
{

}

int	handle_close(t_fractal *fractal)
{
	mlx_destroy_image(fractal->mlx, fractal->img);
	mlx_destroy_window(fractal->mlx, fractal->win);
	mlx_destroy_display(fractal->mlx);
	free(fractal->mlx);
	exit(EXIT_SUCCESS);
}
