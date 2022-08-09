NAME	=	fixed

SRCS	=	main.cpp Fixed.cpp Point.cpp bsp.cpp
OBJS	=	$(SRCS:.cpp=.o)

INC		=	-I.

CC		=	c++
CFLAGS	=	-Wall -Werror -Wextra -std=c++98
DFLAGS	=	-fsanitize=address -g
RM		=	rm -f

.cpp.o:
			$(CC) $(CFLAGS) $(INC) -c $< -o $(<:.cpp=.o)

$(NAME):	$(OBJS)
			$(CC) $(CFLAGS) $(INC) $(OBJS) -o $(NAME)

all:		$(NAME)

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

debug:		CFLAGS += $(DFLAGS)
debug:		all

.PHONY:		all clean fclean re debug
