/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asabir <asabir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 22:12:04 by asabir            #+#    #+#             */
/*   Updated: 2024/03/04 22:15:18 by asabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	update_stacks(t_stack *a, t_stack *b)
{
	update_position(&(a->head));
	update_position(&(b->head));
	set_final_rank(a);
	set_final_rank(b);
	set_target_t_node(a, b);
	set_cost(a, b);
}

void	push_and_update(t_stack *a, t_stack *b)
{
	pa(a, b);
	update_stacks(a, b);
}
