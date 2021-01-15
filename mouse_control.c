/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_control.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstepany <lstepany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 23:31:44 by lstepany          #+#    #+#             */
/*   Updated: 2021/01/12 23:32:55 by lstepany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		mouse_control(int key, int x, int y, void *param)
{
	t_data		*data;

	data = (t_data *)param;
	if (key == 4)
		data->zoom *= ZOOMIN;
	if (key == 5)
	{
		data->x_pos -= (x - WIDTH / 2);
		data->y_pos -= (y - HEIGHT / 2);
		data->zoom /= ZOOMIN;
	}
	choose_fractal(data, data->argv);
	insert_text(data);
	return (0);
}
