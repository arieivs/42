SRCS	= ft_display_file.c

OBJS	= ${SRCS:.c=.o}

CC		= gcc

CFLAGS	= -Wall -Werror -Wextra

RM		= rm -f

NAME	= ft_display_file

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
