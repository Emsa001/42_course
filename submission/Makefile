NAME = hints.a
SOURCES = libft.c born2beroot.c

OBJECTS = $(SOURCES:.c=.o)

CC = cc

all: $(NAME)

$(NAME): $(OBJECTS)
	$(AR) -r $@ $?

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

t: test
c: fclean

test:
	make
	clear
	$(CC) main.c -o ./hints ${NAME} && ./hints

.PHONY: all clean fclean re