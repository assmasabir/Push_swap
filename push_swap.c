/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asabir <asabir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 13:18:56 by asabir            #+#    #+#             */
/*   Updated: 2024/02/01 17:06:13 by asabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char**argv)
{   
    char **str;
    stack **a;
    stack **b;
    int size;
    
    if (argc == 2)
        {
        str = ft_split(argv[1], " ");
        *a = create_stack(str);
        }
    *a = create_stack(argv+1);
    size = ft_lstsize(a);
    if(size == 2)
    {
        if((*a)->head->value > (*a)->head->next->value)
            sa(a);
    }
    if(size == 3)
        three_sort(a);
    else if(size > 3)
    {
        update_position(a);
        big_sort(a, b);
        
    }
    
}



