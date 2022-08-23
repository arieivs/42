NAME	=	trap

SRCS_DIR	=	srcs
SRCS		:=	$(shell find $(SRCS_DIR) -name *.cpp)
OBJS_DIR	=	objs
OBJS		:=	$(SRCS:$(SRCS_DIR)/%.cpp=$(OBJS_DIR)/%.o)

INCS_DIR	=	incs
INCS		:=	-I$(INCS_DIR)

CC		=	c++
CFLAGS	=	-Wall -Werror -Wextra -std=c++98
DFLAGS	=	-Wshadow -fsanitize=address -g
RM		=	rm -f

$(OBJS_DIR)/%.o:	$(SRCS_DIR)/%.cpp
					@mkdir -p $(OBJS_DIR)
					$(CC) $(CFLAGS) $(INCS) -c $< -o $@

$(NAME):	$(OBJS)
			$(CC) $(CFLAGS) $(INCS) $(OBJS) -o $(NAME)

all:		$(NAME)

clean:
			$(RM) -r $(OBJS_DIR)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

debug:		CFLAGS += $(DFLAGS)
debug:		all

.PHONY:		all clean fclean re debug
