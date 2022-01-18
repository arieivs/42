NAME		=	philosophers

INC_DIR		=	includes
INCLUDES	=	-I$(INC_DIR)
SRCS_DIR	=	srcs
SRCS		=	$(wildcard $(SRCS_DIR)/*.c)
OBJS_DIR	=	objs
OBJS		=	$(patsubst $(SRCS_DIR)/%.c, $(OBJS_DIR)/%.o, $(SRCS))

CC			=	gcc
CFLAGS		=	-Wall -Werror -Wextra -pthread
RM			=	rm -f

all:				$(NAME)

$(NAME):			$(OBJS)
					$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(OBJS_DIR)/%.o:	$(SRCS_DIR)/%.c
					mkdir -p $(OBJS_DIR)
					$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
					$(RM) -r $(OBJS_DIR)

fclean:				clean
					$(RM) $(NAME)

re:					fclean all

.PHONY:				all clean fclean re
