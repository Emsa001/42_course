# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: escura <escura@student.42wolfsburg.de>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/30 13:49:31 by escura            #+#    #+#              #
#    Updated: 2023/12/09 15:45:26 by escura           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

# Compiler and Flags
CC = gcc
# CFLAGS = -Wall -Wextra -Werror

# Source Files
SRC_DIR = src
INCLUDES_DIR = includes
SRC = $(wildcard $(SRC_DIR)/**/*.c) $(wildcard $(SRC_DIR)/*.c) $(wildcard $(INCLUDES_DIR)/lists/*.c)

# Object Directory
OBJ_DIR = obj

# Object Files
OBJ = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC))

# Libft
LIBFT_DIR = $(INCLUDES_DIR)/libft
LIBFT = $(LIBFT_DIR)/libft.a
LIBFT_MAKE = $(MAKE) -C $(LIBFT_DIR)

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	$(LIBFT_MAKE)

clean:
	$(LIBFT_MAKE) clean
	rm -rf $(OBJ_DIR)

fclean: clean
	$(LIBFT_MAKE) fclean
	rm -f $(NAME)

re: fclean all

t: 
	make
	clear
	./$(NAME) 7 6 2 1 3 9 8 5 4 0
	
.PHONY: all clean fclean re
