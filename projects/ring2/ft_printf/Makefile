NAME = libftprintf.a
SRC_DIR = ./src
OBJ_DIR = ./objs

SOURCES = ${SRC_DIR}/ft_custom.c ${SRC_DIR}/ft_funcs.c \
		  ${SRC_DIR}/ft_parse.c ${SRC_DIR}/ft_printf.c

OBJECTS = ${OBJ_DIR}/ft_custom.o ${OBJ_DIR}/ft_funcs.o \
		  ${OBJ_DIR}/ft_parse.o ${OBJ_DIR}/ft_printf.o

CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)
bonus: $(NAME)

$(NAME): $(OBJECTS)
	$(AR) -r $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_BONUS_DIR)/%.o: $(SRC_BONUS_DIR)/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)
	rm -rf $(OBJ_BONUS_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

t: test
n: norm
c: clean

test:
	make
	clear
	$(CC) -w $(SRC_DIR)/main.c -o ./my_program $(NAME) ../../../libraries/lib.a && ./my_program

norm:
	norminette $(SRC_DIR)/ft_*.c $(SRC_DIR)/ft_printf.h

.PHONY: all clean fclean bonus re