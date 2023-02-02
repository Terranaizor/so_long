# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nradin <nradin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/31 17:23:33 by nradin            #+#    #+#              #
#    Updated: 2023/02/02 15:43:05 by nradin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = main.c					\
		color_manipulations.c	\
		checks.c				\
		parse_utils.c			\
		path.c					\
		read_utils.c			\
		render.c				\

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
	@gcc -o3 -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME) $(OBJECTS_PREFIXED) inc/libft/libft.a inc/printf/libftprintf.a mlx/libmlx.a

clean:
	@rm -rf $(OBJS_DIR)
	@make fclean -C $(LIBFT)
	@make fclean -C $(PRINTF)
	@make fclean -C $(MLX)


fclean: clean
	@rm -f $(NAME)

re: fclean all
