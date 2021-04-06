INCDIR	= .

SRCS	= ft_printf.c parse.c convs/c_print.c convs/s_print.c convs/di_print.c convs/ux_print.c convs/diux_print_utils.c convs/p_print.c convs/p_print_utils.c

SRCS_B	= convs/n_print.c convs/dih_print.c convs/uxh_print.c convs/dill_print.c

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
			${RM} ${OBJS} ${OBJS_B}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
