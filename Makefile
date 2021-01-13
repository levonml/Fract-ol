# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lstepany <lstepany@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/10 12:34:01 by lstepany          #+#    #+#              #
#    Updated: 2021/01/12 23:32:55 by lstepany         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
SRC = main.c key_control.c mouse_control.c void create_burning_ship.c\
	  choose_fractal.c create_julia.c scrolling_area.c\
	  create_mandelbrot.c drow_fractal.c insert_text.c
OBJ = main.o key_control.o mouse_control.o create_burning_ship.o\
	  choose_fractal.o create_julia.o scrolling_area.o\
	   create_mandelbrot.o drow_fractal.o insert_text.o
FLAGS = -Wall -Wextra -Werror
all: $(NAME)
fractol: $(OBJ)
	make -C libft
	clang  $(FLAGS) -g -o fractol $(OBJ) -L libft/ -lft -I /usr/local/include -L /usr/local/lib/ -lmlx -I /usr/include/X11 -L /usr/lib/x86_64-linux-gnu -lXext -lX11 
$(OBJ): %.o: %.c fractol.h
	clang $(FLAGS) -c $<

libft:
	make -C libft
clean:
	make clean -C libft
	rm -rf *~ *.o
fclean: clean
	make clean -C libft	
	rm -f fractol
re:fclean all
