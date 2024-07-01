NAME = push_swap

SRC_DIR = ./src
INC_DIR = ./inc
LIBFT_DIR = ./libft

SRC_FILES =	$(SRC_DIR)/main.c \
			$(SRC_DIR)/error_handling/error_checking.c \
			$(SRC_DIR)/error_handling/free_quit.c \
			$(SRC_DIR)/stack_utils/create_stacks.c \
			$(SRC_DIR)/stack_utils/node_utils.c \
			$(SRC_DIR)/stack_utils/push_cost.c \
			$(SRC_DIR)/stack_utils/target_index_top.c \
			$(SRC_DIR)/stack_operations/swap.c \
			$(SRC_DIR)/stack_operations/rotate.c \
			$(SRC_DIR)/stack_operations/rev_rotate.c \
			$(SRC_DIR)/stack_operations/push.c \
			$(SRC_DIR)/sort_stack/sort.c \
			$(SRC_DIR)/sort_stack/sort_utils.c \
			$(SRC_DIR)/sort_stack/push_a_to_b.c \
			$(SRC_DIR)/sort_stack/push_b_to_a.c \
			$(SRC_DIR)/print_test.c \

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

