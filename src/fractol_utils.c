/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiskac <bkiskac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 18:08:51 by bkiskac           #+#    #+#             */
/*   Updated: 2025/01/25 18:18:49 by bkiskac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	instruction(void)
{
	ft_printf("To move the fractal, use the arrow keys or WASD\n");
	ft_printf("To zoom in and out, use the mouse wheel\n");
	ft_printf("To change the color, use space key\n");
	ft_printf("To change the iterations, use the + and - keys\n");
	ft_printf("To rotate the Julia, use left or right mouse button\n");
	ft_printf("To quit, use the ESC key or simply click X on the window\n");
	ft_printf("Example Julia Sets:\n");
	ft_printf("./fractol julia -0.4 +0.6\n");
	ft_printf("./fractol julia -0.835 -0.2321\n");
}

void	malloc_error(void)
{
	perror("Malloc Error: ");
	exit(EXIT_FAILURE);
}
