INCDIR	= ft_tail.h

SRCS	= ft_atoi.c	ft_tail.c	ft_tail2.c

OBJS	= ${SRCS:.c=.o}

NAME	= ft_tail

CC		= gcc

CFLAGS	= -Wall -Werror -Wextra

RM		= rm -f

.c.o:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			${CC} -o ${NAME} ${OBJS}

all:		${NAME}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
