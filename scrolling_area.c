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
			data->color = 50;
			data->pixel = data->y * data->line_bytes + data->x * 4;
			drow_fractal(data);
			data->x++;
		}
		data->y++;
	}
}
