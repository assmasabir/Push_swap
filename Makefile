NAME = push_swap
NAME_BON= checker
CC = cc
CFLAGS = -Wall -Wextra -Werror
CFLAGS += -fsanitize=address -g3 
OBJ_D = obj

SRC = \
    set_rank.c              \
    big_sort.c              \
    push_instructions.c     \
    swap_instructions.c     \
    big_sort_utils.c        \
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
    libft_functions3.c      \
    errors.c                \
    resort.c                \
    visualize.c

SRC2 =  \
    set_rank.c              \
    big_sort.c              \
    push_instructions.c     \
    swap_instructions.c     \
    reverse_rotate_instructions.c \
    rotate_instructions.c   \
    set_target.c            \
    big_sort_utils.c        \
    set_costs.c             \
    move_nodes.c            \
    libft_functions2.c      \
    checker.c               \
    push_swap_utils.c       \
    three_sort.c            \
    libft_functions1.c      \
    libft_functions3.c      \
    errors.c                \
    resort.c                \
    get_next_line/get_next_line.c         \
    get_next_line/get_next_line_utils.c   \
    visualize.c

OBJS = $(addprefix $(OBJ_D)/,${SRC:.c=.o})
OBJB = $(addprefix $(OBJ_D)/,$(SRC2:.c=.o))

all : $(NAME)

$(OBJ_D)/%.o: %.c | ${OBJ_D}
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

${OBJ_D} :
	@mkdir ${OBJ_D}

bonus : $(NAME_BON)

$(OBJ_D)/%.o: %.c | ${OBJ_D}
    ifeq (,$(findstring get_next_line/,$<))
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@
    endif

$(NAME_BON) : $(OBJB)
	@$(CC) $(CFLAGS) $(OBJB) -o $(NAME_BON)


clean:
	@rm -rf $(OBJ_D)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all fclean re clean bonus
