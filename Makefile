# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: erahimi <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/08 11:38:24 by erahimi           #+#    #+#              #
#    Updated: 2019/12/20 20:54:57 by erahimi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = rtv1

SRCS =  main.c\
		init.c\
		vector.c\
		draw_calcul.c\
		plane.c\
		cylinder.c\
		cone.c\
		sphere.c\
		parser.c\
		init_parser.c\
		add_objects.c\
		color.c\
		tools.c\
		light_checker.c\
		parse_tools.c\
		closer.c\
		loadTexture.c\
		texture.c

OBJ = main.o\
	  init.o\
	  vector.o\
	  draw_calcul.o\
	  plane.o\
	  cylinder.o\
	  cone.o\
	  sphere.o\
	  parser.o\
	  init_parser.o\
		add_objects.o\
		color.o\
		tools.o\
		light_checker.o\
		parse_tools.o\
		closer.o\
		loadTexture.o\
		texture.o

LIBFT = -L libft -lft

CFLAGS = -Wall -Wextra -Werror

CC = gcc $(CFLAGS)

MLX = -L minilibx -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft libft.a
	@$(CC) -o $@ $(OBJ) $(LIBFT) $(MLX)

%.o: %.c
	$(CC) -c $< -o $@ 

clean:
	@make clean -C libft/
	@rm -f $(OBJ)

fclean: clean
	@make fclean -C libft/
	@rm -f $(NAME)

re: fclean all
