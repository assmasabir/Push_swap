/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_instructions.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asabir <asabir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 13:58:32 by asabir            #+#    #+#             */
/*   Updated: 2024/03/08 17:44:20 by asabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate(t_stack *pile)
{
	t_node	*before_last;
	t_node	*to_rotate;

	if (pile->head != NULL && pile->head->next != NULL)
	{
		to_rotate = ft_lstlast(pile->head);
		before_last = pile->head;
		while (before_last->next)
		{
			if (before_last->next->next)
				before_last = before_last->next;
			else
				break ;
		}
		to_rotate->next = pile->head;
		pile->head = to_rotate;
		before_last->next = NULL;
	}
}

void	rra(t_stack *a, int display)
{
	reverse_rotate(a);
	if (display == 1)
		write(1, "rra\n", 4);
}

void	rrb(t_stack *b, int display)
{
	reverse_rotate(b);
	if (display == 1)
		write(1, "rrb\n", 4);
}

void	rrr(t_stack *a, t_stack *b, int display)
{
	reverse_rotate(a);
	reverse_rotate(b);
	if (display == 1)
		write(1, "rrr\n", 4);
}
