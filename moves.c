#include "push_swap.h"

void swap(stack **pile)
{
    if ((*pile)->head != NULL && (*pile)->head->next != NULL)
    {
    node *first = (*pile)->head;
    node *second = first->next;
    first->next = second->next;
    first->previous = second;
    second->next = first;
    second->previous = NULL;
    (*pile)->head = second;
    }
}

void push(stack **s1, stack **s2)
{
    if((*s1)->head != NULL )
    {
        node *topush = (*s1)->head;
        node *previouss1= topush->next;
        // NULL
        if (previouss1)
            previouss1->previous = NULL;
        (*s1)->head = previouss1;
        if(!(*s2)->head)
        {
            (*s2)->head = topush;
            (*s2)->head->next = NULL;
            (*s2)->head->previous = NULL;
        }
        else
        {
            topush->next = (*s2)->head;
            (*s2)->head->previous = topush;
            (*s2)->head = topush;
        }
    }
}

void rotate(stack **pile)
{
    if((*pile)->head != NULL && (*pile)->head->next != NULL)
    {
        node *last = ft_lstlast(*pile);
        last->previous->next = NULL;
        (*pile)->head->previous = NULL;
        last->next = (*pile)->head;
        (*pile)->head = last;
    }
}

void reverse_rotate(stack **pile)
{
    if((*pile)->head != NULL && (*pile)->head->next != NULL)
    {
        node *last = ft_lstlast(*pile);
        (*pile)->head->next->previous = NULL;
        last->next = (*pile)->head;
        (*pile)->head->next = NULL;
        (*pile)->head->previous = last;
    }
}