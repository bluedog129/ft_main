/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojocho <hyojocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 19:37:21 by hyojocho          #+#    #+#             */
/*   Updated: 2023/03/15 19:37:22 by hyojocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	push_to(t_stack *from, t_stack *to)
{
	int	data;

	if (from->top)
	{
		data = pop(from);
		push(to, data);
	}
}

void	pa(t_stack *stack_a, t_stack *stack_b)
{
	push_to(stack_b, stack_a);
}

void	pb(t_stack *stack_a, t_stack *stack_b)
{
	push_to(stack_a, stack_b);
}
