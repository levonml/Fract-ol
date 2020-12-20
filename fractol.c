#include "fractol.h"
#include <stdio.h>

int main(void)
{
  t_data	data;
  data.mlx = mlx_init();
  data.win = mlx_new_window(data.mlx, 1600, 900, "Amazing Mandelbrot and friends...");
  data.image = mlx_new_image(data.mlx, 1600, 900);
  data.buffer = mlx_get_data_addr(data.image, &(data.pixel_bits), &(data.line_bytes), &(data.endian));
  for(data.y = 0; data.y < 890; ++data.y)
    for(data.x = 0; data.x < 1590; ++data.x)
      {
	data.count = 0;
	data.cx = (data.x - 1000) * 0.003 ;
	data.cy = (data.y - 400) * 0.003;
	data.zx = 0;
	data.zy = 0;
	data.color = 0;
	while (data.count < 150)
	  {
	    data.zr = data.zx*data.zx - data.zy*data.zy + data.cx;
	    data.zi = 2*data.zx*data.zy + data.cy;
	    data.zx = data.zr;
	    data.zy = data.zi;
	    data.count++;
	    data.color = data.color + 250;
	    if (data.zr*data.zr + data.zi*data.zi > 4)
	      break;
	  }
	data.pixel = data.y * data.line_bytes + data.x * 4;	
	if (data.endian == 1)        // Most significant (Alpha) byte first
	  {
	    data.buffer[data.pixel + 0] = 0x90;//(data.color >> 24);
	    data.buffer[data.pixel + 1] = 0x90; //(data.color >> 16) & 0xFF;
	    data.buffer[data.pixel + 2] = 0x90; //(data.color >> 8) & 0xFF;
	    data.buffer[data.pixel + 3] = (data.color) & 0xFF;
	  }
	else if (data.endian == 0)   // Least significant (Blue) byte first
	  {
	    if((data.zr*data.zr + data.zi*data.zi) < 4 )
	      {
		data.buffer[data.pixel + 0] = 30;//color;//37;// + color;//(color) & 0xFF;
		data.buffer[data.pixel + 1] = 40;//color;//82; //+ color; //(color >> 19) & 0xFF;
		data.buffer[data.pixel + 2] = 30;//color;//0xa2; //+ color; //(color >> 16) & 0xFF;
		data.buffer[data.pixel + 3] = (data.color >> 24);
	      }
	    else
	      {
		data.buffer[data.pixel + 0] = data.color + 35;// 0x50;//(color) & 0xFF;
		data.buffer[data.pixel + 1] = data.color + 72;//0x50; //(color >> 8) & 0xFF;
		data.buffer[data.pixel + 2] = data.color + 0xb8;//0x50; //(color >> 16) & 0xFF;
		data.buffer[data.pixel + 3] = (data.color >> 24);
		//color++;
	      }
	  }
      }
  mlx_put_image_to_window(data.mlx, data.win, data.image, 0, 0);
  mlx_loop(data.mlx);
}
