
#ifndef FRACTOL_H
# define FRACTOL_H
# define COLOR 0xff0000
# define Z 1
# define ZOOM 15
//# include "libft/libft.h"
# include "mlx.h"

typedef struct		s_data
{
	int			x;
	int			y;
	int			color;
	int			count;
	int			pixel;
	int			pixel_bits;
	int			line_bytes;
	int			endian;
  //}					t_ints;
//typedef	struct		s_floats
//{
	float			zr;
	float			zi;
  	float			cx;
  	float			cy;
	float			zx;
	float			zy;
	void			*mlx;
	void			*win;
	void			*image;
	char			*buffer;
}					t_data;
#endif
