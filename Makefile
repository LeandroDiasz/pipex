# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ledias-d <ledias-d@student.42.rio>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/21 17:00:35 by ledias-d          #+#    #+#              #
#    Updated: 2024/11/26 18:54:43 by ledias-d         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
CC = cc
CFLAGS = -Wall -Wextra -Werror

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

MAKE_LIBFT = make -C $(LIBFT_DIR)

SRCS = pipex.c utils.c 
OBJS = $(SRCS:.c=.o)

TEST_SRC = $(SRCS)
TEST_EXEC = test

all: $(LIBFT) $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT)

$(LIBFT):
	$(MAKE_LIBFT)

testfiles:
	@echo "Creating test files..."
	@touch infile outfile
	@echo "ainda" > infile
	@echo "Jamal bieber" >> infile
	@echo "vai tomando" >> infile
	@echo "Test files 'infile' and 'outfile' created successfully."

clean:
	rm -f $(OBJS)
	$(MAKE_LIBFT) clean

fclean: clean
	rm -f $(NAME) $(TEST_EXEC)
	$(MAKE_LIBFT) fclean

re: fclean all

.PHONY: all clean fclean re test
