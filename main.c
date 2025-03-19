#include "mlx/mlx.h"

int	main(void)
{
	void	*mlx;
	void	*win;

	mlx = mlx_init();                                 // MiniLibX の初期化,接続
	win = mlx_new_window(mlx, 800, 600, "My Window"); // 800x600 のウィンドウを作成
	mlx_loop(mlx); // イベントループ
	return (0);
}
