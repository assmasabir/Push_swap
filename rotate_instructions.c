/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_instructions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asabir <asabir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 14:07:28 by asabir            #+#    #+#             */
/*   Updated: 2024/02/29 14:13:11 by asabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack *pile)
{
	t_node	*to_rotate;
	t_node	*last;

	if (pile->head != NULL && pile->head->next != NULL)
	{
		to_rotate = pile->head;
		last = ft_lstlast(pile->head);
		pile->head = pile->head->next;
		last->next = to_rotate;
		to_rotate->next = NULL;
	}
}

void	ra(t_stack *a)
{
	rotate(a);
	write(1, "ra\n", 3);
}

void	rb(t_stack *b)
{
	rotate(b);
	write(1, "rb\n", 3);
}

void	rr(t_stack *a, t_stack *b)
{
	rotate(a);
	rotate(b);
	write(1, "rr\n", 3);
}
