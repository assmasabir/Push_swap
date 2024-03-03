NAME = push_swap
CC = cc
# CFLAGS = -Wall -Wextra -Werror
# CFLAGS += -fsanitize=address -g3 
OBJ_D = obj

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
    resort.c                \
    visualize.c

OBJS = $(addprefix $(OBJ_D)/,${SRC:.c=.o})

all : $(NAME)

$(OBJ_D)/%.o: %.c | ${OBJ_D}
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

${OBJ_D} :
	@mkdir ${OBJ_D}

clean:
	@rm -rf $(OBJ_D)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all fclean re clean
