/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asabir <asabir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 13:18:56 by asabir            #+#    #+#             */
/*   Updated: 2024/03/03 19:33:28 by asabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

t_stack	*initialize_b_t_stack(void)
{
	t_stack	*b;

	b = malloc(sizeof(t_stack));
	b->head = NULL;
	return (b);
}

void	handle_two_numbers(t_stack *a, int size_of_a)
{
	if (size_of_a == 2 && a->head->value > a->head->next->value)
		sa(a);
}

void	sort_large_t_stack(t_stack *a, t_stack *b, int size_of_a)
{
	move_to_b(a, b, size_of_a);
	set_target_t_node(a, b);
	set_cost(a, b);
	big_sort(a, b);
	resort(a);
}

void	clean_up(t_stack *a, t_stack *b)
{
	free_and_exit(a, 0);
	if (b)
		free(b);
}

int	main(int argc, char **argv)
{
	char	**str;
	t_stack	*a;
	t_stack	*b;
	int		size_of_a;

	a = NULL;
	b = NULL;
	if (argc < 2)
		exit(EXIT_FAILURE);
	else if (argc == 2)
	{
		str = ft_split(argv[1], ' ');
		a = create_t_stack(str, argc - 1);
	}
	else
		a = create_t_stack(argv + 1, argc - 1);
	size_of_a = ft_lstsize(a);
	b = initialize_b_t_stack();
	update_position(&(a->head));
	handle_two_numbers(a, size_of_a);
	if (argc - 1 == 3)
		three_sort(a);
	else if (size_of_a > 3)
		sort_large_t_stack(a, b, size_of_a);
	clean_up(a, b);
}
