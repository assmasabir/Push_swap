#include "push_swap.h"

void swap(stack *pile)
{
    if (pile->head != NULL && pile->head->next != NULL)
    {
        node *first = pile->head;
        node *second = first->next;
        first->next = second->next;

        second->next = first;

        pile->head = second;
    }
}

void push(stack *s1, stack *s2)
{
    if (s1->head != NULL)
    {
        node *topush = s1->head;
        // node *previouss1 = topush->next;
        // NULL
        s1->head = s1->head->next;
        // if (previouss1)
        //     s1->head = previouss1;
        // else if (!previouss1)
        // {
        //     s1->head = NULL;
        // }
        if (!s2->head)
        {
            s2->head = topush;
            s2->head->next = NULL;
            return;
        }
        else if (s2->head)
        {
            topush->next = s2->head;
            s2->head = topush;
        }
    }
}

void rotate(stack *pile)
{
    if (pile->head != NULL && pile->head->next != NULL)
    {   node *to_rotate;
        node *last;

        to_rotate = pile->head;
        last = ft_lstlast(pile->head);
        pile->head = pile->head->next;
        last->next = to_rotate;
        to_rotate->next = NULL;
    }
}

void reverse_rotate(stack *pile)
{
    if (pile->head != NULL && pile->head->next != NULL)
    {
        node *to_rotate = ft_lstlast(pile->head);
        node *before_last;
        before_last = pile->head;
        while(before_last->next)
        {
            if(before_last->next->next)
                before_last = before_last->next;
            else
                break;
        }
        to_rotate->next = pile->head;
        pile->head = to_rotate;
        before_last->next == NULL;
    }
}