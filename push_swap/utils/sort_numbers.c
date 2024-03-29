/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_numbers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojocho <hyojocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 18:00:37 by hyojocho          #+#    #+#             */
/*   Updated: 2023/03/15 18:00:43 by hyojocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	sort_three_numbers_b(t_stack *stack_b)
{
	int	pattern;

	pattern = pattern_three_numbers(stack_b);
	if (pattern == 6)
	{
		sb(stack_b);
		rrb(stack_b);
	}
	if (pattern == 5)
		rrb(stack_b);
	else if (pattern == 4)
		rb(stack_b);
	else if (pattern == 3)
		sb(stack_b);
	else if (pattern == 2)
	{
		rrb(stack_b);
		sb(stack_b);
	}
	else
		return ;
}

void	min_to_top(t_stack *stack_a)
{
	size_t	max_index;
	size_t	size;

	max_index = get_max_index(stack_a);
	size = stack_size(stack_a);
	if (stack_a == NULL || stack_a->head == NULL || stack_a->head->next == NULL)
		return ;
	while (is_biggest_num(stack_a, stack_a->head->data) == FALSE)
	{
		if (max_index > size / 2)
			rra(stack_a);
		else
			ra(stack_a);
	}
}

int	sort_b(t_stack *stack_b)
{
	if (stack_size(stack_b) <= 1 || is_stack_sorted_b(stack_b))
		return (COMPLETE);
	else if (stack_size(stack_b) == 2)
		sb(stack_b);
	else if (stack_size(stack_b) == 3)
		sort_three_numbers_b(stack_b);
	else
		return (CONTINUE);
	return (COMPLETE);
}

void	cheapest_to_top_b(t_stack *stack_b, size_t number, int flag)
{
	while (number)
	{
		if (flag == RB)
			rb(stack_b);
		else
			rrb(stack_b);
		number--;
	}
}
