#include "mlx.h"
#include <stdio.h>
#include <stdlib.h>
#define ESC_KEY 53

void	draw_rectangle(void *mlx, void *win, int x, int y, int width,
		int height, int color)
{
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			mlx_pixel_put(mlx, win, x + j, y + i, color);
		}
	}
}

void	draw_circle(void *mlx, void *win, int xc, int yc, int radius, int color)
{
	for (int y = -radius; y <= radius; y++)
	{
		for (int x = -radius; x <= radius; x++)
		{
			if (x * x + y * y <= radius * radius)
			{
				mlx_pixel_put(mlx, win, xc + x, yc + y, color);
			}
		}
	}
}

int	handle_keypress(int keycode, void *param)
{
	printf("Key pressed: %d\n", keycode);
	(void)param;
	if (keycode == ESC_KEY)
	{
		// ESCキーが押されたらプログラムを終了する
		exit(0);
	}
	return (0);
}

int	handle_mouse(int button, int x, int y, void *param)
{
	printf("Mouse button %d pressed at (%d, %d)\n", button, x, y);
	(void)param;
	return (0);
}

int	main(void)
{
	void	*mlx;
	void	*win;

	// MiniLibXの初期化
	mlx = mlx_init();
	// ウィンドウの作成
	win = mlx_new_window(mlx, 800, 600, "MiniLibX Window");
	// 矩形の描画
	draw_rectangle(mlx, win, 100, 100, 200, 150, 0x00FF00); // 緑色の矩形を描画
	draw_circle(mlx, win, 400, 300, 100, 0x0000FF);         // 青色の円を描画
	mlx_key_hook(win, handle_keypress, NULL);               // キーボードイベントのハンドラを登録
	mlx_mouse_hook(win, handle_mouse, NULL);                // マウスイベントのハンドラを登録
	// ウィンドウの表示とイベントループの開始
	mlx_loop(mlx);
	return (0);
}
