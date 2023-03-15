/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyojocho <hyojocho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 19:37:16 by hyojocho          #+#    #+#             */
/*   Updated: 2023/03/15 19:37:18 by hyojocho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	reverse_rotate(t_stack *list)
{
	t_stack_node	*head;
	t_stack_node	*top;

	if (list == NULL || list->head == NULL || list->head->next == NULL)
		return ;
	head = list->head;
	top = list->top;
	top->next = head;
	head->prev = top;
	list->top = head;
	list->head = head->next;
	list->top->next = NULL;
	list->head->prev = NULL;
}

void	rra(t_stack *stack_a)
{
	reverse_rotate(stack_a);
}

void	rrb(t_stack *stack_b)
{
	reverse_rotate(stack_b);
}

void	rrr(t_stack *stack_a, t_stack *stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
}
