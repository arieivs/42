NAME =		push_swap

LFT_DIR =	libft

LFT_LIB =	-L$(LFT_DIR) -lft

INCLUDES =	-Iincludes -I$(LFT_DIR)

CC =		gcc

CFLAGS =	-Wall -Werror -Wextra -fsanitize=address

SRCS =		main.c ops.c interface.c

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
