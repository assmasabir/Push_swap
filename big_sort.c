#include "push_swap.h"

int less_median(int final_rank, int size)
{
    int median;

    median = size / 2;

    if (final_rank <= median)
        return (1);
    else
        return (0);
}
int less_median_pos(int pos, int size)
{
    int median;

    median = size / 2;

    if (pos <= median)
        return (1);
    else
        return (0);
}

// ila kan ness f b kanhabso
void move_to_b(stack *a, stack *b, int size_of_a)
{
    int size_of_b;

    size_of_b = 0;
    int initial_size_of_a = size_of_a;
    while (size_of_a > 3 && size_of_b < size_of_a / 2)
    {
        size_of_b = ft_lstsize(b);
        // printf("value = %d, final rank %d, if less = %d\n", a->head->value, a->head->final_rank, less_median(a->head->final_rank, initial_size_of_a));
        if (!less_median(a->head->final_rank, initial_size_of_a))
        {
            pb(b, a);
            size_of_a--;
        }
        else
            ra(a);
    }
    while (size_of_a > 3)
    {
        pb(b, a);
        size_of_a--;
    }
    if (size_of_a == 3)
    {
        three_sort(a);
    }
    size_of_a = ft_lstsize(a);

    update_position(a);
    // printf("i am here \n");
    update_position(b);
}
node *node_with_smallest_value(stack *a)
{
    int var;
    node *temp;
    node *iterer;

    var = a->head->value;
    temp = a->head;
    iterer = a->head;
    while (iterer)
    {
        // printf("%d\n", iterer);
        if (var > iterer->value)
        {
            var = iterer->value;
            temp = iterer;
        }
        iterer = iterer->next;
    }
    return (temp);
}

void set_target_node(stack *a, stack *b)
{
    int var;

    node *tempa;
    node *tempb;
    tempb = b->head;
    while (tempb)
    {
        var = INT_MAX;
        tempa = a->head;
        while (tempa)
        { // negative value ??
            if (tempa->value > tempb->value && var > tempa->value - tempb->value)
            {
                var = tempa->value - tempb->value;
                tempb->cible = tempa;
            }
            tempa = tempa->next;
        }
        if (var == INT_MAX)
        {
            tempb->cible = node_with_smallest_value(a);
        }
        tempb = tempb->next;
    }
}
// set every stack apart
void set_cost(stack *a, stack *b)
{
    int size_of_a;
    int size_of_b;
    node *tempa;
    node *tempb;

    size_of_a = ft_lstsize(a);
    size_of_b = ft_lstsize(b);
    tempa = a->head;
    tempb = b->head;
    while (tempa)
    {
        // printf("%d\n", less_median(tempa->final_rank, size_of_a));
        if (less_median_pos(tempa->position, size_of_a))
            tempa->cost = tempa->position;
        else
            tempa->cost = -(size_of_a - tempa->position);
        tempa = tempa->next;
    }
    while (tempb)
    {
        if (less_median_pos(tempb->position, size_of_b))
            tempb->cost = tempb->position;
        else
            tempb->cost = -(size_of_b - tempb->position);
        tempb = tempb->next;
    }
}
int cost_sum(int cost_a, int cost_b)
{
    int sum;

    if (cost_a < 0)
        cost_a = -cost_a;
    if (cost_b < 0)
        cost_b = -cost_b;
    sum = cost_a + cost_b;
    return (sum);
}

int position_of_node_with_smallest_cost(stack *pile)
{
    int pos;
    int cost;
    node *temp;

    cost = cost_sum(pile->head->cost, pile->head->cible->cost);
    pos = 0;
    temp = pile->head;
    while (temp)
    {
        if (cost > cost_sum(temp->cost, temp->cible->cost))
        {
            cost = cost_sum(temp->cost, temp->cible->cost);
            pos = temp->position;
        }
        temp = temp->next;
    }
    return (pos);
}

void update_stacks(stack *a, stack *b)
{
    // hadi laaaaach
    //  if (a->head->value > a->head->next->value)
    //  {
    //      printf("heeeeeeeeere\n");
    //      ra(a);
    //  }
    update_position(a);

    update_position(b);
    set_final_rank(a);
    set_final_rank(b);
    set_target_node(a, b);
    set_cost(a, b);
}

