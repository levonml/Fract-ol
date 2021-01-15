/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstepany <lstepany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 23:31:27 by lstepany          #+#    #+#             */
/*   Updated: 2021/01/12 23:32:47 by lstepany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	argc_check(int argc)
{
	if (argc != 2)
	{
		ft_putstr("wrong number of argument\nusage: ./fractol mandelbrot or ");
		ft_putstr("./fractol julia or ./fractol burning_ship\n");
		exit(0);
	}
}

int		main(int argc, char **argv)
{
	t_data	*data;

	argc_check(argc);
	if (!(data = (t_data *)malloc(sizeof(t_data))))
		return (0);
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "fractol");
	data->image = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	data->zoom = ZOOM;
	data->x_pos = X_POS;
	data->y_pos = Y_POS;
	data->iter = ITERATION;
	data->argv = argv[1];
	data->color_change = 5;
	data->buffer = mlx_get_data_addr(data->image, &(data->pixel_bits),\
	&(data->line_bytes), &(data->endian));
	mlx_key_hook(data->win, key_control, data);
	mlx_mouse_hook(data->win, mouse_control, data);
	mlx_hook(data->win, 06, 1L << 6, mouse_motion, data);
	mlx_loop(data->mlx);
	return (0);
}
