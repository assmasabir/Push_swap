#include "push_swap.h"

#include <limits.h>

void set_final_rank(stack *pile)
{
    int size = ft_lstsize(pile);
    node *highest;

    highest = NULL;
    while (size)
    {
        int min = INT_MIN;
        node *current = pile->head;

        while (current != NULL)
        {
            if (current->value == INT_MIN)
                current->final_rank = 1;
            if (current->value > min && current->final_rank == -1)
            {
                min = current->value;
                highest = current;
                current = current->next;
            }
            else
            {
                current = current->next;
            }
        }
        if (highest)
        {
            highest->final_rank = size;
        }
        size--;
    }
}
