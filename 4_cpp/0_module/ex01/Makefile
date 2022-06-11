NAME	=	phonebook

SRCS_DIR	=	srcs
SRCS		:=	$(shell find $(SRCS_DIR) -name *.cpp)
OBJS_DIR	=	objs
OBJS		:=	$(SRCS:$(SRCS_DIR)/%.cpp=$(OBJS_DIR)/%.o)

INCLUDES	=	-Iincs

CC		=	c++
CFLAGS	=	-Wall -Werror -Wextra
DFLAGS	=	-g -fsanitize=address

RM		=	rm -f
RM_DIR	=	rm -rf

$(OBJS_DIR)/%.o:	$(SRCS_DIR)/%.cpp
					@mkdir -p $(OBJS_DIR)
					$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(NAME):	$(OBJS)
			$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) -o $(NAME)

all:		$(NAME)

clean:
			$(RM_DIR) $(OBJS_DIR)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

debug:		INCLUDES += -DDEBUG_MODE
debug:		CFLAGS += $(DFLAGS)
debug:		all

.PHONY:		all clean fclean re debug

