NAME = pipex

SRC_DIR = ./src
INC_DIR = ./inc
LIBFT_DIR = ./libft

LIBFT = $(LIBFT_DIR)/libft.a

SRC_FILES =	$(SRC_DIR)/main.c \
			$(SRC_DIR)/error_management/parse_check_input.c \
			$(SRC_DIR)/error_management/free.c \
			$(SRC_DIR)/utils/utils.c \

OBJ_FILES = $(SRC_FILES:.c=.o)

REMOVE = rm -f
CC = gcc
CFLAGS = -Wall -Werror -Wextra -I$(INC_DIR) -I$(LIBFT_DIR)

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ_FILES)
	@echo "Pipex:	Compiling"
	@$(CC) $(CFLAGS) $(OBJ_FILES) $(LIBFT) -o $(NAME)
	@echo "Pipex:	Compiled"

$(LIBFT):
	@echo "Libft:	Compiling"
	@make -s all -C $(LIBFT_DIR)

.c.o:
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@make -s clean -C $(LIBFT_DIR)
	@$(REMOVE) $(OBJ_FILES)
	@echo "Pipex:	Object Files Removed"

fclean:
	@make -s fclean -C $(LIBFT_DIR)
	@$(REMOVE) $(OBJ_FILES)
	@echo "Pipex:	Object Files Removed"
	@$(REMOVE) $(NAME)
	@echo "Pipex:	Executable Removed"

re:	fclean all

.PHONY: all clean fclean re
