#include "mlx.h"
#include <math.h>
#include <stdlib.h>

#define WIDTH 800
#define HEIGHT 600
#define MAX_ITER 100

typedef struct
{
	void	*mlx;
	void	*win;
	double	cr;
	double	ci;
}			t_data;

int	julia(double zr, double zi, double cr, double ci)
{
	int		iter;
	double	temp;

	iter = 0;
	while (zr * zr + zi * zi <= 4.0 && iter < MAX_ITER)
	{
		temp = zr * zr - zi * zi + cr;
		zi = 2.0 * zr * zi + ci;
		zr = temp;
		iter++;
	}
	return (iter);
}

void	draw_julia(t_data *data)
{
	double	zr;
	double	zi;
	int		iter;
	int		color;

	for (int y = 0; y < HEIGHT; y++)
	{
		for (int x = 0; x < WIDTH; x++)
		{
			zr = (x - WIDTH / 2.0) * 4.0 / WIDTH;
			zi = (y - HEIGHT / 2.0) * 4.0 / HEIGHT;
			iter = julia(zr, zi, data->cr, data->ci);
			color = iter == MAX_ITER ? 0 : (iter * 255 / MAX_ITER) << 16;
			mlx_pixel_put(data->mlx, data->win, x, y, color);
		}
	}
}

int	main(void)
{
	t_data	data;

	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, WIDTH, HEIGHT, "Julia Set");
	data.cr = -0.7;    // 固定された複素数の実数部分
	data.ci = 0.27015; // 固定された複素数の虚数部分
	draw_julia(&data);
	mlx_loop(data.mlx);
	return (0);
}
