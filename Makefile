NAME = pipex

BONUS_NAME = bonus_pipex

LIBFT = libft/libft.a

LIBFT_PATH = libft/

CFLAGS	= -Wextra -Wall -Werror -g

HEADERS	= -Iincludes

MK = mkdir -p

SOURCE_PATH = sources/

BONUS_SOURCE_PATH = bonus_sources/

SRCS	= \
			pipex.c \
			commands.c \
			files.c \
			exec.c \
			free.c \
			error.c \

BONUS_SRCS	= \

OBJECTS_PATH = objects

BONUS_OBJECTS_PATH = bonus_objects

OBJS	= $(addprefix $(OBJECTS_PATH)/, $(SRCS:%.c=%.o))

BONUS_OBJS	= $(addprefix $(BONUS_OBJECTS_PATH)/, $(BONUS_SRCS:%.c=%.o))

all: $(LIBFT) $(NAME)

$(LIBFT):
	make -C $(LIBFT_PATH)

$(OBJECTS_PATH)/%.o: $(SOURCE_PATH)%.c
	$(MK) $(@D)
	$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) 

$(BONUS_OBJECTS_PATH)/%.o: $(BONUS_SOURCE_PATH)%.c
	$(MK) $(@D)
	$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) 

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(LIBFT) $(HEADERS) -o $(NAME)

$(BONUS_NAME): $(BONUS_OBJS)
	$(CC) $(BONUS_OBJS) $(LIBFT) $(HEADERS) -o $(BONUS_NAME)

clean:
	rm -rf $(OBJECTS_PATH) $(BONUS_OBJECTS_PATH)
	make clean -C $(LIBFT_PATH)

fclean: clean
	rm -rf $(NAME) $(BONUS_NAME)
	make fclean -C $(LIBFT_PATH)

#bonus: $(LIBFT) $(BONUS_NAME)

re: fclean all

.PHONY: all clean fclean re