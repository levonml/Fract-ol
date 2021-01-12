#include "fractol.h"

void	choose_fractal(t_data *data, char *fr_type)
{
	if (ft_strcmp(fr_type, "mandelbrot") == 0)
		create_mandelbrot(data);
	else if (ft_strcmp(fr_type, "julia") == 0)
		create_julia(data);
	else
	{
		ft_putstr("wrong argument\n usage: \
		./fractol mandelbrot or ./fractol julia\n");
		exit(0);
	}
}
