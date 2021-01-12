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

void drow_fractal(t_data *data)
{
	if(data->endian == 1)        // Most significant (Alpha) byte first
	  	{
	    	data->buffer[data->pixel + 0] = 0x90;//(data->color >> 24);
	    	data->buffer[data->pixel + 1] = 0x90; //(data->color >> 16) & 0xFF;
	    	data->buffer[data->pixel + 2] = 0x90; //(data->color >> 8) & 0xFF;
	    	//data->buffer[data->pixel + 3] = (data->color) & 0xFF;
	  	}
		else if (data->endian == 0)   // Least significant (Blue) byte first
	  	{
			if((data->zr*data->zr + data->zi*data->zi) < 4 )
	    	{
				data->buffer[data->pixel + 0] = 30;//color;//37;// + color;//(color) & 0xFF;
				data->buffer[data->pixel + 1] = 40;//color;//82; //+ color; //(color >> 19) & 0xFF;
				data->buffer[data->pixel + 2] = 30;//color;//0xa2; //+ color; //(color >> 16) & 0xFF;
				//data->buffer[data->pixel + 3] = (data->color >> 24);
	    	}
			else
	    	{
				data->buffer[data->pixel + 0] = data->color + 35;// 0x50;//(color) & 0xFF;
				data->buffer[data->pixel + 1] = data->color + 72;//0x50; //(color >> 8) & 0xFF;
				data->buffer[data->pixel + 2] = data->color + 0xb8;//0x50; //(color >> 16) & 0xFF;
				//data->buffer[data->pixel + 3] = (data->color >> 24);
	 		}
	  	}
}
