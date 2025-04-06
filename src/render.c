/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: YourName <your.email@example.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 01:07:55 by YourName          #+#    #+#             */
/*   Updated: 2025/04/06 13:20:50 by YourName         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	my_pixel_put(int x, int y, t_my_img *img, int color)
{
	int	offset;

	offset = (y * img->line_len) + (x * (img->bpp / 8));
	*(unsigned int *)(img->pixels_ptr + offset) = color;
}

static void	mandel_vs_julia(t_complex *z, t_complex *c, t_fractol *fractol)
{
	if (!ft_strncmp(fractol->name, "julia", 5))
	{
		c->x = fractol->julia_x;
		c->y = fractol->julia_y;
	}
	else
	{
		c->x = z->x;
		c->y = z->y;
	}
}

int	compute_color(t_complex z, t_complex c, t_fractol *fractol)
{
	int		i;
	t_range	iter_range;

	iter_range = (t_range){0, fractol->iterations_definition};
	i = 0;
	while (i < fractol->iterations_definition)
	{
		z = sum_complex(square_complex(z), c);
		if ((z.x * z.x) + (z.y * z.y) > fractol->escape_value)
			return (map(i, BLACK, WHITE, iter_range));
		++i;
	}
	return (PSYCEDELIC_PURPLE);
}

void	handle_pixel(int x, int y, t_fractol *fractol)
{
	t_complex	z;
	t_complex	c;
	t_range		x_range;
	t_range		y_range;
	int			color;

	x_range = (t_range){0, WIDTH};
	y_range = (t_range){0, HEIGHT};
	z.x = (map(x, -2, +2, x_range) * fractol->zoom) + fractol->shift_x;
	z.y = (map(y, +2, -2, y_range) * fractol->zoom) + fractol->shift_y;
	mandel_vs_julia(&z, &c, fractol);
	color = compute_color(z, c, fractol);
	my_pixel_put(x, y, &fractol->img, color);
}

void	fractol_render(t_fractol *fractol)
{
	int	x;
	int	y;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			handle_pixel(x, y, fractol);
		}
	}
	mlx_put_image_to_window(fractol->mlx_connection, fractol->mlx_window,
		fractol->img.img_ptr, 0, 0);
}
