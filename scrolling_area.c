#include "fractol.h"

void	scrolling_area(t_data *data)
{
	data->y = 320;
	while (data->y < 550)
	{
		data->x = 50;
		while (data->x < 300)
		{
			data->color = 50;
			data->pixel = data->y * data->line_bytes + data->x * 4;
			drow_fractal(data);
			data->x++;
		}
		data->y++;
	}
}
