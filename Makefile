# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nazouz <nazouz@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/01 16:13:58 by nazouz            #+#    #+#              #
#    Updated: 2024/08/01 18:14:37 by nazouz           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= 		cub3D

NAME_BONUS		= 		cub3D_bonus

CC				= 		cc

CFLAGS			= 		-Wall -Werror -Wextra

INCLUDE			=		mandatory/headers/cub3d.h

INCLUDE_BONUS	=		bonus/headers/cub3d_bonus.h

MLX				=		-lmlx -framework OpenGL -framework AppKit

MLX_BONUS		=		./bonus/mlx/libmlx.a -lm -framework OpenGL -framework AppKit

SRCS			= 		mandatory/cub3d.c \
						mandatory/init.c \
						mandatory/engine/intersection.c \
						mandatory/engine/mlx.c \
						mandatory/engine/walls.c \
						mandatory/engine/gameloop.c \
						mandatory/engine/update.c \
						mandatory/events/keypress.c \
						mandatory/parsing/parsing.c \
						mandatory/parsing/parsing_config.c \
						mandatory/parsing/parsing_utils.c \
						mandatory/parsing/parsing_map.c \
						mandatory/parsing/parsing_map_2.c \
						mandatory/parsing/parsing_map_utils.c \
						mandatory/parsing/parsing_map_utils_2.c \
						mandatory/parsing/parsing_textures.c \
						mandatory/parsing/parsing_textures_utils.c \
						mandatory/parsing/exit.c \
						mandatory/parsing/free_mlx.c \
						mandatory/parsing/utils/ft_split.c \
						mandatory/parsing/utils/ft_itoa.c \
						mandatory/parsing/utils/get_next_line.c \
						mandatory/parsing/utils/utils_2.c \
						mandatory/parsing/utils/utils.c

SRCS_BONUS		= 		bonus/cub3d_bonus.c \
						bonus/init_bonus.c \
						bonus/engine/intersection_bonus.c \
						bonus/engine/mlx_bonus.c \
						bonus/engine/walls_bonus.c \
						bonus/engine/gameloop_bonus.c \
						bonus/engine/minimap_bonus.c \
						bonus/engine/update_bonus.c \
						bonus/events/keypress_bonus.c \
						bonus/events/mouse_events_bonus.c \
						bonus/events/animation_bonus.c \
						bonus/parsing/parsing_bonus.c \
						bonus/parsing/parsing_config_bonus.c \
						bonus/parsing/parsing_utils_bonus.c \
						bonus/parsing/parsing_map_bonus.c \
						bonus/parsing/parsing_map_2_bonus.c \
						bonus/parsing/parsing_map_utils_bonus.c \
						bonus/parsing/parsing_map_utils_2_bonus.c \
						bonus/parsing/parsing_textures_bonus.c \
						bonus/parsing/parsing_textures_utils_bonus.c \
						bonus/parsing/exit_bonus.c \
						bonus/parsing/free_mlx_bonus.c \
						bonus/parsing/utils/ft_split.c \
						bonus/parsing/utils/ft_itoa.c \
						bonus/parsing/utils/get_next_line.c \
						bonus/parsing/utils/utils_2.c \
						bonus/parsing/utils/utils.c

OBJS			= 		$(SRCS:.c=.o)

OBJS_BONUS		= 		$(SRCS_BONUS:.c=.o)

all : $(NAME)

%.o : %.c $(INCLUDE) $(INCLUDE_BONUS)
	@echo "\033[5;34mCompiling ${notdir $<}\033[0m"
	@$(CC) $(CFLAGS) -O3 -c $< -o $@

$(NAME) : $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(MLX) -o $(NAME)
	@echo "\033[1;32mSUCCESS\033[0m"

$(NAME_BONUS) : $(OBJS_BONUS)
	@$(CC) $(CFLAGS) $(OBJS_BONUS) $(MLX_BONUS) -o $(NAME_BONUS)
	@echo "\033[1;32mSUCCESS\033[0m"

bonus : $(NAME_BONUS)

clean :
	@echo "\033[3;31mCleaning...\033[0m"
	@rm -rf $(OBJS) $(OBJS_BONUS)

fclean : clean
	@rm -rf $(NAME) $(OBJS) $(NAME_BONUS) $(OBJS_BONUS)

re : fclean all