/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_cost.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojocho <hyojocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 19:58:15 by hyojocho          #+#    #+#             */
/*   Updated: 2023/03/15 20:49:32 by hyojocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static size_t	get_passing_cost(size_t index, size_t size)
{
	size_t	rb_count;
	size_t	rrb_count;

	rb_count = index;
	rrb_count = size - index;
	if (rb_count <= rrb_count)
		return (rb_count);
	else
		return (rrb_count);
}

int	is_biggest_num(t_stack *stack_a, int number)
{
	t_stack_node	*dummy;

	if (stack_a == NULL || stack_a->top == NULL)
		return (TRUE);
	dummy = stack_a->top;
	while (dummy)
	{
		if (dummy->data > number)
			return (FALSE);
		dummy = dummy->prev;
	}
	return (TRUE);
}

static size_t	get_sorting_cost(t_stack *stack_a, int number)
{
	size_t			cost;
	t_stack_node	*dummy;
	t_stack_node	*tmp;

	cost = 0;
	if (stack_a == NULL || stack_a->top == NULL)
		return (0);
	dummy = stack_a->top;
	if (is_biggest_num(stack_a, number) == TRUE)
		return (0);
	while (dummy && dummy->data < number)
	{
		cost++;
		tmp = stack_a->head;
		while (tmp != NULL && tmp->data > number)
		{
			cost++;
			tmp = tmp->next;
		}
		dummy = dummy->prev;
	}
	return (cost);
}

static void	get_cost(t_stack *stack_a, t_stack *stack_b, \
	t_stack_node *node, size_t index)
{
	size_t	cost;

	cost = 0;
	cost += get_passing_cost(index, stack_size(stack_b));
	cost += get_sorting_cost(stack_a, node->data);
	node->cost = cost;
}

size_t	get_min_cost_index(t_stack *stack_a, t_stack *stack_b)
{
	size_t			min_cost;
	size_t			index;
	size_t			cost;
	size_t			min_index;
	t_stack_node	*dummy;

	index = 0;
	if (stack_b == NULL || stack_b->top == NULL)
		return (0);
	dummy = stack_b->top;
	min_cost = INT_MAX;
	while (dummy)
	{
		get_cost(stack_a, stack_b, dummy, index);
		cost = dummy->cost;
		if (cost < min_cost)
		{
			min_cost = dummy->cost;
			min_index = index;
		}
		index++;
		dummy = dummy->prev;
	}
	return (min_index);
}
