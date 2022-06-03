NAME	=	megaphone

SRCS	=	megaphone.cpp
OBJS	=	$(SRCS:.cpp=.o)

CC		=	c++
CFLAGS	=	-Wall -Wextra -Werror -std=c++98
DFLAGS	=	-g -fsanitize=address
RM		=	rm -f

.c.o:
			$(CC) $(CFLAGS) -c $< -o ${<:.cpp=.o}

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

