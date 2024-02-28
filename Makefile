# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asabir <asabir@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/05 16:39:17 by asabir            #+#    #+#              #
#    Updated: 2024/02/27 20:44:43 by asabir           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
CFLAGS =-Wall -Wextra -Werror
CFLAGS += -fsanitize=address -g3 

SRC = \
	algo.c					\
	big_sort.c				\
	instructions.c			\
	moves.c					\
	push_swap.c				\
	push_swap_utils.c		\
	simple_sort.c			\
	libft_functions.c		\
	visualize.c

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
		$(CC) $(CFLAGS) $(OBJ) -o $(NAME) 
#-fsanitize=address

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all fclean re clean