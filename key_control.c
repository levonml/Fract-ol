/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_control.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstepany <lstepany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 23:31:23 by lstepany          #+#    #+#             */
/*   Updated: 2021/01/12 23:32:55 by lstepany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	key_control(int key, void *param)
{
	t_data *data;

	data = (t_data *)param;
	if (key == 65307)
		exit(0);
	if (key == 49)
		data->color_change += 10;
	if (key == 50)
		data->color_change -= 5;
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
