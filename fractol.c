#include "fractol.h"
#include <stdio.h>
#include <stdlib.h>

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
void create_mandelbrot(t_data *data)
{
	printf("mandel_zoom = %f\n", data->zoom);
	data->y = 0; 
	while(data->y < 890)
	{
		data->x = 0;
		while(data->x < 1590)
		{
			data->count = 0;
			data->cx = (data->x - 1000) * data->zoom ;
			data->cy = (data->y - 400)* data->zoom;
			data->zx = 0;
			data->zy = 0;
			data->color = 0;
			while (data->count < data->iter)
	  		{
	    		data->zr = data->zx*data->zx - data->zy*data->zy  + data->cx;
	    		data->zi = 2*data->zx*data->zy + data->cy;
	    		data->zx = data->zr;
	    		data->zy = data->zi;
	    		data->count++;
	    		data->color = data->color + 250;
	    		if (data->zr*data->zr + data->zi*data->zi > 4)
	      			break;
	  		}
			data->pixel = data->y * data->line_bytes + data->x * 4;	
			drow_fractal(data);
			data->x++;
      }
	  data->y++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->image, 0, 0);
}
void create_julia(t_data *data)
{
  //	printf("zoom_julia = %f\n", (data->zoom));
	data->y = 0; 
	while(data->y < 890)
	{
		data->x = 0;
		while(data->x < 1590)
		{
			data->count = 0;
			data->cx = /*-0.8;/*/-0.7269;
			data->cy = /*0.156;/*/0.188;
			data->zx = data->zoom*(data->x - data->x_pos);//0;
			data->zy = data->zoom*(data->y - data->y_pos);//0;
			data->color = 0;
			while (data->count < data->iter)
	  		{
	    		data->zr = data->zx*data->zx - data->zy*data->zy /*- 0->70176 - 1000;//*/ + data->cx;
	    		data->zi = 2*data->zx*data->zy /*-0->3842 - 400;//*/+ data->cy;
	    		data->zx = data->zr;
	    		data->zy = data->zi;
	    		data->count++;
	    		data->color = data->color + 250;
	    		if (data->zr*data->zr + data->zi*data->zi > 4)
	      			break;
	  		}
			data->pixel = data->y * data->line_bytes + data->x * 4;	
			drow_fractal(data);
			data->x++;
      }
	  data->y++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->image, 0, 0);
}
void choose_fractal(t_data *data, char *fr_type)
{
	char *mandelbrot = "mandelbrot";
	char *julia = "julia";

	if (ft_strcmp(fr_type, mandelbrot) == 0)
		create_mandelbrot(data);
	else if (ft_strcmp(fr_type, julia) == 0)
		create_julia(data);
	else
	{
		printf("wrong argument\n usage: ./a.out mandelbrot or ./a.out julia\n");
		exit(0);
	}
}
int	key_control(int key,  void *param)
{
t_data *data;
data = (t_data *)param;
if(key == 65307)
	exit(0);
	//data->zoom = 0.003;
if (key == 49)
	data->zoom *= 2;
if (key == 50)
	data->zoom /= 2;
if (key == 65363)
	data->x_pos++;
if (key == 65361)
	data->x_pos -= 100;
 if (key == 105)
   data->iter += 10;
 if (key == 111)
   data->iter -= 10;
//printf("key == %d\n", key);
choose_fractal(data, data->argv);
//printf("argv = %s\n", data->argv);
	
	return(0);
}
int mouse_control(int key, int x, int y, void *param)
{
	t_data *data;
	data = (t_data *)param;
//	printf("key = %d\n", key);
	if (key == 4)
		data->zoom *= 2;
	if (key == 5)
		data->zoom /= 2;
	choose_fractal(data, data->argv);
		//printf("zoom = %f\n", (data->zoom));
	return(0);
}
int main(int argc, char **argv)
{
	t_data	*data;

	if(argc != 2)
	  {
	    ft_putstr("usage: ./a.out mandelbrot or ./a.out julia\n");
	    exit(0);
	  }
       	data = (t_data *)malloc(sizeof(t_data));	
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, 1600, 900, "Amazing Mandelbrot and friends->->->");
	data->image = mlx_new_image(data->mlx, 1600, 900);
	data->zoom = 0.003;
	data->x_pos = 800;
	data->y_pos = 400;
	data->iter = 150;
	data->argv = argv[1];
	data->buffer = mlx_get_data_addr(data->image, &(data->pixel_bits), &(data->line_bytes), &(data->endian));
	mlx_key_hook(data->win, key_control, data);
	mlx_mouse_hook(data->win, mouse_control, data);
	mlx_loop(data->mlx);
}
