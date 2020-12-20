#include "mlx.h"
#include <stdio.h>

int main()
{
    void *mlx = mlx_init();
    void *win = mlx_new_window(mlx, 640, 360, "Tutorial Window - Create Image");

    void *image = mlx_new_image(mlx, 400, 300);
    
    // The following code goes here.
    int a;
    int b;
    int count;
    int pixel_bits;
    int line_bytes;
    int endian;
    char *buffer = mlx_get_data_addr(image, &pixel_bits, &line_bytes, &endian);

    int color = 0xABCDEF;

    if (pixel_bits != 32)
      color = mlx_get_color_value(mlx, color);
    //    printf("endian = %d\n", endian);
    //    printf("line_bites = %d\n", line_bytes);
    for(int y = 40; y < 300; ++y)
    for(int x = 40; x < 300; x = x + 4)
      {
	int pixel = (y  * line_bytes) + (x * 4);
	count = 0;
	/*while (count < 10 || y < 250)
	  {
	    //y = y + 4;
	    count++;
	    }*/
      	if (endian == 1)        // Most significant (Alpha) byte first
	  {
	    buffer[pixel + 0] = (color >> 24);
	    buffer[pixel + 1] = (color >> 16) & 0xFF;
	    buffer[pixel + 2] = (color >> 8) & 0xFF;
	    buffer[pixel + 3] = (color) & 0xFF;
	  }
	else if (endian == 0)   // Least significant (Blue) byte first
	  {
	      buffer[pixel + 0] = (color) & 0xFF;
	      buffer[pixel + 1] = (color >> 8) & 0xFF;
	      buffer[pixel + 2] = (color >> 16) & 0xFF;
	      buffer[pixel + 3] = (color >> 24);
	    //buffer[pixel] = 12345;
	  }
      }
    mlx_put_image_to_window(mlx, win, image, 0, 0);
    mlx_loop(mlx);
}
