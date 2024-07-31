# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nazouz <nazouz@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/26 18:56:33 by mmaila            #+#    #+#              #
#    Updated: 2024/07/31 13:30:57 by nazouz           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= 		Cub3D

CC				= 		cc

CFLAGS			= 		-Wall -Werror -Wextra -g3

INCLUDE			=		./headers/cub3d.h ./mlx/mlx.h

MLXLIB			=		mlx/libmlx.a

MLX				=		$(MLXLIB) -lm -framework OpenGL -framework AppKit

SRCS			= 		./cub3d.c \
						./init.c \
						./engine/intercection.c \
						./engine/mlx.c \
						./engine/render_walls.c \
						./engine/render_game.c \
						./engine/render_game_utils.c \
						./engine/update_game.c \
						./events/keypress.c \
						./events/mouse_events.c \
						./events/animation.c \
						./parsing/parsing.c \
						./parsing/parsing_utils.c \
						./parsing/parsing_utils_2.c \
						./parsing/parsing_utils_3.c \
						./parsing/parsing_utils_4.c \
						./parsing/parsing_validate.c \
						./parsing/parsing_validate_2.c \
						./parsing/exit.c \
						./parsing/utils/ft_split.c \
						./parsing/utils/ft_itoa.c \
						./parsing/utils/get_next_line.c \
						./parsing/utils/utils_2.c \
						./parsing/utils/utils.c \
						./parsing/helpers.c  #please remove this file, its for debugging puposes

OBJS			= 		$(SRCS:.c=.o)

all : $(NAME)

%.o : %.c $(INCLUDE)
	@echo "\033[5;34mCompiling ${notdir $<}\033[0m"
	@$(CC) $(CFLAGS) -O3 -I ./mlx -c $< -o $@

$(NAME) : $(OBJS) $(INCLUDE)
	@$(CC) $(CFLAGS) $(OBJS) $(MLX) -o $(NAME)
	@echo "\033[1;32mSUCCESS\033[0m"

clean :
	@echo "\033[3;31mCleaning...\033[0m"
	@rm -rf $(OBJS)

fclean : clean
	@rm -rf $(NAME) $(OBJS)

re : fclean all