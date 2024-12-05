NAME = minishell

SRC_DIR = ./src
INC_DIR = ./inc
LIBFT_DIR = ./libft

LIBFT = $(LIBFT_DIR)/libft.a

SRC_FILES =	$(SRC_DIR)/main.c \
			$(SRC_DIR)/init_data_struct.c \
			$(SRC_DIR)/free.c \
			$(SRC_DIR)/get_input.c \
			$(SRC_DIR)/var_get_print.c \
			$(SRC_DIR)/var_export.c \
			$(SRC_DIR)/var_export_utils.c \
			$(SRC_DIR)/var_utils.c \
			$(SRC_DIR)/cd.c \
			$(SRC_DIR)/cd_utils.c \
			$(SRC_DIR)/pwd.c \
			$(SRC_DIR)/token_list.c \
			$(SRC_DIR)/token_list_utils.c \
			$(SRC_DIR)/cmd_list.c \
			$(SRC_DIR)/utils.c \
			$(SRC_DIR)/check_builtins.c \
			$(SRC_DIR)/exit.c \
			$(SRC_DIR)/echo.c \
			$(SRC_DIR)/expand_var.c \
			$(SRC_DIR)/expand_var_2.c \
			$(SRC_DIR)/expand_path.c \

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
