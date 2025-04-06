/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: YourName <your.email@example.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 06:01:44 by YourName          #+#    #+#             */
/*   Updated: 2025/04/06 14:28:41 by YourName         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	close_handler(t_fractol *fractol)
{
	mlx_destroy_image(fractol->mlx_connection, fractol->img.img_ptr);
	mlx_destroy_window(fractol->mlx_connection, fractol->mlx_window);
	mlx_destroy_display(fractol->mlx_connection);
	free(fractol->mlx_connection);
	exit(0);
}

int	key_handler(int keysym, t_fractol *fractol)
{
	if (keysym == XK_Escape)
		close_handler(fractol);
	if (keysym == XK_Left)
		fractol->shift_x -= (0.5 * fractol->zoom);
	else if (keysym == XK_Right)
		fractol->shift_x += (0.5 * fractol->zoom);
	else if (keysym == XK_Up)
		fractol->shift_y += (0.5 * fractol->zoom);
	else if (keysym == XK_Down)
		fractol->shift_y -= (0.5 * fractol->zoom);
	else if (keysym == XK_period)
		fractol->iterations_definition += 10;
	else if (keysym == XK_comma)
		fractol->iterations_definition -= 10;
	fractol_render(fractol);
	return (0);
}

int	mouse_handler(int button, int x, int y, t_fractol *fractol)
{
	(void)x;
	(void)y;
	if (button == Button5)
	{
		fractol->zoom *= 0.95;
	}
	else if (button == Button4)
	{
		fractol->zoom *= 1.05;
	}
	fractol_render(fractol);
	return (0);
}

int	julia_track(int x, int y, t_fractol *fractol)
{
	t_range	x_range;
	t_range	y_range;

	x_range.old_min = 0;
	x_range.old_max = WIDTH;
	y_range.old_min = 0;
	y_range.old_max = HEIGHT;
	if (!ft_strncmp(fractol->name, "julia", 5))
	{
		fractol->julia_x = (map(x, -2, +2, x_range) * fractol->zoom)
			+ fractol->shift_x;
		fractol->julia_y = (map(y, +2, -2, y_range) * fractol->zoom)
			+ fractol->shift_y;
		fractol_render(fractol);
	}
	return (0);
}
