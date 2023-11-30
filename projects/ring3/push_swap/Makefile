# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: escura <escura@student.42wolfsburg.de>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/30 13:49:31 by escura            #+#    #+#              #
#    Updated: 2023/11/30 13:55:23 by escura           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

# Compiler and Flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror

# Source Files
SRC_DIR = src
SRC = $(SRC_DIR)/main.c

# Object Files
OBJ_DIR = obj
OBJ = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC))

# Libft
LIBFT_DIR = includes/libft
LIBFT = $(LIBFT_DIR)/libft.a
LIBFT_MAKE = $(MAKE) -C $(LIBFT_DIR)

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
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

.PHONY: all clean fclean re
