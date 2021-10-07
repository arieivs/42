NAME =
SERVER =	server
CLIENT =	client

LIBFT_DIR =	./libft
LIBFT_LIB =	./libft/libft.a

INCLUDES =	-I. -I$(LIBFT_DIR)

CC =		gcc
CFLAGS =	-Wall -Werror -Wextra

SRCS_S =	server.c
SRCS_C =	client.c

OBJS_S =	$(SRCS_S:.c=.o)
OBJS_C =	$(SRCS_C:.c=.o)

RM =		rm -f

all:		$(SERVER) $(CLIENT)

$(NAME):	all

$(SERVER):
			make -C $(LIBFT_DIR)		
			$(CC) $(CFLAGS) $(SRCS_S) $(LIBFT_LIB) $(INCLUDES) -o $(SERVER)

$(CLIENT):
			make -C $(LIBFT_DIR)		
			$(CC) $(CFLAGS) $(SRCS_C) $(LIBFT_LIB) $(INCLUDES) -o $(CLIENT)

clean:
			make clean -C $(LIBFT_DIR)
			$(RM) $(OBJS_S) $(OBJS_C)

fclean:		clean
			make fclean -C $(LIBFT_DIR)
			$(RM) $(SERVER) $(CLIENT)

re:			fclean all

.PHONY:		all clean fclean re
