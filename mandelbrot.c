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
}			t_data;

int	mandelbrot(double cr, double ci)
{
	double	zr;
	double	zi;
	int		iter;
	double	temp;

	zr = 0.0;
	zi = 0.0;
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

void	draw_mandelbrot(t_data *data)
{
	double	cr;
	double	ci;
	int		iter;
	int		color;

	for (int y = 0; y < HEIGHT; y++)
	{
		for (int x = 0; x < WIDTH; x++)
		{
			cr = (x - WIDTH / 2.0) * 4.0 / WIDTH;
			ci = (y - HEIGHT / 2.0) * 4.0 / HEIGHT;
			iter = mandelbrot(cr, ci);
			color = iter == MAX_ITER ? 0 : (iter * 255 / MAX_ITER) << 16;
			mlx_pixel_put(data->mlx, data->win, x, y, color);
		}
	}
}

int	main(void)
{
	t_data	data;

	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, WIDTH, HEIGHT, "Mandelbrot Set");
	draw_mandelbrot(&data);
	mlx_loop(data.mlx);
	return (0);
}
