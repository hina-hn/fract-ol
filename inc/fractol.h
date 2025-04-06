/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: YourName <your.email@example.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 20:30:48 by YourName          #+#    #+#             */
/*   Updated: 2025/04/06 13:39:27 by YourName         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../libft/includes/libft.h"
# include "../mlx/mlx.h"
# include "../mlx/mlx_int.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define ERROR_MESSAGE "Usage: ./fractol mandelbrot | julia <val1> <val2>\n"

# define WIDTH 800
# define HEIGHT 800

# define BLACK 0x000000
# define WHITE 0xFFFFFF
# define RED 0xFF0000
# define GREEN 0x00FF00
# define BLUE 0x0000FF
# define PSYCEDELIC_PURPLE 0xDF00FF

typedef struct s_range
{
	double		old_min;
	double		old_max;
}				t_range;

typedef struct s_complex
{
	double		x;
	double		y;
}				t_complex;

typedef struct s_my_img
{
	void		*img_ptr;
	char		*pixels_ptr;
	int			bpp;
	int			endian;
	int			line_len;
}				t_my_img;

typedef struct s_fractol
{
	char		*name;
	void		*mlx_connection;
	void		*mlx_window;
	t_my_img	img;
	double		escape_value;
	int			iterations_definition;
	double		shift_x;
	double		shift_y;
	double		zoom;
	double		julia_x;
	double		julia_y;
}				t_fractol;

void			fractol_init(t_fractol *fractol);
void			malloc_error(void);

double			map(double unscaled_num, double new_min, double new_max,
					t_range old);
t_complex		sum_complex(t_complex z1, t_complex z2);
t_complex		square_complex(t_complex z);

void			fractol_render(t_fractol *fractol);
void			data_init(t_fractol *fractol);
void			events_init(t_fractol *fractol);

int				close_handler(t_fractol *fractol);
int				key_handler(int keysym, t_fractol *fractol);
int				mouse_handler(int button, int x, int y, t_fractol *fractol);
int				julia_track(int x, int y, t_fractol *fractol);

double			atodbl(char *s);

#endif
