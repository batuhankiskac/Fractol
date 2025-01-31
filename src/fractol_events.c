/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_events.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiskac <bkiskac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 18:30:17 by bkiskac           #+#    #+#             */
/*   Updated: 2025/01/31 16:57:45 by bkiskac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

static int julia_track(int button, int x, int y, t_fractal *fractal)
{
	if (button == Button1 || button == Button3)
	{
		fractal->julia_real = (map((t_map){x, -2, +2, 0, WIDTH}) * fractal->zoom)
			+ fractal->shift_real;
		fractal->julia_i = (map((t_map){y, +2, -2, 0, HEIGHT}) * fractal->zoom)
			+ fractal->shift_i;
		fractol_render(fractal);
	}
	return (0);
}

int	handle_key(int keysym, t_fractal *fract)
{
	if (keysym == XK_Escape)
		handle_close(fract);
	else if (keysym == XK_Left || keysym == XK_a)
		fract->shift_real -= (0.1 * fract->zoom);
	else if (keysym == XK_Right || keysym == XK_d)
		fract->shift_real += (0.1 * fract->zoom);
	else if (keysym == XK_Up || keysym == XK_w)
		fract->shift_i += (0.1 * fract->zoom);
	else if (keysym == XK_Down || keysym == XK_s)
		fract->shift_i -= (0.1 * fract->zoom);
	else if (keysym == XK_KP_Add)
		fract->iterations += 32;
	else if (keysym == XK_KP_Subtract)
		fract->iterations -= 32;
	else if (keysym == XK_space)
		color_shift(fract);
	fractol_render(fract);
	return (0);
}

int handle_mouse(int button, int x, int y, t_fractal *fract)
{
	double mouse_r;
	double mouse_i;

	mouse_r = (x - WIDTH / 2) / (0.5 * WIDTH * fract->zoom) + fract->shift_real;
	mouse_i = (HEIGHT / 2 - y) / (0.5 * HEIGHT * fract->zoom) + fract->shift_i;
	if (!ft_strncmp(fract->title, "Julia", 5))
		julia_track(button, x, y, fract);
	if (button == Button4)
		zoom_in(fract, mouse_r, mouse_i);
	else if (button == Button5)
		zoom_out(fract, mouse_r, mouse_i);
	fractol_render(fract);
	return (0);
}

int handle_close(t_fractal *fractal)
{
	mlx_destroy_image(fractal->mlx, fractal->img);
	mlx_destroy_window(fractal->mlx, fractal->win);
	mlx_destroy_display(fractal->mlx);
	free(fractal->mlx);
	exit(EXIT_SUCCESS);
}
