/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asabir <asabir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 13:18:56 by asabir            #+#    #+#             */
/*   Updated: 2024/02/05 17:41:53 by asabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char**argv)
{   
    char **str;
    stack **a;
    stack **b;
    int size_of_a;
    
    a = NULL;
    b = NULL;
    if (argc == 2)
        {
        str = ft_split(argv[1], ' ');
        *a = create_stack(str);
        }
    *a = create_stack(argv+1);
    update_position(a);
    size_of_a = ft_lstsize((*a)->head);
    if(size_of_a == 2)
    {
        if((*a)->head->value > (*a)->head->next->value)
            sa(a);
    }
    if(size_of_a == 3)
        three_sort(a);
    else if(size_of_a > 3)
    {
        move_to_b(a, b, size_of_a);
        set_target_node(a,b);
        set_cost(a,b);
        big_sort(a, b);
    }
    
}



