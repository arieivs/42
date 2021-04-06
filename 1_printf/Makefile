INCDIR	= .

SRCS	= ft_printf.c parse.c c_print.c s_print.c di_print.c ux_print.c diux_print_utils.c p_print.c p_print_utils.c

SRCS_B	= n_print.c

OBJS	= ${SRCS:.c=.o}

OBJS_B	= ${SRCS_B:.c=.o}

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

bonus:		${OBJS} ${OBJS_B}
			${MAKE} -C ${LIBDIR}
			cp ${LIBDIR}/libft.a ./${NAME}
			${AR} ${NAME} ${OBJS} ${OBJS_B}

test:
			${CC} -Wall -Wextra main.c -L. -lftprintf -o test.out
			./test.out

all:		${NAME}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
