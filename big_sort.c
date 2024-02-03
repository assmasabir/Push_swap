#include "push_swap.h"

int less_median(int final_rank, int size)
{
    int median;

    median = size/2;
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
node *node_with_smallest_value(stack *a)
{
    int var;
    node *temp;

    var = a->head->value;
    temp = a->head;
    while(a->head)
    {
        a->head = a->head->next;
        if(var < a->head->value)
        {
            var = a->head->value;
            temp = a->head;
        }
    }
    return(temp);
}

void set_target_node(stack **a, stack **b)
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
                (*b)->head->cible = (*a)->head;
            }
            (*a)->head = (*a)->head->next;
        }
        if(var == INT_MIN)
        {
            (*b)->head->cible = node_with_smallest_value(*a);
        }
        (*b)->head = (*b)->head->next;
    }
}
void set_cost(stack **a, stack **b)
{
    int size_of_a;
    int size_of_b;

    size_of_a = ft_lstsize(*a);
    size_of_a = ft_lstsize(*b);
    while((*a)->head)
    {
        if(less_median((*a)->head->final_rank, size_of_a))
            (*a)->head->cost = (*a)->head->position;
        else
            (*a)->head->cost = -(size_of_a - (*a)->head->position);
        (*a)->head = (*a)->head->next;
    }
       while((*b)->head)
    {
        if(less_median((*b)->head->final_rank, size_of_b))
            (*b)->head->cost = (*b)->head->position;
        else
            (*b)->head->cost = -(size_of_b - (*b)->head->position);
        (*b)->head = (*b)->head->next;
    }
}
int cost_sum(int cost_a, int cost_b)
{
    int sum;

    if(cost_a < 0)
        cost_a = -cost_a;
    if(cost_b < 0)
        cost_b = -cost_b;
    sum = cost_a + cost_b;
    return (sum);
}

int position_of_node_with_smallest_cost(stack *pile)
{
    int pos;
    int cost;

    cost = cost_sum(pile->head->cost, pile->head->cible->cost);
    pos = 0;
    while (pile->head)
    {
        pile->head = pile->head->next;
        if (cost > cost_sum(pile->head->cost, pile->head->cible->cost))
        {
            cost = cost_sum(pile->head->cost, pile->head->cible->cost);
            pos = pile->head->position;
        }
    }
    return(pos);
}
void big_sort(stack **a, stack **b)
{
    node *temp;
    int cost_a;`
    int cost_b;

    while((*b)->head)
    {
        if((*a)->head->position == position_of_node_with_smallest_cost(*b))
        {
            temp = (*a)->head;
            break;
        }
        (*b)->head = (*b)->head->next;
    }
    while()
    {
        cost_a = temp;
        cost_b = 
    }
}