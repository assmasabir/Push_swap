#include "push_swap.h"

static node *create_node(int value, int capacity)
{
    node *pm;
    pm = (node *)malloc(sizeof(node));
    if (pm != NULL)
    {
        pm->value = value;
        pm->position = 0;
        pm->capacity = capacity;
        pm->final_rank = -1;
        pm->next = NULL;
    }
    return (pm);
}

stack *create_stack(char **str, int capacity)
{
    int i;
    int nbr;
    node *pm;
    stack *pile;
    node *temp;

    i = 0;

    pile = (stack *)malloc(sizeof(stack));
    if (!pile)
        exit(1);
    // function exit in xase of error
    pile->head = NULL;

    while (str[i] != NULL)
    {
        nbr = ft_atoi(str[i]);
        pm = create_node(nbr, capacity);

        temp = pile->head;
        if (temp == NULL)
        {
            pile->head = pm;
        }
        else
        {
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = pm;
        }
        i++;
    }
    set_final_rank(pile);

    return (pile);
}

// prqqqqqqqqqqqqqqqqqqqqqq
void update_position(stack *a)
{
    int i;
    node *temp;

    i = 0;

    if (!a->head)
        return;
    if (!(a->head->next))
    {
        a->head->position = 0;
        return;
    }
    temp = a->head;
    while (temp)
    {
        temp->position = i;

        temp = temp->next;
        i++;
    }
    // node *test = a->head;
    // while (test)
    // {
    //     printf("\n%d = %d\n", test->value, test->position);
    //     test = test->next;
    // }
}