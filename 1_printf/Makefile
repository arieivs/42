INCDIR	= .

SRCS	= ft_printf.c d_print.c d_print_utils.c

OBJS	= ${SRCS:.c=.o}

LIBDIR	= ./libft

MAKE	= make

AR		= ar rcs

CC		= gcc

CFLAGS	= -Wall -Werror -Wextra

RM		= rm -f

NAME	= libftprintf.a

.c.o:
			${CC} ${CFLAGS} -I${INCDIR} -c $< -o ${<:.c=.o}

libft:
			${MAKE} -C ${LIBDIR}
			cp ${LIBDIR}/libft.a ./${NAME}

${NAME}:	libft ${OBJS}
			${AR} ${NAME} ${OBJS}

test:
			${CC} ${CFLAGS} main.c -L. -lftprintf

all:		${NAME}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		libft all clean fclean re
