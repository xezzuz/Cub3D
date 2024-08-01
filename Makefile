# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nazouz <nazouz@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/26 18:56:33 by mmaila            #+#    #+#              #
#    Updated: 2024/08/01 10:49:13 by nazouz           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= 		Cub3D

CC				= 		cc

CFLAGS			= 		-Wall -Werror -Wextra

INCLUDE			=		./headers/cub3d.h ./mlx/mlx.h

MLXLIB			=		mlx/libmlx.a

MLX				=		$(MLXLIB) -lm -framework OpenGL -framework AppKit

SRCS			= 		./cub3d.c \
						./init.c \
						./engine/intersection.c \
						./engine/mlx.c \
						./engine/walls.c \
						./engine/gameloop.c \
						./engine/minimap.c \
						./engine/update.c \
						./events/keypress.c \
						./events/mouse_events.c \
						./events/animation.c \
						./parsing/parsing.c \
						./parsing/parsing_config.c \
						./parsing/parsing_utils.c \
						./parsing/parsing_map.c \
						./parsing/parsing_map_2.c \
						./parsing/parsing_map_utils.c \
						./parsing/parsing_map_utils_2.c \
						./parsing/parsing_textures.c \
						./parsing/parsing_textures_utils.c \
						./parsing/exit.c \
						./parsing/free_mlx.c \
						./parsing/utils/ft_split.c \
						./parsing/utils/ft_itoa.c \
						./parsing/utils/get_next_line.c \
						./parsing/utils/utils_2.c \
						./parsing/utils/utils.c

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