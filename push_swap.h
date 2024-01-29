#include "libft/libft.h"
#include <stdio.h>

typedef struct node{
    int value;
    int position;
    struct node* cible;
    struct node* next;
    struct node* previous;   
} node;

typedef struct stack {
    node *head;
} stack;