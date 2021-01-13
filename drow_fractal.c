/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drow_fractal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstepany <lstepany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 23:31:08 by lstepany          #+#    #+#             */
/*   Updated: 2021/01/12 23:32:55 by lstepany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	endian_is_one(t_data *data)
{
	if ((data->zr * data->zr + data->zi * data->zi) < 4)
	{
		data->buffer[data->pixel + 0] = 0;
		data->buffer[data->pixel + 1] = 30;
		data->buffer[data->pixel + 2] = 40;
		data->buffer[data->pixel + 3] = 30;
	}
	else
	{
		data->buffer[data->pixel + 0] = 0;
		data->buffer[data->pixel + 1] = data->color + 0xb8;
		data->buffer[data->pixel + 2] = data->color + 72;
		data->buffer[data->pixel + 3] = data->color + 35;
	}
}

void	endian_is_zero(t_data *data)
{
	if ((data->zr * data->zr + data->zi * data->zi) < 4)
	{
		data->buffer[data->pixel + 0] = 50;
		data->buffer[data->pixel + 1] = 50;
		data->buffer[data->pixel + 2] = 50;
		data->buffer[data->pixel + 3] = 0;
	}
	else
	{
		data->buffer[data->pixel + 0] = data->color + 35;
		data->buffer[data->pixel + 1] = data->color + 72;
		data->buffer[data->pixel + 2] = data->color + 0xb8;
		data->buffer[data->pixel + 3] = data->color + 50;
	}
}

void	drow_fractal(t_data *data)
{
	if (data->endian == 1)
		endian_is_one(data);
	else if (data->endian == 0)
		endian_is_zero(data);
}
