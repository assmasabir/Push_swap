/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asabir <asabir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 13:18:56 by asabir            #+#    #+#             */
/*   Updated: 2024/02/21 02:17:14 by asabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
int main(int argc, char **argv)
{
    char **str;
    stack *a;
    stack *b;
    // stack *stacka;
    // stack *stackb;
    int size_of_a;

    // stacka = NULL;
    // stackb = NULL;

    // a = &stacka;
    // b = &stackb;

    // a->head = NULL;
    // b->head = NULL;
    int i = 0;
    if (argc < 2)
        exit(1);

    if (argc == 2)
    {

        str = ft_split(argv[1], ' ');
        for (int i = 0; i < 4; i++)
        {
            printf("str[%d] = %s \n", i, str[i]);
        }

        sleep(1);
        //? a = create_stack(str);
    }
    else
        a = create_stack(argv + 1, argc - 1);

    b = malloc(sizeof(stack));
    b->head = NULL;

    // printf("%p \n",a);
    // printf("%d ->%d\n\n\n\n", a->head->value, a->head->final_rank);
    // printf("%d->%d\n\n\n\n", a->head->next->value, a->head->next->final_rank);
    // printf("%d->%d\n\n\n\n", a->head->next->next->value, a->head->next->next->final_rank);
    update_position(a);

    // printf("%d\n\n\n\n", a->head->final_rank);
    size_of_a = ft_lstsize(a);

    // if (size_of_a == 2)
    // {
    //     if (a->head->value > a->head->next->value)
    //         sa(a);
    // }
    // printf("%d----\n", a->head->value);
    // show(a, b, 0);
    // pb(b, a);
    // show(a, b, 0);
    // printf("%d\n", a->head->value);
    // pb(b, a);
    // show(a, b, 0);
    // printf("%d\n", a->head->value);
    // pb(b, a);
    // printf("%d\n", a->head->value);
    // show(a, b, 0);

    // pa(a, b);
    // show(a, b, 0);
    // printf("%d\n", a->head->value);
    // printf("%d\n\n\n\n", a->head->value);
    show(a, b, 0);
    if (argc - 1 == 3)
        three_sort(a);
    //  printf("%d i am head", a->head->value);
    else if (size_of_a > 3)
    {
        move_to_b(a, b, size_of_a);
        // set_target_node(a, b);
        // set_cost(a, b);
        // big_sort(a, b);
    }
}
