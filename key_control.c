#include "fractol.h"

int	key_control(int key, void *param)
{
	t_data *data;

	data = (t_data *)param;
	if (key == 65307)
		exit(0);
	if (key == 49)
		data->zoom *= ZOOMIN;
	if (key == 50)
		data->zoom /= ZOOMIN;
	if (key == 65363)
		data->x_pos += 500;
	if (key == 65361)
		data->x_pos -= 500;
	if (key == 65362)
		data->y_pos -= 500;
	if (key == 65364)
		data->y_pos += 500;
	if (key == 105)
		data->iter += 20;
	if (key == 111)
		data->iter -= 20;
	choose_fractal(data, data->argv);
	insert_text(data);
	return (0);
}
