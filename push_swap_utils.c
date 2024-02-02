#include "push_swap.h"

node *create_node(int value)
{
    node *pm;
    pm = (node *)malloc(sizeof(node));
    if(pm != NULL)
    {
        pm->value = value;
        pm->next = NULL;
        pm->previous = NULL;
    }
    return (pm);
}

stack *create_stack(char **str)
{
    int     i;
    int     nbr;
    node    *pm;
    stack   *pile;

    i = 0;
    while(str[i] != NULL)
    {
        nbr = ft_atoi(str[i]);
        if(check_duplicate(pile, nbr))
            i++;
        else 
        {
        pm = create_node(nbr);
        if (pm==NULL)
            break;
        pile->head->previous = pm;
        pm->next = pile->head;
        pile->head = pm;
        i++;
        }
        
    }
    return (pile);
}

int check_duplicate(stack *pile, int nbr)
{
    node *temp;

    temp = pile->head;
    while (temp != NULL)
    {
        if(temp->value == nbr)
            return (1);
        temp = temp->next;
    }
    return (0);
}
void update_position(stack **a)
{
    int i;
    
    i = 0;
    while((*a)->head)
    {
        (*a)->head->position = i;
        (*a)->head = (*a)->head->next;
        i++;
    }
}
