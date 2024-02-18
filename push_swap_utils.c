#include "push_swap.h"

static node *create_node(int value, int capacity)
{
    node *pm;
    pm = (node *)malloc(sizeof(node));
    if(pm != NULL)
    {
        pm->value = value;
        pm->position = 0;
        pm->capacity = capacity;
        pm->next = NULL; 
    }
    return (pm);
}

static int check_duplicate(stack *pile, int nbr)
{
    node *temp;

    if(pile == NULL)
        return (0);
    temp = pile->head;
    while (temp != NULL)
    {
        if(temp->value == nbr)
            return (1);
        temp = temp->next;
    }
    return (0);
}

stack *create_stack(char **str, int capacity)
{
    int     i;
    int     nbr;
    node    *pm;
    stack   *pile;
    node    *temp;

    i = 0;

    pile = (stack *)malloc(sizeof(stack));
    if (!pile)
        exit(1);
    pile->head = NULL;
        // function exit in case of error (free)
    while(str[i] != NULL)
    {
        nbr = ft_atoi(str[i]);
        // if(check_duplicate(pile, nbr))
        //     i++;
        // else 
        // {
        pm = create_node(nbr, capacity);
        temp = pile->head;
        pm->next = temp;
        pile->head = pm;
        i++;
    }

    return (pile);
}


//prqqqqqqqqqqqqqqqqqqqqqq
void update_position(stack *a)
{
    int i;
    node *temp;
    
    
    i=0;
    if(!a)
        return;
    temp = a->head;
    // size = ft_lstsize(a);
    while(temp)
    {
        temp->position = i++;
        // printf("%d pos == %d\n", temp->value, temp->position);
        temp = temp->next;
    }
}
