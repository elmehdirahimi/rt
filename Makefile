# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: slaanani <slaanani@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/30 23:51:03 by mderri            #+#    #+#              #
#    Updated: 2019/10/10 13:36:05 by slaanani         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS1 = -Wextra -Wall -Werror -I /usr/local/include -I ./includes
CFLAGS2 = -L srcs/libft -lft -I ./includes -I /usr/local/include -L /usr/local/lib -lmlx -framework OpenGL -framework AppKit
NAME = rtv1

SRC =	parsing.c\
		tools.c\
		tools2.c\
		tools3.c\
		tools4.c\
		sphere.c\
		keyhandle.c\
		vecteur_operations.c\
		cone.c\
		plan.c\
		cylinder.c\
		add_obj.c\
		raytracer.c\
		lighting.c\
		shadow.c\
		get_normals.c\
		transformations.c\
		check_config_file.c\
		check_objects.c\
		parse_objects.c\
		free_all.c\
		tools5.c\
		tools6.c\
		tools7.c\
		rtv1.c

SRCS = $(addprefix srcs/, $(SRC))
OBJ = $(SRC:%.c=objs/%.o)
DIRECTORY = objs

all: $(NAME)

$(NAME): $(DIRECTORY) $(OBJ)
	@make -C srcs/libft
	@$(CC) -o $(NAME) $(OBJ) $(CFLAGS1) $(CFLAGS2)
	@echo "\033[0;31m ================================================================================"
	@echo "\033[0;31m|>>>>>>>>>>>>>>>>>>>>\033[0;35m{YOUR RTV1 HAS BEEN COMPILED SUCCESSFULLY}\033[0;31m<<<<<<<<<<<<<<<<<<|"
	@echo "\033[0;31m ================================================================================"

$(DIRECTORY):
	@mkdir -p objs

objs/%.o: srcs/%.c
	@gcc $(CFLAGS1) -c $< -o $@

clean:
	@rm -rf objs
	@rm -f $(OBJ)
	@make clean -C srcs/libft
	@echo "\033[0;31m ================================================================================"
	@echo "\033[0;31m|>>>>>>>>>>>>>>>>>>>>>\033[0;32m{YOUR RTV1 HAS BEEN CLEANED SUCCESSFULLY}\033[0;31m<<<<<<<<<<<<<<<<<<|"
	@echo "\033[0;31m ================================================================================"

fclean: clean
	@make fclean -C srcs/libft
	@rm -f $(NAME)

re: fclean all
.PHONY: fclean, clean, re, all, rtv1
