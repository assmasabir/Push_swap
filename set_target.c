/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_target.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asabir <asabir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 12:31:57 by asabir            #+#    #+#             */
/*   Updated: 2024/03/03 19:11:32 by asabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*t_node_with_smallest_value(t_stack *a)
{
	int		var;
	t_node	*temp;
	t_node	*iterer;

	var = a->head->value;
	temp = a->head;
	iterer = a->head;
	while (iterer)
	{
		if (var > iterer->value)
		{
			var = iterer->value;
			temp = iterer;
		}
		iterer = iterer->next;
	}
	return (temp);
}

void	set_target_t_node(t_stack *a, t_stack *b)
{
	long		var;
	t_node	*tempa;
	t_node	*tempb;

	tempb = b->head;
	while (tempb)
	{
		var = INT_MAX;
		tempa = a->head;
		while (tempa)
		{
			if (tempa->value > tempb->value && var > (long)tempa->value
				- (long)tempb->value)
			{
				var = (long)tempa->value - (long)tempb->value;
				tempb->cible = tempa;
			}
			tempa = tempa->next;
		}
		if (var == INT_MAX)
			tempb->cible = t_node_with_smallest_value(a);
		tempb = tempb->next;
	}
}
