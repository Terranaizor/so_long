# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nradin <nradin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/31 17:23:33 by nradin            #+#    #+#              #
#    Updated: 2023/02/08 17:23:00 by nradin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = main.c					\
		color_manipulations.c	\
		map_checks.c			\
		map_parse_utils.c		\
		map_path.c				\
		map_read_utils.c		\
		map_utils.c				\
		render.c				\
		picture_parsing.c		\
		game_init.c				\
		game_exit.c				\
		input_handling.c		\

NAME = so_long

LIBFT = inc/libft/
PRINTF = inc/printf/
MLX = mlx/

SRCS_DIR = srcs/

OBJS_DIR = objs/
OBJS = $(SRCS:.c=.o)
OBJECTS_PREFIXED = $(addprefix $(OBJS_DIR), $(OBJS))

CC = gcc

CC_FLAGS = #-Wall -Wextra -Werror

all: $(NAME)

$(OBJS_DIR)%.o : $(SRCS_DIR)%.c inc/so_long.h
	@mkdir -p $(OBJS_DIR)
	@echo "Compiling: $<"
	@gcc $(CC_FLAGS) -c $< -o $@

$(NAME): $(OBJECTS_PREFIXED)
	@make -C $(LIBFT)
	@make -C $(PRINTF)
	@make -C $(MLX)
	@gcc -o3 -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME) $(OBJECTS_PREFIXED) inc/libft/libft.a inc/printf/libftprintf.a ./libmlx.dylib

clean:
	@rm -rf $(OBJS_DIR)
	@make fclean -C $(LIBFT)
	@make fclean -C $(PRINTF)

fclean: clean
	@rm -f $(NAME)

re: fclean all
