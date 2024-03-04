/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_nodes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asabir <asabir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 14:02:37 by asabir            #+#    #+#             */
/*   Updated: 2024/03/04 22:11:58 by asabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	less_median(int final_rank, int size)
{
	int	median;

	median = size / 2;
	if (final_rank <= median)
		return (1);
	else
		return (0);
}

void	update_positions(t_stack *a, t_stack *b)
{
	update_position(&(a->head));
	update_position(&(b->head));
}

void	move_to_b(t_stack *a, t_stack *b, int size_of_a)
{
	int	size_of_b;
	int	initial_size_of_a;

	size_of_b = 0;
	initial_size_of_a = size_of_a;
	while (size_of_a > 5 && size_of_b < initial_size_of_a / 2)
	{
		if (less_median(a->head->final_rank, initial_size_of_a))
		{
			pb(b, a);
			size_of_a--;
		}
		else
			ra(a);
		size_of_b = ft_lstsize(b);
	}
	while (size_of_a > 3)
	{
		pb(b, a);
		size_of_a--;
	}
	if (size_of_a == 3)
		three_sort(a);
	update_positions(a, b);
}
