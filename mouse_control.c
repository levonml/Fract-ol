#include "fractol.h"

void	change_julia_type(t_data *data, int key)
{
	static	int	i = 0;
	static int	j = 1;
	float		arr[] = {-0.7269, 0.188, -0.835, -0.2321, -0.70176,\
	-0.3842, 0.45, 0.1428, 0.285, 0.01, -0.8, 0.156, 0.285, 0};

	if (key == 5)
	{
		data->cx = arr[i];
		data->cy = arr[j];
		i += 2;
		j += 2;
	}
	if (j > 13)
	{
		i = 0;
		j = 1;
	}
}

int		mouse_control(int key, int x, int y, void *param)
{
	t_data		*data;

	data = (t_data *)param;
	if (x >= 50 && x <= 300 && y >= 320 && y <= 550 &&\
		ft_strcmp(data->argv, "julia") == 0)
		change_julia_type(data, key);
	if (key == 4 && (!(x > 50 && x < 300 && y > 320 && y < 550)))
		data->zoom *= ZOOMIN;
	if (key == 5 && (!(x > 50 && x < 300 && y > 320 && y < 550)))
	{
		data->x_pos -= (x - WIDTH / 2);
		data->y_pos -= (y - HEIGHT / 2);
		data->zoom /= ZOOMIN;
	}
	choose_fractal(data, data->argv);
	insert_text(data);
	return (0);
}
