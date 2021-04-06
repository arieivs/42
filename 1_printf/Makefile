INCDIR	= .

SRCS	= ft_printf.c parse.c c_print.c s_print.c di_print.c ux_print.c diux_print_utils.c p_print.c p_print_utils.c n_print.c

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

${NAME}:	${OBJS}
			${MAKE} -C ${LIBDIR}
			cp ${LIBDIR}/libft.a ./${NAME}
			${AR} ${NAME} ${OBJS}

test:
			${CC} ${CFLAGS} main.c -L. -lftprintf

# bonus rule needs to be changed
bonus:		${NAME}

all:		${NAME}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
