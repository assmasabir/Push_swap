/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asabir <asabir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 13:18:56 by asabir            #+#    #+#             */
/*   Updated: 2024/03/25 03:33:48 by asabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	handle_two_numbers(t_stack *a, int size_of_a)
{
	if (size_of_a == 2 && a->head->value > a->head->next->value)
		sa(a, 1);
}

void	sort_large_t_stack(t_stack *a, t_stack *b, int size_of_a)
{
	move_to_b(a, b, size_of_a);
	set_target_t_node(a, b);
	set_cost(a, b);
	big_sort(a, b);
	resort(a);
}

void	clean_up(t_stack *a, t_stack *b, char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
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
	str = arg_join(argc, argv);
	a = create_t_stack(str);
	size_of_a = ft_lstsize(a);
	b = initialize_b_t_stack();
	if (check_if_stack_sorted(a))
		clean_up(a, b, str);
	update_position(&(a->head));
	handle_two_numbers(a, size_of_a);
	if (size_of_a == 3)
		three_sort(a);
	else if (size_of_a > 3)
		sort_large_t_stack(a, b, size_of_a);
	clean_up(a, b, str);
}
