
#include "fractol.h"

int	main(int argc, char **argv)
{
	t_data	*data;

	if (argc != 2)
	{
		ft_putstr("usage: ./fractol mandelbrot or ./fractol julia\n");
		exit(0);
	}
	if (!(data = (t_data *)malloc(sizeof(t_data))))
		exit(0);
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, 1600, 900, "fractol");
	data->image = mlx_new_image(data->mlx, 1600, 900);
	data->zoom = ZOOM;
	data->x_pos = X_POS;
	data->y_pos = Y_POS;
	data->iter = ITERATION;
	data->argv = argv[1];
	data->buffer = mlx_get_data_addr(data->image, &(data->pixel_bits),\
	&(data->line_bytes), &(data->endian));
	mlx_key_hook(data->win, key_control, data);
	mlx_mouse_hook(data->win, mouse_control, data);
	mlx_loop(data->mlx);
	return (0);
}
