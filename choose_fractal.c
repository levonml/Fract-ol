/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_fractal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstepany <lstepany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 23:30:41 by lstepany          #+#    #+#             */
/*   Updated: 2021/01/12 23:30:48 by lstepany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	choose_fractal(t_data *data, char *fr_type)
{
	if (ft_strcmp(fr_type, "mandelbrot") == 0)
		create_mandelbrot(data);
	else if (ft_strcmp(fr_type, "julia") == 0)
		create_julia(data);
	else if (ft_strcmp(fr_type, "burning_ship") == 0)
		create_burning_ship(data);
	else
	{
		ft_putstr("wrong arguments\nusage: ./fractol mandelbrot or ");
		ft_putstr("./fractol julia or ./fractol burning_ship\n");
		exit(0);
	}
}
