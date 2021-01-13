/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scrolling_area.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstepany <lstepany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 23:32:15 by lstepany          #+#    #+#             */
/*   Updated: 2021/01/12 23:32:55 by lstepany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	scrolling_area(t_data *data)
{
	data->y = 320;
	while (data->y < 550)
	{
		data->x = 50;
		while (data->x < 300)
		{
			data->color = 255;
			data->pixel = data->y * data->line_bytes + data->x * 4;
			data->buffer[data->pixel + 0] = 50;
			data->buffer[data->pixel + 1] = 50;
			data->buffer[data->pixel + 2] = 50;
			data->buffer[data->pixel + 3] = 0;
			data->x++;
		}
		data->y++;
	}
}
