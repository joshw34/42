NAME = so_long

SRC_DIR = ./src
INC_DIR = ./inc
LIBFT_DIR = ./libft
MLX_DIR = $(INC_DIR)/minilibx

LIBFT = $(LIBFT_DIR)/libft.a
MLX_LIB = $(shell realpath $(MLX_DIR)/libmlx.a)
MLX_FLAGS = -L$(MLX_DIR) -lmlx -lXext -lX11

SRC_FILES = $(SRC_DIR)/so_long.c \
            $(SRC_DIR)/parse_map.c \
            $(SRC_DIR)/check_map.c \
            $(SRC_DIR)/validate_map.c \
            $(SRC_DIR)/game.c \
            $(SRC_DIR)/game_draw.c \
            $(SRC_DIR)/game_hooks.c \
            $(SRC_DIR)/game_move.c \
            $(SRC_DIR)/free_data.c \
            $(SRC_DIR)/utils.c

OBJ_FILES = $(SRC_FILES:.c=.o)

REMOVE = rm -f
CC = clang
CFLAGS = -Wall -Werror -Wextra -I$(INC_DIR) -I$(LIBFT_DIR) -I$(MLX_DIR)

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ_FILES)
	@echo "so_long: Linking"
	@$(CC) $(OBJ_FILES) $(LIBFT) $(MLX_LIB) $(MLX_FLAGS) -o $(NAME)
	@echo "so_long: Ready"

$(LIBFT):
	@echo "Libft: Compiling"
	@make -s all -C $(LIBFT_DIR)

.c.o:
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@make -s clean -C $(LIBFT_DIR)
	@$(REMOVE) $(OBJ_FILES)
	@echo "so_long: Object Files Removed"

fclean:
	@make -s fclean -C $(LIBFT_DIR)
	@$(REMOVE) $(OBJ_FILES)
	@echo "so_long: Object Files Removed"
	@$(REMOVE) $(NAME)
	@echo "so_long: Executable Removed"

re: fclean all

.PHONY: all clean fclean re
