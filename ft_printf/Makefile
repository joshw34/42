NAME = libftprintf.a

C_FILES =	ft_printf.c \
			print_dec.c \
			print_hex.c \
			print_ptr.c \
			print_text.c \

OBJ_FILES = $(C_FILES:.c=.o)

REMOVE = rm -f
CC = cc
CFLAGS = -Wall -Werror -Wextra

all: $(NAME)

ft_printf:	all

$(NAME): $(OBJ_FILES)
		$(MAKE) -C ./libft all
		cp ./libft/libft.a .
		mv libft.a $(NAME)
		ar rcs $(NAME) $(OBJ_FILES)

clean:
	$(REMOVE) $(OBJ_FILES)
	$(MAKE) -C ./libft clean

fclean:	clean
	$(REMOVE) $(NAME)
	$(MAKE) -C ./libft fclean

re:	fclean all

.PHONY: all clean fclean re

