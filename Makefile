# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nazouz <nazouz@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/22 15:35:00 by nazouz            #+#    #+#              #
#    Updated: 2024/04/22 17:07:03 by nazouz           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= 		cub3d

CC				= 		cc

CFLAGS			= 		-Wall -Werror -Wextra -g3 -fsanitize=address

INCLUDE			=		./cub3d.h

SRCS			= 		\
						./utils/utils.c \
						./utils/ft_split.c \
						./utils/ft_atoi.c \
						./parsing.c \
						./parsing_utils.c \
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