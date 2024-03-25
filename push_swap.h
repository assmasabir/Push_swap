/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asabir <asabir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 13:14:47 by asabir            #+#    #+#             */
/*   Updated: 2024/03/25 02:49:36 by asabir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line/get_next_line.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define INT_MAX 2147483647
#define INT_MIN -2147483648

typedef struct node
{
	int			value;
	int			position;
	int			order;
	int			cost;
	struct node	*cible;
	struct node	*next;
}				t_node;

typedef struct stack
{
	t_node		*head;
}				t_stack;

int				ft_lstsize(t_stack *lst);
t_node			*ft_lstlast(t_node *lst);
char			**ft_split(const char *s, char c);
long			ft_atoi(const char *str);
void			ft_putstr_fd(char *s, int fd);
int				ft_isdigit(int c);
int				ft_strcmp(const char *s1, const char *s2);
char			*ft_strjoin(char *s1, char *s2);
void			*ft_calloc(size_t nmemb, size_t size);
size_t			ft_strlen(const char *str);

t_stack			*create_t_stack(char **str);
void			update_position(t_node **a);
t_stack			*initialize_b_t_stack(void);
void			three_sort(t_stack *pile);

void			move_to_b(t_stack *a, t_stack *b, int size_of_a);
void			set_target_t_node(t_stack *a, t_stack *b);
void			set_cost(t_stack *a, t_stack *b);
void			big_sort(t_stack *a, t_stack *b);
void			resort(t_stack *pile);

void			pa(t_stack *a, t_stack *b, int display);
void			pb(t_stack *b, t_stack *a, int display);
void			sa(t_stack *a, int display);
void			sb(t_stack *b, int display);
void			ss(t_stack *a, t_stack *b, int display);
void			ra(t_stack *a, int display);
void			rb(t_stack *b, int display);
void			rr(t_stack *a, t_stack *b, int display);
void			rra(t_stack *a, int display);
void			rrb(t_stack *b, int display);
void			rrr(t_stack *a, t_stack *b, int display);

void			swap(t_stack *pile);
void			push(t_stack *s1, t_stack *s2);
void			rotate(t_stack *pile);
void			reverse_rotate(t_stack *pile);
void			set_order(t_stack *pile);
int				less_median(int order, int size);
int				cost_sum(int cost_a, int cost_b);
t_node			*find_node_with_smallest_cost(t_stack *b);

void			show(t_stack *a, t_stack *b, int clear);
int				check_if_integer(long c);
int				check_duplicate(t_stack *pile, int nbr);
int				check_if_number(char *str);
void			free_and_exit(t_stack *a, int display);
void			resort(t_stack *pile);
char			*get_next_line(int fd);
void			update_stacks(t_stack *a, t_stack *b);
void			push_and_update(t_stack *a, t_stack *b);
char			**arg_join(int argc, char **argv);
int				check_if_stack_sorted(t_stack *a);