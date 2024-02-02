#include "push_swap.h"
int less_median(int final_rank, int sizeofa)
{
    int median;

    median = sizeofa/2;
    if(final_rank <  median)
        return(1);
    else
        return(0);
}
void move_to_b(stack **a, stack **b, int size_of_a)
{
   
    while(size_of_a > 3)
    {
        if(less_median((*a)->head->final_rank, size_of_a))
        {
            pa(a,b);
            size_of_a--;
        }
        else 
            ra(a);
    }
    while(size_of_a > 3)
    {
        pa(a,b);
        size_of_a--;
    }
    if(size_of_a == 3)
        three_sort(a);
    update_position(a);
    update_position(b);
}
int find_smallest_value(stack *a)
{
    int var;
    int position;

    var = a->head->value;
    position = a->head->position;
    while(a->head)
    {
        a->head = a->head->next;
        if(var < a->head->value)
        {
            var = a->head->value;
            position = a->head->position;
        }
    }
    return(position);
}
void set_target_position(stack **a, stack **b)
{
    int var;

    var = INT_MIN;
    while((*b)->head)
    {
        while ((*a)->head)
        {
            if((*a)->head->value > (*b)->head->value && var < (*a)->head->value - (*b)->head->value)
            {
                var = (*a)->head->value - (*b)->head->value;
                (*b)->head->cible_pos = (*a)->head->position;
            }
            (*a)->head = (*a)->head->next;
        }
        if(var == INT_MIN)
        {
            (*b)->head->cible_pos = find_smallest_value(*a);      
        }
        (*b)->head = (*b)->head->next;
    }
}
void set_cost(stack **b)
{
    
}
void big_sort(stack **a, stack **b)
{
    
}