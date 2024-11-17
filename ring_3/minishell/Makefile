NAME = minishell

SRC_DIR = ./src
INC_DIR = ./inc
LIBFT_DIR = ./libft

LIBFT = $(LIBFT_DIR)/libft.a

SRC_FILES =	$(SRC_DIR)/main.c \
			$(SRC_DIR)/utils.c \
			$(SRC_DIR)/read_input.c \
			$(SRC_DIR)/run_commands.c \
			$(SRC_DIR)/free_exit.c \
			
OBJ_FILES = $(SRC_FILES:.c=.o)

REMOVE = rm -f
CC = clang
CFLAGS = -Wall -Werror -Wextra -I$(INC_DIR) -I$(LIBFT_DIR)
LDFLAGS = -lreadline -lhistory

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ_FILES)
	@echo "Compiling/Linking"
	@$(CC) $(CFLAGS) $(OBJ_FILES) $(LDFLAGS) $(LIBFT) -o $(NAME)
	@echo "Ready"

$(LIBFT):
	@echo "Libft: Compiling"
	@make -s all -C $(LIBFT_DIR)
	
.c.o:
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@make -s clean -C $(LIBFT_DIR)
	@echo "Removing .o files"
	@$(REMOVE) $(OBJ_FILES)

fclean:	clean
	@make -s fclean -C $(LIBFT_DIR)
	@echo "Removing executable"
	@$(REMOVE) $(NAME)

re:	fclean all

.PHONY: all clean fclean re
