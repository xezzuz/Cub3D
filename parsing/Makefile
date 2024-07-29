# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nazouz <nazouz@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/22 15:35:00 by nazouz            #+#    #+#              #
#    Updated: 2024/07/29 15:51:15 by nazouz           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= 		cub3d

CC				= 		cc

CFLAGS			= 		-Wall -Werror -Wextra -g -g3 #-fsanitize=address

INCLUDE			=		./cub3d.h

SRCS			= 		\
						./utils/utils.c \
						./utils/ft_split.c \
						./utils/ft_atoi.c \
						./utils/get_next_line.c \
						./parsing.c \
						./parsing_utils.c \
						./parsing_utils_2.c \
						./parsing_utils_3.c \
						./parsing_validate.c \
						./exit.c \
						./helpers.c \
						./main.c

OBJS			= 		$(SRCS:.c=.o)

all : $(NAME) clean #######

%.o : %.c $(INCLUDE)
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : $(OBJS) $(INCLUDE)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME) $(OBJS)

re : fclean all