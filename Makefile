NAME = pipex

BONUS_NAME = pipex_bonus

LIBFT = libs/libft/libft.a

LIBFT_PATH = libs/libft/

GET_NEXT_LINE = libs/get_next_line/get_next_line.a

GET_NEXT_LINE_PATH = libs/get_next_line/

CFLAGS	= -Wextra -Wall -Werror -g

HEADERS	= -Iincludes

MK = mkdir -p

SOURCE_PATH = sources/

BONUS_SOURCE_PATH = sources_bonus/

SRCS	= \
			pipex.c \
			commands.c \
			files.c \
			exec.c \
			free.c \
			error.c \
			close.c \

BONUS_SRCS	= \
			pipex_bonus.c \
			commands_bonus.c \
			files_bonus.c \
			exec_bonus.c \
			free_bonus.c \
			error_bonus.c \
			close_bonus.c \
			heredoc_bonus.c \

OBJECTS_PATH = objects

BONUS_OBJECTS_PATH = bonus_objects

OBJS = $(addprefix $(OBJECTS_PATH)/, $(SRCS:%.c=%.o))

BONUS_OBJS	= $(addprefix $(BONUS_OBJECTS_PATH)/, $(BONUS_SRCS:%.c=%.o))

all: $(LIBFT) $(NAME)

$(LIBFT):
	make -C $(LIBFT_PATH)

$(GET_NEXT_LINE):
	make -C $(GET_NEXT_LINE_PATH)

$(OBJECTS_PATH)/%.o: $(SOURCE_PATH)%.c
	$(MK) $(@D)
	$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) 

$(BONUS_OBJECTS_PATH)/%.o: $(BONUS_SOURCE_PATH)%.c
	$(MK) $(@D)
	$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) 

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(LIBFT) $(HEADERS) -o $(NAME)

$(BONUS_NAME): $(BONUS_OBJS)
	$(CC) $(BONUS_OBJS) $(LIBFT) $(GET_NEXT_LINE) $(HEADERS) -o $(BONUS_NAME)

clean:
	rm -rf $(OBJECTS_PATH) $(BONUS_OBJECTS_PATH)
	make clean -C $(LIBFT_PATH)
	make clean -C $(GET_NEXT_LINE_PATH)

fclean: clean
	rm -rf $(NAME) $(BONUS_NAME)
	make fclean -C $(LIBFT_PATH)
	make fclean -C $(GET_NEXT_LINE_PATH)

bonus: $(LIBFT) $(GET_NEXT_LINE) $(BONUS_NAME)

re: fclean all

re_bonus: fclean bonus

val: 
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --track-fds=yes \
	--trace-children=yes --trace-children-skip=*/bin/*,*/sbin/* \
	./pipex_bonus here_doc AOF "cat -e" "grep melvin" file2

.PHONY: all clean fclean re val