/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: YourName <your.email@example.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 20:30:48 by YourName          #+#    #+#             */
/*   Updated: 2025/03/30 02:17:58 by YourName         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../libft/includes/libft.h"
# include "../mlx/mlx.h"
# include "../mlx/mlx_int.h"
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define ERROR_MESSAGE "plese enter \n\t\"./fractol mandelbrot\" or \n\t\"./fractol julia <value1> <value2>\" "

# define WIDTH 800
# define HEIGHT 800

# define BLACK 0x000000
# define WHITE 0xFFFFFF
# define RED 0xFF0000
# define GREEN 0x00FF00
# define BLUE 0x0000FF
# define PSYCEDELIC_PURPLE 0xDF00FF

typedef struct s_complex
{
	double	x;
	double	y;
}			t_complex;

typedef struct s_img
{
	void	*img_ptr;
	char	*pixels_ptr;
	int		bpp;
	int		endian;
	int		line_len;
}			t_img;

typedef struct s_fractol
{
	char	*name;
	void *mlx_connection; // mlx_init()
	void *mlx_window;     // mlx_new_window()
	t_img	img;
	double	escape_value;
	int		iterations_definition;
}			t_fractol;

void		fractol_init(t_fractol *fractol);
void		malloc_error(void);

double		map(double unscaled_num, double new_min, double new_max,
				double old_min, double old_max);
t_complex	sum_complex(t_complex z1, t_complex z2);
t_complex	square_complex(t_complex z);

#endif
