/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_instructions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asabir <asabir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 14:07:34 by asabir            #+#    #+#             */
/*   Updated: 2024/03/08 17:42:45 by asabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack *pile)
{
	t_node	*first;
	t_node	*second;

	if (pile->head != NULL && pile->head->next != NULL)
	{
		first = pile->head;
		second = first->next;
		first->next = second->next;
		second->next = first;
		pile->head = second;
	}
}

void	sa(t_stack *a, int display)
{
	swap(a);
	if (display == 1)
		write(1, "sa\n", 3);
}

void	sb(t_stack *b, int display)
{
	swap(b);
	if (display == 1)
		write(1, "sb\n", 3);
}

void	ss(t_stack *a, t_stack *b, int display)
{
	swap(a);
	swap(b);
	if (display == 1)
		write(1, "ss\n", 3);
}
