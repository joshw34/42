SOURCES = main.c \
		parse.c \
		create_arrays.c \
		findname.c \
		print.c \

OBJECTS = $(SOURCES: .c=.o)

NAME = rush-02

all: $(SOURCES)
	@echo "Compiling source files"
	cc -Wall -Wextra -Werror $(SOURCES) -o $(NAME)
	@echo "rush-02 successfully compiled"

fclean: $(NAME)
	@echo "Removing rush-02 executable"
	rm rush-02
	@echo "rush-02 executable removed"

