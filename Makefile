# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nazouz <nazouz@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/26 18:56:33 by mmaila            #+#    #+#              #
#    Updated: 2024/07/26 19:11:22 by nazouz           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= 		cub2d

CC				= 		cc

CFLAGS			= 		-Wall -Werror -Wextra -g3

INCLUDE			=		cub2d.h

SRCS			= 		cub2d.c \
						draw_game.c \
						keypress.c \
						render_game.c \
						render_game_utils.c \
						update_game.c \
						mouse_events.c

OBJS			= 		$(SRCS:.c=.o)

all : $(NAME)

%.o : %.c $(INCLUDE)
	@echo "\033[5;34mCompiling ${notdir $<}\033[0m"
	@$(CC) $(CFLAGS) -O3 -Imlx -c $< -o $@

$(NAME) : $(OBJS) $(INCLUDE)
	@$(CC) $(CFLAGS) -lmlx -framework OpenGL -framework AppKit $(OBJS) -o $(NAME)
	@echo "\033[1;32mSUCCESS\033[0m"

clean :
	@echo "\033[3;31mCleaning...\033[0m"
	@rm -rf $(OBJS)

fclean : clean
	@rm -rf $(NAME) $(OBJS)

re : fclean all