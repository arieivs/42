NAME =		push_swap

LFT_DIR =	libft

LFT_LIB =	-L$(LFT_DIR) -lft

INCLUDES =	-Iincludes -I$(LFT_DIR)

CC =		gcc

CFLAGS =	-Wall -Werror -Wextra -fsanitize=address

SRCS =		main.c list_utils.c list_utils2.c interface_input.c interface_output.c ops.c sort_utils.c sort_algol.c sort_big_algol.c

OBJS =		${SRCS:.c=.o}

RM =		rm -f

.c.o:
			$(CC) $(CFLAGS) $(INCLUDES) -c $< -o ${<:.c=.o}

$(NAME):	$(OBJS)
			make -C $(LFT_DIR)
			$(CC) $(CFLAGS) $(OBJS) $(LFT_LIB) -o $(NAME)

all:		$(NAME)

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re	
