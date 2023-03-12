# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nradin <nradin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/31 17:23:33 by nradin            #+#    #+#              #
#    Updated: 2023/03/04 15:17:07 by nradin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = main.c					\
		map_checks.c			\
		map_parse_utils.c		\
		map_path.c				\
		map_read_utils.c		\
		map_utils.c				\
		render.c				\
		picture_parsing.c		\
		game_exit.c				\
		input_handling.c		\

SRCS_BONUS = main.c				\
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
		render_utils.c			\
		render_beings.c			\
		render_enemies.c		\
		render_exit.c			\
		render_background.c		\
		render_player.c			\
		move_checks.c			\
		free_memory.c			\

NAME = so_long
BONUS = bonus

LIBFT = inc/libft/
PRINTF = inc/printf/
MLX = mlx/

SRCS_DIR = srcs/
SRCS_BONUS_DIR = srcs_bonus/

OBJS_DIR = objs/
OBJS_BONUS_DIR = objs_bonus/
OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)
OBJECTS_PREFIXED = $(addprefix $(OBJS_DIR), $(OBJS))
OBJECTS_BONUS_PREFIXED = $(addprefix $(OBJS_BONUS_DIR), $(OBJS_BONUS))

CC = gcc

CC_FLAGS = -Wall -Wextra -Werror

all: $(NAME) $(BONUS)

$(OBJS_DIR)%.o : $(SRCS_DIR)%.c inc/so_long.h
	@mkdir -p $(OBJS_DIR)
	@echo "Compiling: $<"
	@gcc $(CC_FLAGS) -O3 -c $< -o $@

$(OBJS_BONUS_DIR)%.o : $(SRCS_BONUS_DIR)%.c inc/so_long.h
	@mkdir -p $(OBJS_BONUS_DIR)
	@echo "Compiling: $<"
	@gcc $(CC_FLAGS) -O3 -c $< -o $@

$(NAME): $(OBJECTS_PREFIXED)
	@make -C $(LIBFT)
	@make -C $(PRINTF)
	@make -C $(MLX)
	@gcc -o3 -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME) $(OBJECTS_PREFIXED) inc/libft/libft.a inc/printf/libftprintf.a $(MLX)libmlx.a

$(BONUS): $(OBJECTS_BONUS_PREFIXED)
	@make -C $(LIBFT)
	@make -C $(PRINTF)
	@make -C $(MLX)
	@gcc -o3 -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(BONUS) $(OBJECTS_BONUS_PREFIXED) inc/libft/libft.a inc/printf/libftprintf.a $(MLX)libmlx.a
clean:
	@rm -rf $(OBJS_DIR)
	@rm -rf $(OBJS_BONUS_DIR)
	@make fclean -C $(LIBFT)
	@make fclean -C $(PRINTF)

fclean: clean
	@rm -f $(NAME)
	@rm -f $(BONUS)

re: fclean all
