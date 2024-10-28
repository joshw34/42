NAME = philo

SRC_DIR = ./src
INC_DIR = ./inc

SRC_FILES =	$(SRC_DIR)/main.c \
			$(SRC_DIR)/init_structs.c \
			$(SRC_DIR)/init_structs_utils.c \
			$(SRC_DIR)/free.c \
			$(SRC_DIR)/utils.c \
			$(SRC_DIR)/run_sim.c \
			$(SRC_DIR)/waiter.c \
			$(SRC_DIR)/monitor.c \
			
OBJ_FILES = $(SRC_FILES:.c=.o)

REMOVE = rm -f
CC = clang
CFLAGS = -Wall -Werror -Wextra -I$(INC_DIR) -pthread

all: $(NAME)

$(NAME): $(OBJ_FILES)
	@echo "Compiling/Linking"
	@$(CC) $(CFLAGS) $(OBJ_FILES) -o $(NAME)
	@echo "Ready"

.c.o:
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "Removing .o files"
	@$(REMOVE) $(OBJ_FILES)

fclean:	clean
	@echo "Removing executable"
	@$(REMOVE) $(NAME)

re:	fclean all

.PHONY: all clean fclean re