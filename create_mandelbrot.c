/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_mandelbrot.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstepany <lstepany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 23:31:03 by lstepany          #+#    #+#             */
/*   Updated: 2021/01/12 23:32:55 by lstepany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	iterate(t_data *data)
{
	while (data->count < data->iter)
	{
		data->zr = data->zx * data->zx - data->zy * data->zy + data->cx;
		data->zi = 2 * data->zx * data->zy + data->cy;
		data->zx = data->zr;
		data->zy = data->zi;
		data->count++;
		data->color += data->color_change;
		if (data->zr * data->zr + data->zi * data->zi > 4)
			break ;
	}
}

void		create_mandelbrot(t_data *data)
{
	data->y = 0;
	while (data->y < 890)
	{
		data->x = 0;
		while (data->x < 1590)
		{
			data->count = 0;
			data->cx = (data->x - data->x_pos) * data->zoom;
			data->cy = (data->y - data->y_pos) * data->zoom;
			data->zx = 0;
			data->zy = 0;
			data->color = 0;
			iterate(data);
			data->pixel = data->y * data->line_bytes + data->x * 4;
			drow_fractal(data);
			data->x++;
		}
		data->y++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->image, 0, 0);
}
