# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nazouz <nazouz@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/26 18:56:33 by mmaila            #+#    #+#              #
#    Updated: 2024/07/27 17:27:18 by nazouz           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= 		cub2d

CC				= 		cc

CFLAGS			= 		-Wall -Werror -Wextra -g3

INCLUDE			=		cub3d.h mlx/mlx.h

MLXLIB			=		mlx/libmlx.a

MLX				=		$(MLXLIB) -lm -framework OpenGL -framework AppKit

SRCS			= 		cub3d.c \
						./engine/render_walls.c \
						./engine/render_game.c \
						./engine/render_game_utils.c \
						./engine/update_game.c \
						./events/keypress.c \
						./events/mouse_events.c

OBJS			= 		$(SRCS:.c=.o)

all : $(NAME)

%.o : %.c $(INCLUDE)
	@echo "\033[5;34mCompiling ${notdir $<}\033[0m"
	@$(CC) $(CFLAGS) -O3 -I ./mlx -c $< -o $@

$(NAME) : $(OBJS) $(INCLUDE)
	$(CC) $(CFLAGS) $(OBJS) $(MLX) -o $(NAME)
	@echo "\033[1;32mSUCCESS\033[0m"

clean :
	@echo "\033[3;31mCleaning...\033[0m"
	@rm -rf $(OBJS)

fclean : clean
	@rm -rf $(NAME) $(OBJS)

re : fclean all