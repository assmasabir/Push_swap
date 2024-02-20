#include "push_swap.h"
static int get_max_rank(stack *pile)
{

    int max = pile->head->final_rank;
    node *current = pile->head->next;

    while (current != NULL)
    {
        if (current->final_rank > max)
            max = current->final_rank;
        current = current->next;
    }
    return (max);
}

void three_sort(stack *pile)
{
   int max;

   max = get_max_rank(pile);
   
   if(pile->head->final_rank == max)
   {
    ra(pile);
   }
   else if(pile->head->next->final_rank == max)
   {
    rra(pile);
   }

   printf("%d i am head", pile->head->value);
    if(pile->head->final_rank > pile->head->next->final_rank)
    {
     sa(pile);
    }
}