/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiskac <bkiskac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 18:27:01 by bkiskac           #+#    #+#             */
/*   Updated: 2025/01/31 15:35:33 by bkiskac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

static void	events_init(t_fractal *fractal)
{
	mlx_hook(fractal->win, KeyPress, KeyPressMask, handle_key, fractal);
	mlx_hook(fractal->win, ButtonPress, ButtonPressMask, handle_mouse, fractal);
	mlx_hook(fractal->win, DestroyNotify, StructureNotifyMask, handle_close, fractal);
}

static void	data_init(t_fractal *fractal)
{
	fractal->hypotenuse = 4;
	fractal->iterations = 128;
	fractal->shift_real = 0.0;
	fractal->shift_i = 0.0;
	fractal->zoom = 1.0;
}

static void	create_window(t_fractal *fractal)
{
	fractal->win = mlx_new_window(fractal->mlx, WIDTH, HEIGHT, fractal->title);
	if (!fractal->win)
	{
		mlx_destroy_display(fractal->mlx);
		free(fractal->mlx);
		malloc_error();
	}
}

static void	create_image(t_fractal *fractal)
{
	fractal->img = mlx_new_image(fractal->mlx, WIDTH, HEIGHT);
	if (!fractal->img)
	{
		mlx_destroy_window(fractal->mlx, fractal->win);
		mlx_destroy_display(fractal->mlx);
		free(fractal->mlx);
		malloc_error();
	}
	fractal->addr = mlx_get_data_addr(fractal->img, &fractal->img_bpp,
		&fractal->img_line, &fractal->img_endian);
}

void	fractol_init(t_fractal *fractal)
{
	fractal->mlx = mlx_init();
	if (!fractal->mlx)
		malloc_error();
	create_window(fractal);
	create_image(fractal);
	events_init(fractal);
	data_init(fractal);
	fractal->color = WHITE;
}