void big_sort(stack *a, stack *b)
{
    node *temp;
    int cost_a;
    int cost_b;
    node *tempb;

    tempb = b->head;

    while (tempb)
    {

        temp = b->head;
        while (temp)
        {

            if (temp->position == position_of_node_with_smallest_cost(b))
                break;
            temp = temp->next;
        }

        cost_b = temp->cost;
        cost_a = temp->cible->cost;

        if (cost_a == cost_b && cost_a == 1)
        {
            ss(a, b);
            update_stacks(a, b);
        }

        else if (cost_a == cost_b && cost_a == 0)
        {
            tempb = temp->next;
            pa(a, b);
            // show(a,b,0);
            update_stacks(a, b);
            node *test;
            test = a->head;
            // while (test)
            // {
            //     printf("%d -> %d\n", test->value, test->cost);
            //     test = test->next;
            // }
        }
        else if (cost_a >= 0 && cost_b >= 0)
        {
            while (cost_a != 0 && cost_b != 0)
            {
                rr(a, b);
                update_stacks(a, b);
                cost_b = temp->cost;
                cost_a = temp->cible->cost;
            }
            if (cost_a == 0 && cost_b > 0)
            {
                while (cost_b != 0)
                {
                    rb(b);
                    update_stacks(a, b);
                    cost_b = temp->cost;
                    // c'est preferable de mettre a jour chaque stack a part
                }
            }
            if (cost_b == 0 && cost_a > 0)
            {

                while (cost_a != 0)
                {
                    ra(a);
                    update_stacks(a, b);

                    cost_a = temp->cible->cost;
                }
            }
            if (cost_a == 0 && cost_b == 0)
            {
                tempb = temp->next;
                pa(a, b);
                // show(a,b,0);
                update_stacks(a, b);
            }
        }
        else if (cost_a <= 0 && cost_b <= 0)
        {
            while (cost_a != 0 && cost_b != 0)
            {
                rrr(a, b);
                update_stacks(a, b);
                cost_b = temp->cost;
                cost_a = temp->cible->cost;
            }
            if (cost_a == 0 && cost_b < 0)
            {
                while (cost_b != 0)
                {
                    rrb(b);
                    update_stacks(a, b);
                    cost_b = temp->cost;
                }
            }
            if (cost_b == 0 && cost_a < 0)
            {
                while (cost_a != 0)
                {
                    rra(a);
                    update_stacks(a, b);
                    cost_a = temp->cible->cost;
                }
            }
            if (cost_a == 0 && cost_b == 0)
            {
                tempb = temp->next;
                pa(a, b);
                // show(a,b,0);
                update_stacks(a, b);
            }
        }
        else if (cost_a <= 0 && cost_b >= 0)
        {
            while (cost_a != 0)
            {
                rra(a);

                update_stacks(a, b);
                cost_a = temp->cible->cost;
            }
            if (cost_b > 0)
            {
                while (cost_b != 0)
                {
                    rb(b);
                    update_stacks(a, b);
                    cost_b = temp->cost;
                }
                if (cost_b == 0)
                {
                    tempb = temp->next;
                    pa(a, b);
                    // show(a,b,0);
                    update_stacks(a, b);
                }
            }
        }
        else if (cost_b <= 0 && cost_a >= 0)
        {
            while (cost_a != 0)
            {
                ra(a);
                update_stacks(a, b);
                cost_a = temp->cible->cost;
            }
            if (cost_b < 0)
            {
                while (cost_b != 0)
                {
                    rrb(b);
                    update_stacks(a, b);
                    cost_b = temp->cost;
                }
                if (cost_b == 0)
                {
                    tempb = temp->next;
                    pa(a, b);
                    // show(a,b,0);
                    update_stacks(a, b);
                }
            }
        }
    }
}
void resort(stack *pile)
{
    node *temp;
    int min;
    int min_final_rank;
    int size;

    size = ft_lstsize(pile);
    temp = pile->head;
    min = temp->value;
    min_final_rank = temp->final_rank;
    while (temp)
    {
        if (min > temp->value)
        {
            min = temp->value;
            min_final_rank = temp->final_rank;
            temp = temp->next;
        }
        else
            temp = temp->next;
    }

    if (!less_median(min_final_rank, size))
    {
        while (min != pile->head->value)
        {
            rra(pile);
        }
    }
    else
    {
        while (min != pile->head->value)
        {
            ra(pile);
        }
    }
}
