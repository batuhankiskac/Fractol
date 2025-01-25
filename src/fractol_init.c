/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiskac <bkiskac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 18:27:01 by bkiskac           #+#    #+#             */
/*   Updated: 2025/01/25 18:33:14 by bkiskac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

static void	events_init(t_fractol *fractol)
{
	mlx_hook(fractol->win, KeyPress, KeyPressMask, handle_key, fractol);
	mlx_hook(fractol->win, ButtonPress, ButtonPressMask, handle_mouse, fractol);
	mlx_hook(fractol->win, DestroyNotify, StructureNotifyMask, clean_exit, fractol);
}
