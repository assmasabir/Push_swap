#include "libft/libft.h"
#include <stdio.h>

# define INT_MAX 2147483647
# define INT_MIN -2147483648 

typedef struct node{
    int value;
    int position;
    int final_rank;
    int cible_pos;
    struct node* next;
    struct node* previous;   
} node;

typedef struct stack {
    node *head;
} stack;