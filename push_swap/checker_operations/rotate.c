/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojocho <hyojocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 19:37:12 by hyojocho          #+#    #+#             */
/*   Updated: 2023/03/15 19:37:13 by hyojocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	rotate(t_stack *list)
{
	t_stack_node	*head;
	t_stack_node	*top;

	if (list == NULL || list->head == NULL || list->head->next == NULL)
		return ;
	head = list->head;
	top = list->top;
	top->next = head;
	head->prev = top;
	list->head = top;
	list->top = top->prev;
	list->top->next = NULL;
	list->head->prev = NULL;
}

void	ra(t_stack *stack_a)
{
	rotate(stack_a);
}

void	rb(t_stack *stack_b)
{
	rotate(stack_b);
}

void	rr(t_stack *stack_a, t_stack *stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
}
