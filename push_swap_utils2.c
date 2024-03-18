/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asabir <asabir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 22:12:04 by asabir            #+#    #+#             */
/*   Updated: 2024/03/18 02:55:36 by asabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	update_stacks(t_stack *a, t_stack *b)
{
	update_position(&(a->head));
	update_position(&(b->head));
	set_order(a);
	set_order(b);
	set_target_t_node(a, b);
	set_cost(a, b);
}

void	push_and_update(t_stack *a, t_stack *b)
{
	pa(a, b, 1);
	update_stacks(a, b);
}

int	is_empty(char *argv)
{
	int	i;

	i = 0;
	if (!argv[i])
		return (0);
	while (argv[i])
	{
		if (argv[i] != ' ')
			return (1);
		i++;
	}
	return (0);
}

char	**arg_join(int argc, char **argv)
{
	int		i;
	char	*to_join;
	char	**str;

	i = 1;
	to_join = ft_calloc(1, 1);
	if (to_join == NULL)
		return (NULL);
	if (argv[i] == NULL || argc <= 1)
		exit(EXIT_SUCCESS);
	while (argv[i])
	{
		if (!is_empty(argv[i]))
		{
			ft_putstr_fd("Error\n", 2);
			free(to_join);
			exit(EXIT_FAILURE);
		}
		to_join = ft_strjoin(to_join, " ");
		to_join = ft_strjoin(to_join, argv[i]);
		i++;
	}
	str = ft_split(to_join, ' ');
	free(to_join);
	return (str);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned int	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
	{
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
