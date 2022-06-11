NAME	=	account

SRCS	=	Account.cpp tests.cpp
OBJS	=	$(SRCS:.cpp=.o)

INCS	=	-I.

CC		=	c++
CFLAGS	=	-Wall -Werror -Wextra -std=c++98
DFLAGS	=	-fsanitize=address
RM		=	rm -f

.c.o:
			$(CC) $(CFLAGS) -c $< -o $(<:.cpp=.o)

$(NAME):	$(OBJS)
			$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

all:		$(NAME)

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

debug:		CFLAGS += $(DFLAGS)
debug:		all

.PHONY:		all clean fclean re debug

