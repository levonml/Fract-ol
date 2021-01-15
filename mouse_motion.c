/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_motion.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstepany <lstepany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 23:31:44 by lstepany          #+#    #+#             */
/*   Updated: 2021/01/12 23:32:55 by lstepany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		mouse_motion(int x, int y, void *param)
{
	t_data	*data;
	float	fx;
	float	fy;

	fx = x;
	fy = y;
	data = (t_data *)param;
	if (ft_strcmp(data->argv, "julia") != 0)
		return (0);
	fx = (fx - WIDTH / 2) / (WIDTH / 2);
	fy = (fy - HEIGHT / 2) / (HEIGHT / 2);
	data->cx = (fx);
	data->cy = (fy);
	choose_fractal(data, data->argv);
	insert_text(data);
	return (0);
}
