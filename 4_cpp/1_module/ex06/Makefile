NAME	=	harlFilter

SRCS	=	main.cpp Harl.cpp
OBJS	=	$(SRCS:.cpp=.o)
INCS	=	-I.

CC		=	c++
CFLAGS	=	-Wall -Werror -Wextra -std=c++98
DFLAGS	=	-fsanitize=address -g
RM		=	rm -f

.c.o:
		$(CC) $(CFLAGS) $(INCS) -c $< -o $(<:.cpp=.o)

$(NAME):	$(OBJS)
			$(CC) $(CFLAGS) $(INCS) $(OBJS) -o $(NAME)

all:		$(NAME)

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

debug:		CFLAGS += $(DFLAGS)
debug:		all

.PHONY:		all clean fclean re debug