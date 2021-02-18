SRCS	= withmalloc_main.c

OBJS	= ${SRCS:.c=.o}

LIBDIR	= ../libft

MAKE	= make

CC		= gcc

CFLAGS	= -Wall -Werror -Wextra -fsanitize=address

RM		= rm -f

NAME	= withmalloc

.c.o:
			${CC} ${CFLAGS} -I${LIBDIR} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			${MAKE} -C ${LIBDIR}
			${CC} -fsanitize=address -o ${NAME} ${OBJS} -L${LIBDIR} -lft

all:		${NAME}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
