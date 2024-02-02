#include "push_swap.h"

int get_max_rank(stack *pile)
{
    int max;
    max = pile->head->value;
    while (pile->head != NULL)
    {
        if (pile->head->value > max)
            max = pile->head->value;
        pile->head = pile->head->next;
    }
    return (max);
}

void three_sort(stack **pile)
{
   int max;

   max = get_max_rank(*pile);
   if((*pile)->head->final_rank == max)
   {
    if((*pile)->head->next->final_rank > (*pile)->head->next->next->final_rank)
    {
        ra(pile);
        sa(pile);
    }
   }
   if((*pile)->head->next->final_rank == max)
   {
    if((*pile)->head->final_rank > (*pile)->head->next->next->final_rank == max)
        rra(pile);
    else
    {
        sa(pile);
        ra(pile);
    }
   }
   if((*pile)->head->next->next->final_rank == max)
   {
    if((*pile)->head->final_rank > (*pile)->head->next->final_rank == max)
        sa(pile);
   }
}