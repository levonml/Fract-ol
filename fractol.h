/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstepany <lstepany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 23:31:12 by lstepany          #+#    #+#             */
/*   Updated: 2021/01/12 23:32:55 by lstepany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "libft/libft.h"
# include "mlx.h"
# include <stdlib.h>
# define WIDTH 1600
# define HEIGHT 900
# define ZOOM 0.003
# define ZOOMIN 1.2
# define X_POS 1000
# define Y_POS 400
# define ITERATION 100

typedef struct	s_data
{
	int		x;
	int		y;
	int		random;
	int		x_pos;
	int		y_pos;
	int		color;
	int		color_change;
	int		count;
	int		pixel;
	int		pixel_bits;
	int		line_bytes;
	int		endian;
	int		iter;
	float	zoom;
	float	zr;
	float	zi;
	float	cx;
	float	cy;
	float	zx;
	float	zy;
	void	*mlx;
	void	*win;
	void	*image;
	char	*buffer;
	char	*argv;
}				t_data;
int				key_control(int key, void *param);
int				mouse_control(int key, int x, int y, void *param);
void			choose_fractal(t_data *data, char *fr_type);
void			create_julia(t_data *data);
void			create_mandelbrot(t_data *data);
void			create_burning_ship(t_data *data);
void			drow_fractal(t_data *data);
void			insert_text(t_data *data);
void			scrolling_area(t_data *data);
#endif
