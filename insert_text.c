/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_text.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstepany <lstepany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 23:31:19 by lstepany          #+#    #+#             */
/*   Updated: 2021/01/12 23:32:55 by lstepany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	insert_text(t_data *data)
{
	int		i;
	char	*str[6];

	str[0] = "zoom in            ---  scroll up";
	str[1] = "zoom out           ---  scroll down";
	str[2] = "move               ---  arrows";
	str[3] = "iteration +        ---  i";
	str[4] = "iteration -        ---  o";
	str[5] = "color change       ---  1";
	data->x = 50;
	data->y = 50;
	i = 0;
	while (i < 6)
	{
		mlx_string_put(data->mlx, data->win, data->x,\
		data->y, 0xffffff, str[i]);
		i++;
		data->y += 15;
	}
}
