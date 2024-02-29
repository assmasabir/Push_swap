# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asabir <asabir@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/05 16:39:17 by asabir            #+#    #+#              #
#    Updated: 2024/02/29 17:24:00 by asabir           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
CFLAGS =-Wall -Wextra -Werror
CFLAGS += -fsanitize=address -g3 

SRC = \
    set_rank.c              \
    big_sort.c              \
    push_instructions.c     \
    swap_instructions.c     \
    reverse_rotate_instructions.c \
    rotate_instructions.c   \
    set_target.c            \
    set_costs.c             \
    move_nodes.c            \
    libft_functions2.c      \
    push_swap.c             \
    push_swap_utils.c       \
    three_sort.c            \
    libft_functions1.c      \
    errors.c                \
	resort.c				\
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