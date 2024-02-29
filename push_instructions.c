/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_instructions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asabir <asabir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 14:10:51 by asabir            #+#    #+#             */
/*   Updated: 2024/02/29 14:12:48 by asabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack *s1, t_stack *s2)
{
	t_node	*topush;

	if (s1->head != NULL)
	{
		topush = s1->head;
		s1->head = s1->head->next;
		if (!s2->head)
		{
			s2->head = topush;
			s2->head->next = NULL;
			return ;
		}
		else if (s2->head)
		{
			topush->next = s2->head;
			s2->head = topush;
		}
	}
}

void	pa(t_stack *a, t_stack *b)
{
	push(b, a);
	write(1, "pa\n", 3);
}

void	pb(t_stack *b, t_stack *a)
{
	push(a, b);
	write(1, "pb\n", 3);
}
