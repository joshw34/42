CC = cc

CFLAGS += -c -Wall -Werror -Wextra

SOURCES = ./srcs/ft_putchar.c \
	./srcs/ft_swap.c \
	./srcs/ft_putstr.c \
	./srcs/ft_strlen.c \
	./srcs/ft_strcmp.c

SOURCE_DIR = ./srcs/

OBJECTS = ./srcs/ft_putchar.o \
	./srcs/ft_swap.o \
	./srcs/ft_putstr.o \
	./srcs/ft_strlen.o \
	./srcs/ft_strcmp.o

INCLUDES = ./includes/ft.h

NAME = libft.a

CUR_DIR = $(shell pwd)

all: sources library

libft.a: sources library

sources: $(SOURCES) $(INCLUDES)
	@echo "Compiling ft_putchar"
	$(CC) $(CFLAGS) ./srcs/ft_putchar.c -o ./srcs/ft_putchar.o
	@echo "Compiling ft_swap"
	$(CC) $(CFLAGS) ./srcs/ft_swap.c -o ./srcs/ft_swap.o
	@echo "Compiling ft_putstr"
	$(CC) $(CFLAGS) ./srcs/ft_putstr.c -o ./srcs/ft_putstr.o
	@echo "Compiling ft_strlen"
	$(CC) $(CFLAGS) ./srcs/ft_strlen.c -o ./srcs/ft_strlen.o
	@echo "Compiling ft_strcmp"
	$(CC) $(CFLAGS) ./srcs/ft_strcmp.c -o ./srcs/ft_strcmp.o
	@echo "Source files succesfully compiled"

library: $(OBJECTS)
	@echo "Combining object files and creating libft.a"
	ar -rc $(NAME) $(OBJECTS)
	ranlib $(NAME)
	@echo "libft.a successfully created"

clean:
	@echo "Removing object files from $(SOURCE_DIR)"
	rm ./srcs/*.o
	@echo "Object files successfully removed"

fclean: clean
	@echo "Removing libft.a from $(CUR_DIR)"
	rm libft.a
	@echo "libft.a successfully removed"

re: fclean all
