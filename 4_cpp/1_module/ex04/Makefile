NAME	=	sed

SRCS		=	main.cpp
OBJS		=	$(SRCS:.cpp=.o)
INCLUDES	=	-I.

CC		=	c++
CFLAGS	=	-Wall -Werror -Wextra -std=c++98
DFLAGS	=	-g -fsanitize=address

RM		=	rm -f

.c.o:
		$(CC) $(CFLAGS) $(INCS) -c $< -o $(<:.cpp=.o)

$(NAME):	$(OBJS)
			$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) -o $(NAME)

all:		$(NAME)

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

debug:		CFLAGS += $(DFLAGS)
debug:		all

.PHONY:		all clean fclean re debug
