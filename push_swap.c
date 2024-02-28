/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asabir <asabir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 13:18:56 by asabir            #+#    #+#             */
/*   Updated: 2024/02/28 22:22:04 by asabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int main(int argc, char **argv)
{

    char **str;
    stack *a;
    stack *b;
    int size_of_a;

    a = NULL;
    b = NULL;
    if (argc < 2)
        exit(1);

    else if (argc == 2)
    {

        str = ft_split(argv[1], ' ');
        a = create_stack(str, argc - 1);
    }
    else
        a = create_stack(argv + 1, argc - 1);

    b = malloc(sizeof(stack));
    b->head = NULL;
    size_of_a = ft_lstsize(a);
    update_position(a);

    if (size_of_a == 2)
    {
        if (a->head->value > a->head->next->value)
            sa(a);
    }
    if (argc - 1 == 3)
        three_sort(a);

    else if (size_of_a > 3)
    {
        move_to_b(a, b, size_of_a);
        set_target_node(a, b);
        set_cost(a, b);
        big_sort(a, b);
        resort(a);
    }
}
