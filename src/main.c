/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: YourName <your.email@example.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 01:08:23 by YourName          #+#    #+#             */
/*   Updated: 2025/03/30 07:42:16 by YourName         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

int	main(int argc, char **argv)
{
	t_fractol	fractol;

	if ((argc == 2 && !ft_strncmp(argv[1], "mandelbrot", 10)) || (argc == 4
			&& !ft_strncmp(argv[1], "julia", 5)))
	{
		fractol.name = argv[1];
		fractol.julia_x = atodbl(argv[2]);
		fractol.julia_y = atodbl(argv[3]);
		fractol_init(&fractol);
		fractol_render(&fractol);
		mlx_loop(fractol.mlx_connection);
	}
	else
	{
		ft_putstr_fd(ERROR_MESSAGE, STDERR_FILENO);
		exit(1);
	}
	return (0);
}

// #include "mlx/mlx.h"

// int	main(void)
// {
// 	void	*mlx;
// 	void	*win;

// 	mlx = mlx_init();                                 // MiniLibX の初期化,接続
// 	win = mlx_new_window(mlx, 800, 600, "My Window"); // 800x600 のウィンドウを作成
// 	mlx_loop(mlx); // イベントループ
// 	return (0);
// }
