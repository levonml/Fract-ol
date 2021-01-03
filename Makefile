fractol:
	make -C libft
	clang  -g fractol.c  -L libft -lft -I /usr/local/include -L /usr/local/lib/ -lmlx -I /usr/include/X11 -L /usr/lib/x86_64-linux-gnu -lXext -lX11 
clean:
	make clean -C libft
	rm -rf *~ *.o