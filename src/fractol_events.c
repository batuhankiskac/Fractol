/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_events.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiskac <bkiskac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 18:30:17 by bkiskac           #+#    #+#             */
/*   Updated: 2025/01/31 15:35:33 by bkiskac          ###   ########.fr       */
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

int handle_key(int keysym, t_fractal *fractal)
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

int handle_mouse(int button, int x, int y, t_fractal *fractal)
{
	double mouse_real = (x - WIDTH / 2) / (0.5 * WIDTH * fractal->zoom)
		+ fractal->shift_real;
	double mouse_i = (y - HEIGHT / 2) / (0.5 * HEIGHT * fractal->zoom)
		+ fractal->shift_i;
	if (!ft_strncmp(fractal->title, "Julia", 5))
		julia_track(button, x, y, fractal);
	if (button == Button4)
		zoom_in(fractal, mouse_real, mouse_i);
	else if (button == Button5)
		zoom_out(fractal, mouse_real, mouse_i);
	fractol_render(fractal);
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
