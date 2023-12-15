NAME := pipex

LIBFT = libft/libft.a

CFLAGS	:= -Wextra -Wall -Werror
HEADERS	:= -Iincludes
MK = mkdir -p

SOURCE_PATH = sources/

SRCS	:= \
			pipex.c \

OBJECTS_PATH = objects
OBJS	:= $(addprefix $(OBJECTS_PATH)/, $(SRCS:%.c=%.o))

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

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re