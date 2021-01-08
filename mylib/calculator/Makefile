SRCS	= ft_atoi.c ft_ops.c ft_do_op.c ft_putnbr.c ft_valid_op.c main.c

OBJS	= ${SRCS:.c=.o}

NAME	= do-op

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
