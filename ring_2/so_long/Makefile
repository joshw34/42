NAME = so_long
BONUS_NAME = so_long_bonus

SRC_DIR = ./src
BONUS_SRC_DIR = ./bonus_src
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

BONUS_SRC_FILES = $(BONUS_SRC_DIR)/so_long_bonus.c \
				  $(BONUS_SRC_DIR)/parse_map_bonus.c \
				  $(BONUS_SRC_DIR)/check_map_bonus.c \
				  $(BONUS_SRC_DIR)/validate_map_bonus.c \
				  $(BONUS_SRC_DIR)/game_bonus.c \
				  $(BONUS_SRC_DIR)/game_draw_bonus.c \
				  $(BONUS_SRC_DIR)/game_hooks_bonus.c \
				  $(BONUS_SRC_DIR)/game_move_bonus.c \
				  $(BONUS_SRC_DIR)/free_data_bonus.c \
				  $(BONUS_SRC_DIR)/utils_bonus.c

OBJ_FILES = $(SRC_FILES:.c=.o)
BONUS_OBJ_FILES = $(BONUS_SRC_FILES:.c=.o)

REMOVE = rm -f
CC = clang
CFLAGS = -Wall -Werror -Wextra -I$(INC_DIR) -I$(LIBFT_DIR) -I$(MLX_DIR)

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ_FILES)
	@echo "$(NAME): Linking"
	@$(CC) $(OBJ_FILES) $(LIBFT) $(MLX_LIB) $(MLX_FLAGS) -o $(NAME)
	@echo "$(NAME): Ready"

$(LIBFT):
	@echo "Libft: Compiling"
	@make -s all -C $(LIBFT_DIR)

bonus: $(BONUS_NAME)

$(BONUS_NAME): $(LIBFT) $(BONUS_OBJ_FILES)
	@echo "so_long bonus: Linking"
	@$(CC) $(BONUS_OBJ_FILES) $(LIBFT) $(MLX_LIB) $(MLX_FLAGS) -o $(BONUS_NAME)
	@mv so_long_bonus so_long
	@echo "so_long bonus: Ready"

.c.o:
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@make -s clean -C $(LIBFT_DIR)
	@$(REMOVE) $(OBJ_FILES) $(BONUS_OBJ_FILES)
	@echo "so_long: Object Files Removed"

fclean:
	@make -s fclean -C $(LIBFT_DIR)
	@$(REMOVE) $(OBJ_FILES) $(BONUS_OBJ_FILES)
	@echo "so_long: Object Files Removed"
	@$(REMOVE) $(NAME)
	@echo "so_long: Executable Removed"

re: fclean all

.PHONY: all clean fclean re bonus
