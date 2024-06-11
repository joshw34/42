NAME = libft.a

C_FILES =	ft_bzero.c \
			ft_calloc.c \
			ft_itoa.c \
			ft_strlen.c \

OBJ_FILES = $(C_FILES:.c=.o)

REMOVE = rm -f
CC = cc
CFLAGS = -Wall -Werror -Wextra

all: $(NAME)

libft:	all

$(NAME): $(OBJ_FILES)
		ar rcs $(NAME) $(OBJ_FILES)

clean:
	$(REMOVE) $(OBJ_FILES)

fclean:	clean
	$(REMOVE) $(NAME)

re:	fclean all

.PHONY: all clean fclean re
