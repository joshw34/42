NAME = push_swap

SRC_DIR = ./src
INC_DIR = ./inc
LIBFT_DIR = ./libft

SRC_FILES =	$(SRC_DIR)/push_swap.c \
			$(SRC_DIR)/error_checking.c \
			$(SRC_DIR)/free_quit.c \
			$(SRC_DIR)/create_stack_a.c \
			$(SRC_DIR)/stack_tools.c \
			$(SRC_DIR)/stack_tools_2.c \
			$(SRC_DIR)/swap.c \

OBJ_FILES = $(SRC_FILES:.c=.o)

LIBFT = $(LIBFT_DIR)/libft.a

REMOVE = rm -f
CC = gcc
CFLAGS = -Wall -Werror -Wextra -I$(INC_DIR) -I$(LIBFT_DIR)

all: $(NAME)

$(NAME): $(OBJ_FILES) $(LIBFT)
		$(CC) $(CFLAGS) $(OBJ_FILES) $(LIBFT) -o $(NAME)

$(LIBFT):
	make all -C $(LIBFT_DIR)

clean:
	$(REMOVE) $(OBJ_FILES)
	make clean -C $(LIBFT_DIR)

fclean:	clean
	$(REMOVE) $(NAME)
	make fclean -C $(LIBFT_DIR)

re:	fclean all

.PHONY: all clean fclean re

