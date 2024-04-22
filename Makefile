NAME			= 		cub3d

CC				= 		cc

CFLAGS			= 		-Wall -Werror -Wextra -g3 -fsanitize=address

INCLUDE			=		./cub3d.h

SRCS			= 		\
						./utils/utils.c \
						./utils/ft_split.c \
						./parsing.c \
						./parsing_utils.c \
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