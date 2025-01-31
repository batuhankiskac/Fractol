/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiskac <bkiskac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 17:46:51 by bkiskac           #+#    #+#             */
/*   Updated: 2025/01/31 17:49:45 by bkiskac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft/libft.h"
# include "mlx/mlx.h"
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <X11/X.h>
# include <X11/keysym.h>

# define WIDTH 800
# define HEIGHT 800

# define BLACK 0x000000
# define WHITE 0xFFFFFF
# define DEEP_PURPLE 0x4A148C
# define INDIGO 0x3F51B5
# define AZURE 0x007FFF
# define TURQUOISE 0x40E0D0
# define SPRING_GREEN 0x00FF7F
# define CHARTREUSE 0x7FFF00
# define GOLDEN 0xFFD700
# define CORAL 0xFF7F50
# define CRIMSON 0xDC143C
# define VIOLET 0x9400D3
# define AQUA 0x00FFFF
# define ELECTRIC_BLUE 0x7DF9FF
# define HOT_PINK 0xFF69B4
# define NEON_GREEN 0x39FF14

typedef struct s_map
{
	double	unscaled_num;
	double	new_min;
	double	new_max;
	double	old_min;
	double	old_max;
}			t_map;

typedef struct s_fractal
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	char	*title;
	int		img_bpp;
	int		img_line;
	int		img_endian;
	int		iterations;
	int		color;
	double	compl_real;
	double	compl_i;
	double	hypotenuse;
	double	shift_real;
	double	shift_i;
	double	zoom;
	double	julia_real;
	double	julia_i;
}			t_fractal;

t_fractal	square_complex(t_fractal z);
t_fractal	sum_complex(t_fractal z1, t_fractal z2);
void		instruction(void);
void		malloc_error(void);
void		fractol_init(t_fractal *fractal);
void		fractol_render(t_fractal *fractal);
void		zoom_in(t_fractal *fract, double mouse_real, double mouse_i);
void		zoom_out(t_fractal *fract, double mouse_real, double mouse_i);
void		color_shift(t_fractal *fractal);
int			blend_colors(int color1, int color2, double t);
int			handle_close(t_fractal *fractal);
int			handle_key(int keysym, t_fractal *fractal);
int			handle_mouse(int button, int x, int y, t_fractal *fractal);
double		ft_atod(char *s);
double		map(t_map coords);

#endif
