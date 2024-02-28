
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define INT_MAX 2147483647
#define INT_MIN -2147483648

typedef struct node
{
    int value;
    int position;
    int final_rank;
    int cost;
    int capacity;
    struct node *cible;
    struct node *next;
} node;

typedef struct stack
{
    node *head;
} stack;

int ft_lstsize(stack *lst);
node *ft_lstlast(node *lst);
char **ft_split(const char *s, char c);
int ft_atoi(const char *str);

stack *create_stack(char **str, int capacity);
void update_position(stack *a);
void three_sort(stack *pile);

void move_to_b(stack *a, stack *b, int size_of_a);
void set_target_node(stack *a, stack *b);
void set_cost(stack *a, stack *b);
void big_sort(stack *a, stack *b);
void resort(stack *pile);

void pa(stack *a, stack *b);
void pb(stack *b, stack *a);
void sa(stack *a);
void sb(stack *b);
void ss(stack *a, stack *b);
void ra(stack *a);
void rb(stack *b);
void rr(stack *a, stack *b);
void rra(stack *a);
void rrb(stack *b);
void rrr(stack *a, stack *b);

void swap(stack *pile);
void push(stack *s1, stack *s2);
void rotate(stack *pile);
void reverse_rotate(stack *pile);
void set_final_rank(stack *pile);

void show(stack *a, stack *b, int clear);