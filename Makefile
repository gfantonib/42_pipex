NAME = pipex

LIBFT = libft/libft.a

LIBFT_PATH = libft/

CFLAGS	= -Wextra -Wall -Werror -g

HEADERS	= -Iincludes

MK = mkdir -p

SOURCE_PATH = sources/

SRCS	= \
			pipex.c \
			utils.c \
			children.c \
			commands.c \
			free.c \

OBJECTS_PATH = objects

OBJS	= $(addprefix $(OBJECTS_PATH)/, $(SRCS:%.c=%.o))

all: $(LIBFT) $(NAME)

$(LIBFT):
	make -C $(LIBFT_PATH)

$(OBJECTS_PATH)/%.o: $(SOURCE_PATH)%.c
	$(MK) $(@D)
	$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) 

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(LIBFT) $(HEADERS) -o $(NAME)

clean:
	rm -rf $(OBJS)
	rm -rf $(OBJECTS_PATH)
	make clean -C $(LIBFT_PATH)

fclean: clean
	rm -rf $(NAME)
	make fclean -C $(LIBFT_PATH)

re: fclean all

.PHONY: all clean fclean re